#include "ChunkPos.hpp"

namespace MC3DSPluginFramework
{
    // FUN_0x64CA6C
    ChunkPos::ChunkPos(const BlockPos &pos)
    {
        this->x = pos.x >> 4;
        this->y = pos.z >> 4;
    }

    bool ChunkPos::operator<(const ChunkPos &other) const
    {
        if (this->y == other.y)
            return this->x < other.x;
        return this->y < other.y;
    }

}    // namespace MC3DSPluginFramework