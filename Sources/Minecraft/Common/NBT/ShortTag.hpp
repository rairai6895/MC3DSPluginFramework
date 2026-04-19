#pragma once

#include "Minecraft/Common/NBT/Tag.hpp"

namespace MC3DSPluginFramework
{
    class ShortTag : public Tag
    {
        USE_GAME_ALLOCATOR
    public:
        ShortTag(short value) :
            mValue(value)
        {
            *(u32 *)this = 0x9D1864;
        }

        short mValue;
    };
}    // namespace MC3DSPluginFramework