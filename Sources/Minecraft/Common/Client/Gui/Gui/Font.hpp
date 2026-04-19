#pragma once

#include "Minecraft/Common/Platform/AppPlatformListener.hpp"
#include "Minecraft/gstd/gstd.hpp"
#include "Minecraft/src-deps/Core/Math/Color.hpp"

namespace MC3DSPluginFramework
{
    // "C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\src\\common\\client\\gui\\gui\\Font.cpp"
    class Font : public AppPlatformListener
    {
        USE_GAME_ALLOCATOR
    public:
        void draw(float x, float y, gstd::string str, const Color &color, u32 unknown1, u32 unknown2, u32 unknown3, u32 unknown4);
        void drawWithShadow(float x, float y, float shadowXyOffset, gstd::string str, const Color &color, bool unknown1, u32 unknown2);
        int  getTextWidth(gstd::string str, bool unknown1, float unknown2);
        int  getTextHeight(gstd::string str, int unknown1, int unknown2);

    private:
    };
}    // namespace MC3DSPluginFramework