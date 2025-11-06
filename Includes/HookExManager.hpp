#ifndef HOOKEXMANAGER_HPP
#define HOOKEXMANAGER_HPP

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
    static HookExManager *AllocSlot(HookEx *hook);
    void FreeSlot(void);

  private:
    struct WrapCallback {
        u32 *instrMemory = nullptr;

        WrapCallback(u32 *mem) :
            instrMemory(mem) {}
    };

    u32 m_instr;
    WrapCallback m_wrapCallback;
};

#endif