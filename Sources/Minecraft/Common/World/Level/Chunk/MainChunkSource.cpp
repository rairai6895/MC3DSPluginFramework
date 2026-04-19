#include "MainChunkSource.hpp"
#include "LevelChunk.hpp"

namespace MC3DSPluginFramework
{
    // FUN_0x2CC54C
    // +0x8
    LevelChunk *MainChunkSource::getChunk(const ChunkPos &pos)
    {
        // 登録済みのチャンクから取得

        auto it = mStoredChunks.find(pos);
        return it != mStoredChunks.end() ? it->second.ref().get() : nullptr;
    }

    // FUN_0x2CC360
    // +0xC
    LevelChunk *MainChunkSource::requestChunk(const ChunkPos &pos, u32 unknown)
    {
        if (!(gstd::this_thread::get_id() == gMainThread))
            LOG("This code should only be executed on the main thread", std::this_thread::get_id() == gMainThread, 0);

        auto it = mStoredChunks.find(pos);

        if (it == mStoredChunks.end())
        {
            // 親から取得して登録

            LevelChunk *lc = mParent->requestChunk(pos, unknown);

            if (lc)
                mStoredChunks[pos] = ChunkRefCount(std::move(lc), 1);

            return lc;
        }

        return it->second.grab();
    }

    // FUN_0x2CC1F8
    // +0x10
    bool MainChunkSource::releaseChunk(LevelChunk *lc)
    {
        if (!(gstd::this_thread::get_id() == gMainThread))
            LOG("This code should only be executed on the main thread", std::this_thread::get_id() == gMainThread, 0);

        auto it = mStoredChunks.find(lc->getChunkPos());

        if (it != mStoredChunks.end() && (it->second.release() == 0))
        {
            // 利用者が0になったら親に返却

            mLevel->onReleaseChunk(*it->second);
            mParent->acquireDiscarded(it->second.ref());
            mStoredChunks.erase(it);
            return true;
        }

        return false;
    }

    // FUN_0x2CC4C0
    // +0x3C
    void MainChunkSource::acquireDiscarded(gstd::unique_ptr<LevelChunk> &lc)
    {
        auto it = mStoredChunks.find(lc->getChunkPos());

        if (it == mStoredChunks.end())
        {
            // 未登録時だけ追加する

            mStoredChunks[lc->getChunkPos()] = ChunkRefCount(std::move(lc), 1);
            return;
        }

        it->second.grab();
        lc.release();
    }

    // FUN_0x2CC4B8
    // +0x44
    gstd::map<ChunkPos, ChunkRefCount> &MainChunkSource::getStoredChunks()
    {
        return mStoredChunks;
    }

    // FUN_0x2CC580
    // +0x54
    void MainChunkSource::Unknown8()
    {
        mParent->Unknown8();
    }

}    // namespace MC3DSPluginFramework