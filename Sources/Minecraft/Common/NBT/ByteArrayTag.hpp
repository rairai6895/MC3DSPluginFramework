#pragma once

#include "Minecraft/Common/NBT/Tag.hpp"

namespace MC3DSPluginFramework
{
    class ByteArrayTag : public Tag
    {
        USE_GAME_ALLOCATOR
    public:
        ByteArrayTag(std::pair<size_t, gstd::string> array) :
            mArray(array)
        {
            *(u32 *)this = 0x99F6EC;
        }

        std::pair<size_t, gstd::string> mArray;
    };
}    // namespace MC3DSPluginFramework