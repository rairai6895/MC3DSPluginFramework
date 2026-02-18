#pragma once

#include "Minecraft/Common/World/Level/Level.hpp"

namespace MC3DSPluginFramework
{
    class Button
    {
    public:
        void _initIcons(u32 level)
        {
            reinterpret_cast<void (*)(Button *, u32)>(0x5D82D0)(this, level);
        }

    private:
    };
}    // namespace MC3DSPluginFramework