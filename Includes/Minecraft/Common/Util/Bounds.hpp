#pragma once

#include "Minecraft/Common/World/Level/BlockPos.hpp"

namespace MC3DSPluginFramework
{
    // "C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\project\\3DS\\..\\..\\src\\common\\util/Bounds.h"
    class Bounds
    {
    public:
        Bounds(const BlockPos &minBlock, const BlockPos &maxBlock, u32 unknown1, u32 unknown2)
        {
            reinterpret_cast<Bounds *(*)(Bounds *, const BlockPos &, const BlockPos &, u32, u32)>(0x5E5D54)(this, minBlock, maxBlock, unknown1, unknown2);
        }

    private:
        u32 mUnk1;
        u32 mUnk2;
        u32 mUnk3;
        u32 mUnk4;
        u32 mUnk5;
        u32 mUnk6;
        u32 mUnk7;
        u32 mUnk8;
        u32 mUnk9;
        u32 mUnk10;
        u32 mUnk11;
        u32 mUnk12;
    };
}    // namespace MC3DSPluginFramework