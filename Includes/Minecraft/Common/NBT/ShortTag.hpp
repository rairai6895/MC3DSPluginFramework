#pragma once

#include "Minecraft/Common/NBT/Tag.hpp"

namespace MC3DSPluginFramework
{
    class ShortTag : public Tag
    {
    public:
        ShortTag(short value) :
            mValue(value)
        {
            *(u32 *)this = 0x9D1864;
        }

        void *operator new(size_t s) { return gstd::malloc(s); }

        short mValue;
    };
}    // namespace MC3DSPluginFramework