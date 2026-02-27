#pragma once

#include "HookEx.hpp"
#include "Regs.hpp"
#include <malloc.h>

class HookEx;
class HookExManager
{
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