#pragma once

#include <types.h>

namespace Asterium
{
    class AstHook;

    class AstHookManager
    {
    public:
        static AstHookManager *allocMitmModeSlot(AstHook *hook);
        static AstHookManager *allocSubWrapModeSlot(AstHook *hook);
        static AstHookManager *allocRoutineModeSlot(AstHook *hook);
        void freeSlot();
        static bool mapping();

    private:
        static constexpr u32 NOP = 0xE320F000;

        u32 mInstr    = 0;
        u32 mCallback = 0;
    };
}    // namespace Asterium