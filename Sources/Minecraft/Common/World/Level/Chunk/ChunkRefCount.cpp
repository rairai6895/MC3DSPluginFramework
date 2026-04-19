#include "ChunkRefCount.hpp"
#include "LevelChunk.hpp"
#include "Minecraft/Common/Logger.hpp"
#include "Minecraft/Common/Thread.hpp"

namespace MC3DSPluginFramework
{
    ChunkRefCount::ChunkRefCount() :
        mRefCount(0)
    {
    }

    // FUN_0x20702C
    ChunkRefCount::ChunkRefCount(LevelChunk *lc, int refCount) :
        mRefCount(refCount),
        mLevelChunk(lc) {}

    // FUN_0x207014
    ChunkRefCount::ChunkRefCount(gstd::unique_ptr<LevelChunk> lc, int refCount) :
        mRefCount(refCount),
        mLevelChunk(std::move(lc))
    {
    }

    // FUN_0x2070C0
    ChunkRefCount &ChunkRefCount::operator=(ChunkRefCount &&other)
    {
        mRefCount       = other.mRefCount;
        other.mRefCount = 0;
        mLevelChunk     = std::move(other.mLevelChunk);

        return *this;
    }

    LevelChunk &ChunkRefCount::operator*() const
    {
        return *mLevelChunk;
    }

    // FUN_0x206E10
    LevelChunk *ChunkRefCount::grab()
    {
        if (!(gstd::this_thread::get_id() == gMainThread))
            LOG("This code should only be executed on the main thread", gstd::this_thread::get_id() == gMainThread, 0);

        ++mRefCount;

        return mLevelChunk.get();
    }

    // FUN_0x206EE4
    int ChunkRefCount::release()
    {
        if (!(gstd::this_thread::get_id() == gMainThread))
            LOG("This code should only be executed on the main thread", gstd::this_thread::get_id() == gMainThread, 0);

        if (!(mRefCount > 0))
            LOG("Releasing an already released chunk", mRefCount > 0, 0);

        return --mRefCount;
    }

    gstd::unique_ptr<LevelChunk> &ChunkRefCount::ref()
    {
        return mLevelChunk;
    }

}    // namespace MC3DSPluginFramework