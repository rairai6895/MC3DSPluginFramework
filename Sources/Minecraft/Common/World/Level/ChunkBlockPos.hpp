#pragma once

#include "BlockPos.hpp"

namespace MC3DSPluginFramework
{
    // "C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\project\\3DS\\..\\..\\src\\common\\world/level/ChunkBlockPos.h"
    class ChunkBlockPos
    {
    public:
        u8  x, z;
        u16 y;

    public:
        explicit ChunkBlockPos(const BlockPos &pos);
        bool isInChunk2D() const;
        char index2D() const;
    };
}    // namespace MC3DSPluginFramework