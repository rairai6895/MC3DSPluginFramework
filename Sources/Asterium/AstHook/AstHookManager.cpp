#include "AstHookManager.hpp"
#include "AstHook.hpp"
#include "Disassembly.hpp"
#include "Regs.hpp"
#include <malloc.h>

namespace Asterium
{
    using Callback = void (*)(Regs &, u32 *, AstHook *);

    static bool mMemMapped;
    static constexpr size_t mMaxHookCount = 256;
    static AstHookManager *mSlotPool      = (AstHookManager *)0x01E83000;

    AstHookManager *AstHookManager::allocMitmModeSlot(AstHook *hook)
    {
        if (!mapping())
            return nullptr;

        for (int i = 0; i < mMaxHookCount; ++i) {
            AstHookManager *slot = mSlotPool + i;

            if (slot->mCallback)
                continue;

            slot->mInstr    = 0xE51FF004;    // ldr pc, [pc, #-4]
            slot->mCallback = hook->mCallbackAddress;
            return slot;
        }

        return nullptr;
    }

    AstHookManager *AstHookManager::allocSubWrapModeSlot(AstHook *hook)
    {
        if (!mapping())
            return nullptr;

        for (int i = 0; i < mMaxHookCount; ++i) {
            AstHookManager *slot = mSlotPool + i;

            if (slot->mCallback)
                continue;

            bool before    = hook->mBeforeCallbackAddress;
            bool after     = hook->mAfterCallbackAddress;
            u32 *InstrLine = (u32 *)malloc(4 * 12);

            InstrLine[0]  = (before ? 0xE59FE018 : NOP);    // ldr lr, [pc, #18] -> mBeforeCallbackAddress
            InstrLine[1]  = (before ? 0xE12FFF3E : NOP);    // blx lr
            InstrLine[2]  = (0xE59FE014);    // ldr lr, [pc, #code] -> mCallbackAddress (Original)
            InstrLine[3]  = (0xE12FFF3E);    // blx lr
            InstrLine[4]  = (after ? 0xE59FE010 : NOP);    // ldr lr, [pc, #code] -> mAfterCallbackAddress
            InstrLine[5]  = (after ? 0xE12FFF3E : NOP);    // blx lr
            InstrLine[6]  = (0xE59FE00C);    // ldr lr, [pc, #code] -> mReturnAddress
            InstrLine[7]  = (0xE12FFF1E);    // bx lr
            InstrLine[8]  = (hook->mBeforeCallbackAddress);
            InstrLine[9]  = (hook->mCallbackAddress);
            InstrLine[10] = (hook->mAfterCallbackAddress);
            InstrLine[11] = (hook->mReturnAddress);

            slot->mInstr    = 0xE51FF004;    // ldr pc, [pc, #-4]
            slot->mCallback = (u32)InstrLine;
            return slot;
        }

        return nullptr;
    }

    AstHookManager *AstHookManager::allocRoutineModeSlot(AstHook *hook)
    {
        if (!mapping())
            return nullptr;

        for (int i = 0; i < mMaxHookCount; ++i) {
            AstHookManager *slot = mSlotPool + i;

            if (slot->mCallback)
                continue;

            u32 *InstrLine  = (u32 *)malloc(4 * 16);
            bool after      = (hook->mMode & HookMode::EXECUTE_ORIGINAL_INSTR_AFTER);
            bool before     = (hook->mMode & HookMode::EXECUTE_ORIGINAL_INSTR_BEFORE);
            bool mitm       = (hook->mMode & HookMode::MITM);
            bool trampoline = (hook->mMode & HookMode::TRAMPOLINE);

            // いつか対応させる
            bool isPcRelative = Disassembly::isPcRelativeInstr(hook->mOriginalInstr);
            InstrLine[0]      = ((before && !isPcRelative) ? hook->mOriginalInstr : NOP);

            InstrLine[1] = (0xE92D5FFF);    // stmfd sp! {r0-r12, lr} (push {r0-r12, lr})
            InstrLine[2] = (0xED2D0A20);    // vstmdb sp! {s0-s31}    (vpush {s0-s31})
            InstrLine[3] = (0xE1A0000D);    // mov r0, sp             (param1 = regs)
            InstrLine[4] = (0xE28D10B8);    // add r1, sp, #184       (param2 = sp (sizeof(Regs) == 184))
            InstrLine[5] = (0xE59F2018);    // ldr r2, [pc, #0x18]   -> hook
            InstrLine[6] = (0xE59FE018);    // ldr lr, [pc, #0x18]   -> mCallbackAddress
            InstrLine[7] = (0xE12FFF3E);    // blx lr
            InstrLine[8] = (0xECBD0A20);    // vldmia sp! {s0-s31}    (vpop {s0-s31})
            InstrLine[9] = (0xE8BD5FFF);    // ldmfd sp! {r0-r12, lr} (pop {r0-r12, lr})

            InstrLine[10] = ((after && !isPcRelative) ? hook->mOriginalInstr : NOP);

            // mitmなら復元したlrで戻る
            if (mitm)
                InstrLine[11] = (NOP);
            // trampolineならlrを上書きせず、そのまま元の処理に戻る
            else if (trampoline)
                InstrLine[11] = (0xE59FF008);    // ldr pc, [pc, #8]   -> mReturnAddress
            // lrを上書きして戻る
            else
                InstrLine[11] = (0xE59FE008);    // ldr lr, [pc, #8]   -> mReturnAddress

            InstrLine[12] = (0xE12FFF1E);
            InstrLine[13] = ((u32)hook);
            InstrLine[14] = ((u32)hook->mCallbackAddress);
            InstrLine[15] = (hook->mReturnAddress);

            slot->mInstr    = 0xE51FF004;    // ldr pc, [pc, #-4]
            slot->mCallback = (u32)InstrLine;
            return slot;
        }

        return nullptr;
    }

    void AstHookManager::freeSlot()
    {
        mInstr = 0;
        free((void *)mCallback);
        mCallback = 0;
    }

    bool AstHookManager::mapping()
    {
        static void *mem = malloc(0x1000);

        if (!mMemMapped)
            mMemMapped = svcMapProcessMemoryEx(CUR_PROCESS_HANDLE, (u32)mSlotPool, CUR_PROCESS_HANDLE, (u32)mem, 0x1000) == 0;

        return mMemMapped;
    }
}    // namespace Asterium