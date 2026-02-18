#include "HookEx/HookEx.hpp"

HookEx::HookEx() :
    mTargetAddress(0),
    mCallbackAddress(0),
    mBeforeCallbackAddress(0),
    mAfterCallbackAddress(0),
    mReturnAddress(0),
    mOriginalInstr(0),
    mMode(0),
    mSlot(nullptr),
    mIsEnabled(false),
    mIsNormal(false) {
}

HookEx::~HookEx() {
    if (mIsEnabled)
        Disable();
}

bool HookEx::InitMitm(u32 targetAddress, u32 callbackAddress) {
    if (!mIsEnabled) {
        mTargetAddress         = targetAddress;
        mOriginalInstr         = *(u32 *)targetAddress;
        mBeforeCallbackAddress = 0;
        mCallbackAddress       = callbackAddress;
        mAfterCallbackAddress  = 0;
        mReturnAddress         = targetAddress + 4;
        mMode                  = MITM_MODE;
        mIsNormal              = true;
        return true;
    }
    return false;
}

bool HookEx::InitSubWrap(u32 targetAddress, u32 beforeCallbackAddress, u32 afterCallbackAddress) {
    if (!mIsEnabled) {
        mTargetAddress         = targetAddress;
        mOriginalInstr         = *(u32 *)targetAddress;
        mBeforeCallbackAddress = beforeCallbackAddress;
        mCallbackAddress       = DecodeARMBranch(targetAddress);
        mAfterCallbackAddress  = afterCallbackAddress;
        mReturnAddress         = targetAddress + 4;
        mMode                  = WRAP_SUB;
        mIsNormal              = true;
        return true;
    }
    return false;
}

bool HookEx::InitRoutine(u32 targetAddress, Routine callbackAddress, u32 routineMode) {
    if (!mIsEnabled) {
        mTargetAddress         = targetAddress;
        mOriginalInstr         = *(u32 *)targetAddress;
        mBeforeCallbackAddress = 0;
        mCallbackAddress       = (u32)callbackAddress;
        mAfterCallbackAddress  = 0;
        mReturnAddress         = targetAddress + 4;
        mMode                  = ROUTINE | routineMode;
        mIsNormal              = true;
        return true;
    }
    return false;
}

void HookEx::Enable(void) {
    if (!mIsEnabled) {
        mOriginalInstr = *(u32 *)mTargetAddress;

        if (mMode & MITM_MODE) {
            if (mSlot = HookExManager::AllocMitmModeSlot(this)) {
                SetBranch(mTargetAddress, (u32)mSlot);
                mIsEnabled = true;
                ClearCache();
            }
            return;
        }

        if (mMode & WRAP_SUB) {
            if (mSlot = HookExManager::AllocSubWrapModeSlot(this)) {
                SetBranch(mTargetAddress, (u32)mSlot);
                mIsEnabled = true;
                ClearCache();
            }
            return;
        }

        if (mMode & ROUTINE) {
            if (mSlot = HookExManager::AllocRoutineModeSlot(this)) {
                SetBranch(mTargetAddress, (u32)mSlot);
                mIsEnabled = true;
                ClearCache();
            }
            return;
        }
    }
}

void HookEx::Disable(void) {
    if (mIsEnabled) {
        *(u32 *)mTargetAddress = mOriginalInstr;
        mSlot->FreeSlot(this);
        mSlot      = nullptr;
        mIsEnabled = false;
        ClearCache();
    }
}

void HookEx::SetArgs(void *args) {
    mArgs = args;
}

HookEx::Context HookEx::GetContext(void) {
    Context ctx;
    ctx.targetAddress = mTargetAddress;
    ctx.args          = mArgs;
    return ctx;
}

bool HookEx::IsEnabled(void) {
    return mIsEnabled;
}

u32 HookEx::CheckAddress(u32 address) {
    return address >= 0x100000 ? address : 0;
}

void HookEx::ClearCache(void) {
    svcInvalidateEntireInstructionCache();
    svcFlushProcessDataCache(CUR_PROCESS_HANDLE, mTargetAddress, 4);
}

u32 HookEx::DecodeARMBranch(u32 from) {
    s32 code = (*(u32 *)from & 0x00FFFFFF) << 2;
    if (code & 0x00800000)
        code |= 0xFF000000;

    return from + 8 + code;
}

void HookEx::SetBranch(u32 from, u32 to) {
    s32 code     = (s32)(to - (from + 8));
    code         = (code >> 2) & 0x00FFFFFF;
    *(u32 *)from = 0xEA000000 | code;
}

void HookEx::SetBranchLink(u32 from, u32 to) {
    s32 code     = (s32)(to - (from + 8));
    code         = (code >> 2) & 0x00FFFFFF;
    *(u32 *)from = 0xEB000000 | code;
}
