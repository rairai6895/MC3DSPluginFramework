#include "AstHook.hpp"
#include "AstHookManager.hpp"
#include "Disassembly.hpp"

namespace Asterium
{
    AstHook::AstHook() :
        mTargetAddress(0),
        mCallbackAddress(0),
        mBeforeCallbackAddress(0),
        mAfterCallbackAddress(0),
        mReturnAddress(0),
        mOriginalInstr(0),
        mMode(0),
        mSlot(nullptr),
        mEnabled(false) {}

    AstHook::~AstHook()
    {
        if (mEnabled)
            disable();
    }

    bool AstHook::initMitm(u32 targetAddress, u32 callbackAddress)
    {
        if (mEnabled || !checkAddress(targetAddress) || !callbackAddress)
            return false;

        mTargetAddress         = targetAddress;
        mBeforeCallbackAddress = 0;
        mCallbackAddress       = callbackAddress;
        mAfterCallbackAddress  = 0;
        mReturnAddress         = targetAddress + 4;
        mMode                  = HookMode::MITM;

        return true;
    }

    bool AstHook::initSubWrap(u32 targetAddress, u32 beforeCallbackAddress, u32 afterCallbackAddress)
    {
        if (mEnabled || !checkAddress(targetAddress) || (!beforeCallbackAddress && !afterCallbackAddress))
            return false;

        u32 instr = *(u32 *)targetAddress;

        if (!Disassembly::isBranch(instr))
            return false;

        mTargetAddress         = targetAddress;
        mBeforeCallbackAddress = beforeCallbackAddress;
        mCallbackAddress       = Disassembly::decodeARMBranch(targetAddress);
        mAfterCallbackAddress  = afterCallbackAddress;
        mReturnAddress         = targetAddress + 4;
        mMode                  = HookMode::WRAP_SUB;

        return true;
    }

    bool AstHook::initRoutine(u32 targetAddress, Routine callbackAddress, u32 addmode)
    {
        if (mEnabled || !checkAddress(targetAddress) || !callbackAddress)
            return false;

        mTargetAddress         = targetAddress;
        mBeforeCallbackAddress = 0;
        mCallbackAddress       = reinterpret_cast<u32>(callbackAddress);
        mAfterCallbackAddress  = 0;
        mReturnAddress         = targetAddress + 4;
        mMode                  = HookMode::ROUTINE | addmode;

        return true;
    }

    bool AstHook::isEnabled() const
    {
        return mEnabled;
    }

    void AstHook::enable()
    {
        if (mEnabled || mMode == 0 /* 未初期化チェック */)
            return;

        mOriginalInstr = *(u32 *)mTargetAddress;

        if (mMode == HookMode::MITM)
            mSlot = AstHookManager::allocMitmModeSlot(this);
        else if (mMode == HookMode::WRAP_SUB)
            mSlot = AstHookManager::allocSubWrapModeSlot(this);
        else if (mMode & HookMode::ROUTINE)
            mSlot = AstHookManager::allocRoutineModeSlot(this);

        if (!mSlot)
            return;

        Disassembly::setBranch(mTargetAddress, (u32)mSlot);
        clearCache();
        mEnabled = true;
    }

    void AstHook::disable()
    {
        if (!mEnabled)
            return;

        *(u32 *)mTargetAddress = mOriginalInstr;
        mSlot->freeSlot();
        mSlot    = nullptr;
        mEnabled = false;
        clearCache();
    }

    void AstHook::clearCache() const
    {
        svcInvalidateEntireInstructionCache();
        svcFlushProcessDataCache(CUR_PROCESS_HANDLE, mTargetAddress, 4);
    }
}    // namespace Asterium