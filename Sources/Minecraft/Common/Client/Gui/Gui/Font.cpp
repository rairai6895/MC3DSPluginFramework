#include "Font.hpp"

namespace MC3DSPluginFramework
{
    void Font::draw(float x, float y, gstd::string str, const Color &color, u32 unknown1, u32 unknown2, u32 unknown3, u32 unknown4)
    {
        reinterpret_cast<void (*)(Font *, float, float, gstd::string, const Color &, u32, u32, u32, u32)>(0x55DA20)(this, x, y, str, color, unknown1, unknown2, unknown3, unknown4);
    }

    void Font::drawWithShadow(float x, float y, float shadowXyOffset, gstd::string str, const Color &color, bool unknown1, u32 unknown2)
    {
        reinterpret_cast<void (*)(Font *, float, float, float, gstd::string, const Color &, bool, u32)>(0x55BB84)(this, x, y, shadowXyOffset, str, color, unknown1, unknown2);
    }

    int Font::getTextWidth(gstd::string str, bool unknown1, float unknown2)
    {
        return reinterpret_cast<int (*)(Font *, gstd::string, bool, float)>(0x71AD28)(this, str, unknown1, unknown2);
    }

    int Font::getTextHeight(gstd::string str, int unknown1, int unknown2)
    {
        return reinterpret_cast<int (*)(Font *, gstd::string, int, int)>(0x55BEEC)(this, str, unknown1, unknown2);
    }
}