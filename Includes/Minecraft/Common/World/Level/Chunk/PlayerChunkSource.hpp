#pragma once

#include "Minecraft/Common/World/Level/Chunk/ChunkSource.hpp"

namespace MC3DSPluginFramework
{
    class PlayerChunkSource : public ChunkSource
    {
    public:
        // FUN_374178
        void setRadius(int newRadius) {}

    public:
        ~PlayerChunkSource() override;
        LevelChunk *getChunk(const ChunkPos &pos) override;

    private:
        // vtable 0x9B8008
    };
}    // namespace MC3DSPluginFramework