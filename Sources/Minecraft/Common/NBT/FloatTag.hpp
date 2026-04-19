#pragma once

#include "Minecraft/Common/NBT/Tag.hpp"

namespace MC3DSPluginFramework
{
    class FloatTag : public Tag
    {
        USE_GAME_ALLOCATOR
    public:
        FloatTag(float value) :
            mValue(value)
        {
            *(u32 *)this = 0x9D0468;
        }

        float mValue;
    };
}    // namespace MC3DSPluginFramework