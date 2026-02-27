#pragma once

#include "Minecraft/Common/World/Level/BlockPos.hpp"

namespace MC3DSPluginFramework
{
    class ChunkPos
    {
    public:
        // FUN_0x64CA6C
        explicit ChunkPos(const BlockPos &pos)
        {
            this->x = pos.x >> 4;
            this->y = pos.z >> 4;
        }

        bool operator<(const ChunkPos &other) const
        {
            if (y == other.y)
                return x < other.x;
            return y < other.y;
        }

        int x, y;

    private:
    };
}    // namespace MC3DSPluginFramework