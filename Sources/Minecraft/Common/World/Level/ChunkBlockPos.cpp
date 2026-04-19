#include "ChunkBlockPos.hpp"

namespace MC3DSPluginFramework
{
    // FUN_0x206DD8
    ChunkBlockPos::ChunkBlockPos(const BlockPos &pos)
    {
        x = pos.x & 0xF;
        z = pos.z & 0xF;
        y = pos.y;
    }

    bool ChunkBlockPos::isInChunk2D() const
    {
        return (x < 16) && (z < 16);
    }

    // FUN_0x6BCD7C
    char ChunkBlockPos::index2D() const
    {
        if (!isInChunk2D())
            LOG("Using invalid Chunk tile pos", isInChunk2D(), 0);

        return x + z * 16;
    }
}    // namespace MC3DSPluginFramework