#pragma once

#include "Minecraft/gstd/gstd.hpp"

namespace MC3DSPluginFramework::Util
{
    // "C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\src\\common\\util\\StringUtils.cpp"

    // FUN_0x12A814
    inline u32 hashCode(const char *str)
    {
        u32 hash = 0;
        while (*str) {
            signed char c = *str++;    // ゲーム内では符号付き

            if (c >= 'A' && c <= 'Z')
                c = gstd::tolower(c);

            hash = (c + hash) * 0x401;
            hash ^= hash >> 6;
        }
        return (hash * 9 ^ hash * 9 >> 11) * 32769;
    }

    NAKED inline gstd::string format(const char *fmt, ...)
    {
        asm volatile("ldr pc, =0x581E84 \n");
    }

    inline bool stringContains(gstd::string str, char c)
    {
        return reinterpret_cast<bool (*)(gstd::string, char)>(0x5818B8)(str, c);
    }

}    // namespace MC3DSPluginFramework::Util