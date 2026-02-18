#pragma once

#include "HookEx.hpp"
#include <malloc.h>
#include <types.h>

class HookEx;
struct Regs {
    float s0, s1, s2, s3, s4, s5, s6, s7, s8, s9, s10, s11, s12, s13, s14, s15, s16, s17, s18, s19, s20, s21, s22, s23, s24, s25, s26, s27, s28, s29, s30, s31;
    u32 r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12, lr;
};
class HookExManager {
  public:
    static HookExManager *AllocMitmModeSlot(HookEx *hook);
    static HookExManager *AllocSubWrapModeSlot(HookEx *hook);
    static HookExManager *AllocRoutineModeSlot(HookEx *hook);
    void FreeSlot(HookEx *hook);
    static bool SlotPoolMapping(void);

  private:
    u32 mInstr    = 0;
    u32 mCallback = 0;
};