#include "HookEx/HookExManager.hpp"

using Callback = void (*)(Regs &, u32 *, HookEx *);

static bool mMemMapped;
static constexpr size_t mMaxHookCount = 256;
static constexpr size_t mMemSize      = 0x1000;
static u32 mMapMem[mMemSize]          = {};
static HookExManager *mSlotPool       = (HookExManager *)0x01E83000;

HookExManager *HookExManager::AllocMitmModeSlot(HookEx *hook)
{
    if (SlotPoolMapping())
        for (size_t i = 0; i < mMaxHookCount; ++i)
            if (!(mSlotPool + i)->mCallback && (hook->mMode & HookEx::MITM_MODE)) {
                HookExManager *slot = mSlotPool + i;
                slot->mInstr        = 0xE51FF004;    // ldr pc, [pc, #-4]
                slot->mCallback     = hook->mCallbackAddress;
                return slot;
            }
    return nullptr;
}

HookExManager *HookExManager::AllocSubWrapModeSlot(HookEx *hook)
{
    if (SlotPoolMapping())
        for (size_t i = 0; i < mMaxHookCount; ++i) {
            if (!(mSlotPool + i)->mCallback) {
                std::vector<u32> InstrLine;
                bool before = hook->mBeforeCallbackAddress, after = hook->mAfterCallbackAddress;
                u32 code = 8;

                if (before)
                    code += 8;

                if (after)
                    code += 8;

                if (before) {
                    InstrLine.push_back(0xE59FE000 | code);    // ldr lr, [pc, #18] -> mBeforeCallbackAddress
                    InstrLine.push_back(0xE12FFF3E);    // blx lr
                    code -= 4;
                }

                InstrLine.push_back(0xE59FE000 | code);    // ldr lr, [pc, #code] -> mCallbackAddress (Original)
                InstrLine.push_back(0xE12FFF3E);    // blx lr
                code -= 4;

                if (after) {
                    InstrLine.push_back(0xE59FE000 | code);    // ldr lr, [pc, #code] -> mAfterCallbackAddress
                    InstrLine.push_back(0xE12FFF3E);    // blx lr
                    code -= 4;
                }

                InstrLine.push_back(0xE59FE000 | code);    // ldr lr, [pc, #code] -> mReturnAddress
                InstrLine.push_back(0xE12FFF1E);    // bx lr

                if (before)
                    InstrLine.push_back(hook->mBeforeCallbackAddress);

                InstrLine.push_back(hook->mCallbackAddress);

                if (after)
                    InstrLine.push_back(hook->mAfterCallbackAddress);

                InstrLine.push_back(hook->mReturnAddress);

                u32 *mem;

                if (mem = (u32 *)malloc(InstrLine.size() * 4)) {
                    size_t instrIndex = 0;
                    for (auto instr : InstrLine) {
                        mem[instrIndex++] = instr;
                    }
                }

                HookExManager *slot = mSlotPool + i;
                slot->mInstr        = 0xE51FF004;    // ldr pc, [pc, #-4]
                slot->mCallback     = (u32)mem;
                return slot;
            }
        }
    return nullptr;
}

HookExManager *HookExManager::AllocRoutineModeSlot(HookEx *hook)
{
    if (SlotPoolMapping())
        for (size_t i = 0; i < mMaxHookCount; ++i) {
            if (mSlotPool)
                if (!(mSlotPool + i)->mCallback) {
                    std::vector<u32> InstrLine;
                    constexpr u32 NOP = 0xE320F000;
                    bool after        = (hook->mMode & HookEx::EXECUTE_ORIGINAL_INSTR_AFTER);
                    bool before       = (hook->mMode & HookEx::EXECUTE_ORIGINAL_INSTR_BEFORE);
                    bool mitm         = (hook->mMode & HookEx::MITM_MODE);

                    InstrLine.push_back(before ? hook->mOriginalInstr : NOP);
                    InstrLine.push_back(0xE92D5FFF);    // stmfd sp! {r0-r12, lr} (push {r0-r12, lr})
                    InstrLine.push_back(0xED2D0A20);    // vstmdb sp! {s0-s31}    (vpush {s0-s31})
                    InstrLine.push_back(0xE1A0000D);    // mov r0, sp             (param1 = regs)
                    InstrLine.push_back(0xE28D10B8);    // add r1, sp, #184       (param2 = sp (sizeof(Regs) == 184))
                    InstrLine.push_back(0xE59F2018);    // ldr r2, [pc, #0x18]   -> hook
                    InstrLine.push_back(0xE59FE018);    // ldr lr, [pc, #0x18]   -> mCallbackAddress
                    InstrLine.push_back(0xE12FFF3E);    // blx lr
                    InstrLine.push_back(0xECBD0A20);    // vldmia sp! {s0-s31}    (vpop {s0-s31})
                    InstrLine.push_back(0xE8BD5FFF);    // ldmfd sp! {r0-r12, lr} (pop {r0-r12, lr})
                    InstrLine.push_back(after ? hook->mOriginalInstr : NOP);
                    InstrLine.push_back(mitm ? NOP : 0xE59FE008);    // ldr lr, [pc, #8]   -> mReturnAddress
                    InstrLine.push_back(0xE12FFF1E);
                    InstrLine.push_back((u32)hook);
                    InstrLine.push_back((u32)hook->mCallbackAddress);
                    InstrLine.push_back(hook->mReturnAddress);

                    u32 *mem = nullptr;

                    if (mem = (u32 *)malloc(InstrLine.size() * 4)) {
                        size_t instrIndex = 0;
                        for (auto instr : InstrLine) {
                            mem[instrIndex++] = instr;
                        }
                    }

                    HookExManager *slot = mSlotPool + i;
                    slot->mInstr        = 0xE51FF004;    // ldr pc, [pc, #-4]
                    slot->mCallback     = (u32)mem;
                    return slot;
                }
        }
    return nullptr;
}

void HookExManager::FreeSlot(HookEx *hook)
{
    mInstr = 0;
    free((void *)mCallback);
    mCallback = 0;
}

bool HookExManager::SlotPoolMapping(void)
{
    if (!mMemMapped)
        mMemMapped = svcMapProcessMemoryEx(CUR_PROCESS_HANDLE, (u32)mSlotPool, CUR_PROCESS_HANDLE, (u32)mMapMem, mMemSize) == 0;

    return mMemMapped;
}
