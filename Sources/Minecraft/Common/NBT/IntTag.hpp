#pragma once

#include "Minecraft/Common/NBT/Tag.hpp"

namespace MC3DSPluginFramework
{
    class IntTag : public Tag
    {
        USE_GAME_ALLOCATOR
    public:
        IntTag(int value) :
            mValue(value)
        {
            *(u32 *)this = 0x9CB9F0;
        }

        int mValue;
    };
}    // namespace MC3DSPluginFramework