#pragma once

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

        static void *alloc(size_t size, Type type, size_t align, u32 unk2)
        {
            // 0x1010CA | 1
            // 0x2FEEB0 -> 0x11494C
            // 0x2FF4EC -> 0x2FEEB0
            // 0x2FE9F0 -> 0x2FF4EC
            return reinterpret_cast<void *(*)(size_t, Type, size_t, u32)>(0x11494C)(size, type, align, unk2);
        }

    private:
    };
}    // namespace MC3DSPluginFramework