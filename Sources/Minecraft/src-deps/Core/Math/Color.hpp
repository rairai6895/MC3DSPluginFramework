#pragma once

#include "Minecraft/Common/Logger.hpp"

namespace MC3DSPluginFramework
{
    // "C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\src-deps\\Core\\Math\\Color.cpp"
    class Color
    {
    public:
        float r, g, b, a;

        static inline Color &WHITE  = *(Color *)0xB2E4B0;
        static inline Color &BLACK  = *(Color *)0xB2E4E0;
        static inline Color &YELLOW = *(Color *)0xB2E520;

    public:
        constexpr void
            init(float r, float g, float b, float a)
        {
            this->r = r;
            this->g = g;
            this->b = b;
            this->a = a;
        }

        constexpr Color()
        {
            init(0, 0, 0, 0);
        }

        // FUN_0x8AF3B4
        constexpr Color(float r, float g, float b, float a = 1.f)
        {
            init(r, g, b, a);
        }

        constexpr bool isNormalized() const
        {
            return ((r <= 1) && (r >= 0) && (g <= 1) && (g >= 0) && (b <= 1) && (b >= 0) && (a <= 1) && (a >= 0));
        }

#ifdef LOGGER_ON
        // FUN_0x72018C
        int toARGB() const
        {
            if (!isNormalized())
                LOG("This color uses more than 8 bit per channel, clamp it first", isNormalized(), 0);

            return (int)(b * 255) | ((int)(g * 255) << 8) | ((int)(r * 255) << 16) | ((int)(a * 255) << 24);
        }

        // FUN_0x720034
        int toABGR() const
        {
            if (!isNormalized())
                LOG("This color uses more than 8 bit per channel, clamp it first", isNormalized(), 0);

            return (int)(r * 255) | ((int)(g * 255) << 8) | ((int)(b * 255) << 16) | ((int)(a * 255) << 24);
        }
#else
        constexpr int toARGB() const
        {
            return (int)(b * 255) | ((int)(g * 255) << 8) | ((int)(r * 255) << 16) | ((int)(a * 255) << 24);
        }

        constexpr int toABGR() const
        {
            return (int)(r * 255) | ((int)(g * 255) << 8) | ((int)(b * 255) << 16) | ((int)(a * 255) << 24);
        }
#endif

    private:
    };
}    // namespace MC3DSPluginFramework