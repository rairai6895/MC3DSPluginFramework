#include "HookExManager.hpp"

using Callback = void (*)(Regs &, u32 *, HookEx *);

static bool MAPED;
static constexpr size_t MAX_SLOT    = 256;
static constexpr size_t MEMORY_SIZE = 0x1000;
static u32 SLOT_MEMORY[MEMORY_SIZE];
static HookExManager *SLOT_POOL = (HookExManager *)0x01E83000;

HookExManager *HookExManager::AllocSlot(HookEx *hook) {
    if (!MAPED)
        MAPED = svcMapProcessMemoryEx(CUR_PROCESS_HANDLE, (u32)SLOT_POOL, CUR_PROCESS_HANDLE, (u32)SLOT_MEMORY, MEMORY_SIZE) == 0;

    if (MAPED)
        for (size_t i = 0; i < MAX_SLOT; ++i) {
            if (!(SLOT_POOL + i)->m_wrapCallback.instrMemory) {
                HookEx::Context ctx = hook->GetContext();

                std::vector<u32> InstrLine{};
                u32 *mem = nullptr;
                if (ctx.mode & HookEx::Mode::USE_LR_TO_RETURN || ctx.mode & HookEx::Mode::MITM_MODE) {
                    if (ctx.mode & HookEx::Mode::EXECUTE_ORIGINAL_INSTR_BEFORE)
                        InstrLine.push_back(ctx.original_Instr);

                    if (ctx.mode & HookEx::Mode::EXECUTE_OVERRIDE_INSTR_BEFORE)
                        for (auto overrideInstr : *ctx.override_Instr_Before)
                            InstrLine.push_back(overrideInstr);

                    InstrLine.push_back(0xE92D5FFF);    // stmfd sp! {r0-r12, lr} | push {r0-r12, lr}
                    InstrLine.push_back(0xED2D0A20);    // vstmdb sp! {s0-s31}    | vpush {s0-s31}
                    InstrLine.push_back(0xE1A0000D);    // mov r0, sp             | param1 = regs
                    InstrLine.push_back(0xE28D10B8);    // add r1, sp, #184     | param2 = sp    sizeof(Regs) == 184

                    u32 code = (0x10 + (ctx.mode & HookEx::Mode::EXECUTE_OVERRIDE_INSTR_AFTER ? (*ctx.override_Instr_After).size() * 4 : 0) + (ctx.mode & HookEx::Mode::EXECUTE_ORIGINAL_INSTR_AFTER ? 4 : 0));

                    InstrLine.push_back(0xE59F2000 | code);    // ldr r2, [pc, #code]  | param3 = hook
                    InstrLine.push_back(0xE59FE000 | code);    // ldr lr, [pc, #code]
                    InstrLine.push_back(0xE12FFF3E);           // blx lr                 | bl ctx.callback
                    InstrLine.push_back(0xECBD0A20);           // vldmia sp! {s0-s31}    | vpop {s0-s31}
                    InstrLine.push_back(0xE8BD5FFF);           // ldmfd sp! {r0-r12, lr} | pop {r0-r12, lr}

                    if (ctx.mode & HookEx::Mode::EXECUTE_OVERRIDE_INSTR_AFTER)
                        for (auto overrideInstr : *ctx.override_Instr_After)
                            InstrLine.push_back(overrideInstr);

                    if (ctx.mode & HookEx::Mode::EXECUTE_ORIGINAL_INSTR_AFTER)
                        InstrLine.push_back(ctx.original_Instr);

                    InstrLine.push_back(0xE12FFF1E);    // bx lr
                    InstrLine.push_back((u32)hook);
                    InstrLine.push_back((u32)ctx.callback);

                    if (mem = (u32 *)malloc(InstrLine.size() * 4)) {
                        size_t i = 0;
                        for (auto instr : InstrLine) {
                            mem[i++] = instr;
                        }
                    }

                    HookExManager *slot  = SLOT_POOL + i;
                    slot->m_instr        = 0xE51FF004;    // ldr pc, [pc, #-4]
                    slot->m_wrapCallback = WrapCallback(mem);
                    return slot;
                }
            }
        }
    return nullptr;
}

void HookExManager::FreeSlot(void) {
    free(m_wrapCallback.instrMemory);
    m_wrapCallback.instrMemory = nullptr;
}
