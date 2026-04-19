#pragma once

#include "Minecraft/Common/World/Level/ChunkBlockPos.hpp"

namespace MC3DSPluginFramework
{
    // "C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\project\\3DS\\..\\..\\src\\common\\world/level/SubChunkBlockPos.h"
    class SubChunkBlockPos
    {
    public:
        u8 x, y, z;

    public:
        explicit SubChunkBlockPos(const ChunkBlockPos &pos)
        {
            x = pos.x;
            y = pos.y % 16;
            z = pos.z;
        }

        bool isInChunk()
        {
            return (x < 16) && (y < 16) && (z < 16);
        }

        // FUN_0x6E3D2C
        u16 index()
        {
            return (u16)z * 16 + (u16)x * 0x100 + (u16)y;
        }
    };
}    // namespace MC3DSPluginFramework