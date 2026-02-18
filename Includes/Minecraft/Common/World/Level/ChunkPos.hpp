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

        u32 x, y;

    private:
    };
}    // namespace MC3DSPluginFramework