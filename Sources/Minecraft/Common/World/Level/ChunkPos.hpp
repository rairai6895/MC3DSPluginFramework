#pragma once

#include "BlockPos.hpp"

namespace MC3DSPluginFramework
{
    class ChunkPos
    {
    public:
        int x, y;

    public:
        explicit ChunkPos(const BlockPos &pos);
        bool operator<(const ChunkPos &other) const;
    };
}    // namespace MC3DSPluginFramework