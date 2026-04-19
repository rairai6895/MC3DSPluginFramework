#pragma once

#include "Minecraft/Common/NBT/Tag.hpp"

namespace MC3DSPluginFramework
{
    class ByteTag : public Tag
    {
        USE_GAME_ALLOCATOR
    public:
        ByteTag(char value) :
            mValue(value)
        {
            *(u32 *)this = 0x9CD824;
        }

        char mValue;
    };
}    // namespace MC3DSPluginFramework