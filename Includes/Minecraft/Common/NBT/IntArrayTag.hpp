#pragma once

#include "Minecraft/Common/NBT/Tag.hpp"

namespace MC3DSPluginFramework
{
    class IntArrayTag : public Tag
    {
    public:
        IntArrayTag(gstd::string array) :
            mSize(array.size()), mArray(array)
        {
            *(u32 *)this = 0x99BE48;
        }

        void *operator new(size_t s) { return gstd::malloc(s); }

        size_t mSize;
        gstd::string mArray;
    };
}    // namespace MC3DSPluginFramework