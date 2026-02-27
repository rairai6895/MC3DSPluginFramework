#pragma once

#include "Minecraft/Helper/GameStructs.hpp"
#include "Minecraft/gstd/gstd.hpp"

namespace MC3DSPluginFramework
{
    // "C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\src\\common\\client\\gui\\gui\\Font.cpp"
    class Font
    {
    public:
        void draw(float x, float y, gstd::string str, const FColor &color, u32 unknown1, u32 unknown2, u32 unknown3, u32 unknown4)
        {
            reinterpret_cast<void (*)(Font *, float, float, gstd::string, const FColor &, u32, u32, u32, u32)>(0x55DA20)(this, x, y, str, color, unknown1, unknown2, unknown3, unknown4);
        }

    private:
    };
}    // namespace MC3DSPluginFramework