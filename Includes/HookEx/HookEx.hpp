#pragma once

#include "HookExManager.hpp"
#include <3ds.h>
#include <csvc.h>
#include <types.h>
#include <vector>

struct Regs;
class HookExManager;
class HookEx {
    using Routine = void (*)(Regs &, u32 *, HookEx *);

  public:
    friend HookExManager;

    enum Mode {
        MITM_MODE = 1 << 0,
        WRAP_SUB  = 1 << 1,
        ROUTINE   = 1 << 2,

        EXECUTE_ORIGINAL_INSTR_BEFORE = 1 << 3,
        EXECUTE_ORIGINAL_INSTR_AFTER  = 1 << 4,
    };

    struct Context {
        u32 targetAddress;
        u32 originalInstr;
        void *args;
    };

    HookEx();
    ~HookEx();

    bool InitMitm(u32 targetAddress, u32 callbackAddress);
    bool InitSubWrap(u32 targetAddress, u32 beforeCallbackAddress, u32 afterCallbackAddress);
    bool InitRoutine(u32 targetAddress, Routine callbackAddress, u32 routineMode = 0);

    bool IsEnabled(void);
    void Enable(void);
    void Disable(void);

    void SetArgs(void *args);
    Context GetContext(void);

    static u32 DecodeARMBranch(u32 from);
    static void SetBranch(u32 from, u32 to);
    static void SetBranchLink(u32 from, u32 to);

  private:
    static u32 CheckAddress(u32 address);
    void ClearCache(void);

    u32 mTargetAddress;
    u32 mCallbackAddress;
    u32 mBeforeCallbackAddress;
    u32 mAfterCallbackAddress;
    u32 mReturnAddress;
    u32 mOriginalInstr;
    u32 mMode;
    void *mArgs = nullptr;
    HookExManager *mSlot;
    bool mIsEnabled;
    bool mIsNormal;
};