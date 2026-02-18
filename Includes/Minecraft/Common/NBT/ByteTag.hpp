#pragma once

#include "Minecraft/Common/NBT/Tag.hpp"

namespace MC3DSPluginFramework
{
    class ByteTag : public Tag
    {
    public:
        ByteTag(char value) :
            mValue(value)
        {
            *(u32 *)this = 0x9CD824;
        }

        void *operator new(size_t s) { return gstd::malloc(s); }

        char mValue;
    };
}    // namespace MC3DSPluginFramework