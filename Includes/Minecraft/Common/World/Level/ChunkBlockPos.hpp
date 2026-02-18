#pragma once

#include "Minecraft/Common/World/Level/BlockPos.hpp"
#include "Minecraft/Helper/Structs.hpp"
#include <types.h>

namespace MC3DSPluginFramework
{
    // "C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\project\\3DS\\..\\..\\src\\common\\world/level/ChunkBlockPos.h"
    class ChunkBlockPos
    {
    public:
        // FUN_0x206DD8
        explicit ChunkBlockPos(const BlockPos &pos)
        {
            x = pos.x & 0xF;
            z = pos.z & 0xF;
            y = pos.y;
        }

        bool isInChunk2D(void) { return (x < 16) && (z < 16); }

        char index2D(void) const
        {
            return reinterpret_cast<char (*)(const ChunkBlockPos *)>(0x6BCD7C)(this);
        }

        u8 x, z;
        u16 y;
    };
}    // namespace MC3DSPluginFramework