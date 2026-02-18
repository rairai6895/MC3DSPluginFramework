#pragma once

#include "Minecraft/Common/NBT/Tag.hpp"

namespace MC3DSPluginFramework
{
    class StringTag : public Tag
    {
    public:
        StringTag(gstd::string str) :
            mString(str)
        {
            *(u32 *)this = 0x9D7AAC;
        }

        void *operator new(size_t s) { return gstd::malloc(s); }

        gstd::string mString;
    };
}    // namespace MC3DSPluginFramework