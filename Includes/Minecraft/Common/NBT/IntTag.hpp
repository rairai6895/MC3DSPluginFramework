#pragma once

#include "Minecraft/Common/NBT/Tag.hpp"

namespace MC3DSPluginFramework
{
    class IntTag : public Tag
    {
    public:
        IntTag(int value) :
            mValue(value)
        {
            *(u32 *)this = 0x9CB9F0;
        }

        void *operator new(size_t s) { return gstd::malloc(s); }

        int mValue;
    };
}    // namespace MC3DSPluginFramework