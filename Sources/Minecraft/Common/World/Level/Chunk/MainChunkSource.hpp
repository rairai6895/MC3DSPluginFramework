#pragma once

#include "../BlockPos.hpp"
#include "ChunkSource.hpp"

namespace MC3DSPluginFramework
{
    // "C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\src\\common\\world\\level\\chunk\\MainChunkSource.cpp"
    class MainChunkSource : public ChunkSource
    {
        USE_GAME_ALLOCATOR
    public:
        /*
        MainChunkSource(gstd::unique_ptr<ChunkSource> &&parent)
        {
            reinterpret_cast<MainChunkSource *(*)(MainChunkSource *, gstd::unique_ptr<ChunkSource> &&)>(0x2CC5A0)(this, std::move(parent));
        }
       */

        ~MainChunkSource() override;

        LevelChunk                         *getChunk(const ChunkPos &pos) override;
        LevelChunk                         *requestChunk(const ChunkPos &pos, u32 unknown) override;
        bool                                releaseChunk(LevelChunk *lc) override;
        void                                acquireDiscarded(gstd::unique_ptr<LevelChunk> &lc) override;
        gstd::map<ChunkPos, ChunkRefCount> &getStoredChunks() override;
        void                                Unknown8() override;

    private:
        // 0x9AFB28

        gstd::map<ChunkPos, ChunkRefCount> mStoredChunks;
    };
}    // namespace MC3DSPluginFramework