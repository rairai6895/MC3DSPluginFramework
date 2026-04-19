#pragma once

#include "LevelChunk.hpp"
#include "Minecraft/gstd/gstd.hpp"

namespace MC3DSPluginFramework
{
    class LevelChunk;

    // "C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\src\\common\\world\\level\\chunk\\ChunkRefCount.cpp"
    class ChunkRefCount
    {
    public:
        ChunkRefCount();
        ChunkRefCount(LevelChunk *lc, int refCount);
        ChunkRefCount(gstd::unique_ptr<LevelChunk> lc, int refCount);
        ~ChunkRefCount() = default;    // FUN_0x207094

        ChunkRefCount(ChunkRefCount &&other)
        {
            mRefCount       = other.mRefCount;
            other.mRefCount = 0;
            mLevelChunk     = std::move(other.mLevelChunk);
        }

        ChunkRefCount &operator=(ChunkRefCount &&other);
        LevelChunk    &operator*() const;

        LevelChunk                   *grab();
        int                           release();
        gstd::unique_ptr<LevelChunk> &ref();

    private:
        int                          mRefCount;
        gstd::unique_ptr<LevelChunk> mLevelChunk;
    };
}    // namespace MC3DSPluginFramework