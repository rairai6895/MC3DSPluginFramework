#pragma once

#include "Minecraft/Common/NBT/Tag.hpp"

namespace MC3DSPluginFramework
{
    class FloatTag : public Tag
    {
    public:
        FloatTag(float value) :
            mValue(value)
        {
            *(u32 *)this = 0x9D0468;
        }

        void *operator new(size_t s) { return gstd::malloc(s); }

        float mValue;
    };
}    // namespace MC3DSPluginFramework