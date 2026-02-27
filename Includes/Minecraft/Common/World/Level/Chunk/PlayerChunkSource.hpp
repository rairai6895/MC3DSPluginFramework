#pragma once

#include "Minecraft/Common/World/Level/Chunk/ChunkSource.hpp"

namespace MC3DSPluginFramework
{
    // コンストラクタ内で、ChunkSourceコンストラクタじゃないのを呼んでるから直系の子クラスではない可能性がある

    class PlayerChunkSource : public ChunkSource
    {
    public:
        // FUN_0x374178
        void setRadius(int newRadius) {}

    public:
        ~PlayerChunkSource() override;
        LevelChunk *getChunk(const ChunkPos &pos) override;

    private:
        // vtable 0x9B8008
    };
}    // namespace MC3DSPluginFramework