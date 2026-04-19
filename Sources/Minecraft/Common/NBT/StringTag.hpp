#pragma once

#include "Minecraft/Common/NBT/Tag.hpp"

namespace MC3DSPluginFramework
{
    class StringTag : public Tag
    {
        USE_GAME_ALLOCATOR
    public:
        StringTag(gstd::string str) :
            mString(str)
        {
            *(u32 *)this = 0x9D7AAC;
        }

        gstd::string mString;
    };
}    // namespace MC3DSPluginFramework