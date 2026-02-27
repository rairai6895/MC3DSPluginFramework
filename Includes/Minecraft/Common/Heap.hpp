#pragma once

#include "HookEx/HookEx.hpp"
#include "Minecraft/gctr/gctr_synchronization.hpp"
#include <CTRPluginFramework/System/Process.hpp>
#include <types.h>

namespace MC3DSPluginFramework
{
    class Heap
    {
    public:
        enum class Type {
            CTR,
            Default,
            Unknown,
        };

        static void *alloc(size_t size, Type type, u32 unk1, u32 unk2)
        {
            // 0x1010CA | 1
            // 0x2FEEB0 -> 0x11494C
            // 0x2FF4EC -> 0x2FEEB0
            // 0x2FE9F0 -> 0x2FF4EC

            return reinterpret_cast<void *(*)(size_t, Type, u32, u32)>(0x11494C)(size, type, unk1, unk2);
        }

    private:
        };
}    // namespace MC3DSPluginFramework