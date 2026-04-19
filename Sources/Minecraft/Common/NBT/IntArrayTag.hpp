#pragma once

#include "Minecraft/Common/NBT/Tag.hpp"

namespace MC3DSPluginFramework
{
    class IntArrayTag : public Tag
    {
        USE_GAME_ALLOCATOR
    public:
        IntArrayTag(std::pair<size_t, gstd::string> array) :
            mArray(array)
        {
            *(u32 *)this = 0x99BE48;
        }

        std::pair<size_t, gstd::string> mArray;
    };
}    // namespace MC3DSPluginFramework