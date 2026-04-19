#pragma once

#include "Minecraft/Common/NBT/Tag.hpp"

namespace MC3DSPluginFramework
{
    class DoubleTag : public Tag
    {
        USE_GAME_ALLOCATOR
    public:
        DoubleTag(double value) :
            mValue(value) { *(u32 *)this = 0x9D3D58; }

        double mValue;
    };
}    // namespace MC3DSPluginFramework