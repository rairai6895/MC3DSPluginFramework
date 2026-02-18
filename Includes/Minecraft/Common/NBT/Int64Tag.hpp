#pragma once

#include "Minecraft/Common/NBT/Tag.hpp"

namespace MC3DSPluginFramework
{
    class Int64Tag : public Tag
    {
    public:
        Int64Tag(long long value) :
            mValue(value)
        {
            *(u32 *)this = 0x9D0BF8;
        }

        void *operator new(size_t s) { return gstd::malloc(s); }

        long long mValue;
    };
}    // namespace MC3DSPluginFramework