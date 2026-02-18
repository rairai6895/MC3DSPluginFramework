#pragma once

#include "Minecraft/Common/NBT/Tag.hpp"

namespace MC3DSPluginFramework
{
    class DoubleTag : public Tag
    {
    public:
        DoubleTag(double value) :
            mValue(value) { *(u32 *)this = 0x9D3D58; }

        void *operator new(size_t s) { return gstd::malloc(s); }

        double mValue;
    };
}    // namespace MC3DSPluginFramework