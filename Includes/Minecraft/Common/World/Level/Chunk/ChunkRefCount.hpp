#pragma once

#include "Minecraft/Common/Logger.hpp"
#include "Minecraft/Common/Thread.hpp"
#include "Minecraft/Common/World/Level/Chunk/LevelChunk.hpp"
#include "Minecraft/gstd/gstd.hpp"

namespace MC3DSPluginFramework
{
    class LevelChunk;

    // "C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\src\\common\\world\\level\\chunk\\ChunkRefCount.cpp"
    class ChunkRefCount
    {
    public:
        // FUN_0x20702C
        ChunkRefCount(LevelChunk *lc, int count) :
            mRefCount(count), mLevelChunk(lc) {}

        // FUN_0x206E10
        LevelChunk *grab()
        {
            if (!(gstd::this_thread::get_id() == gMainThread))
                LOG("This code should only be executed on the main thread", gstd::this_thread::get_id() == gMainThread, 0);

            mRefCount++;

            return mLevelChunk;
        }

        // FUN_0x206EE4
        void release()
        {
            if (!(gstd::this_thread::get_id() == gMainThread))
                LOG("This code should only be executed on the main thread", gstd::this_thread::get_id() == gMainThread, 0);

            if (!(mRefCount > 0))
                LOG("Releasing an already released chunk", mRefCount > 0, 0);

            mRefCount--;
        }

        LevelChunk *get()
        {
            return mLevelChunk;
        }

    private:
        int mRefCount;
        LevelChunk *mLevelChunk;
    };
}    // namespace MC3DSPluginFramework