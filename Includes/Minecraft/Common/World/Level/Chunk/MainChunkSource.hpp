#pragma once

#include "Minecraft/Common/World/Level/BlockPos.hpp"
#include "Minecraft/Common/World/Level/Chunk/ChunkSource.hpp"

namespace MC3DSPluginFramework
{
    // "C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\src\\common\\world\\level\\chunk\\MainChunkSource.cpp"
    class MainChunkSource : public ChunkSource
    {
    public:
        void *operator new(size_t s)
        {
            return gstd::malloc(s);
        }

        /*
        MainChunkSource(gstd::unique_ptr<ChunkSource> &&parent)
        {
            reinterpret_cast<MainChunkSource *(*)(MainChunkSource *, gstd::unique_ptr<ChunkSource> &&)>(0x2CC5A0)(this, std::move(parent));
        }
        */

    public:
        ~MainChunkSource() override;

        LevelChunk *getChunk(const ChunkPos &pos) override
        {
            auto it = mStoredChunks.find(pos);

            if (it != mStoredChunks.end())
                return it->second.get();

            return nullptr;
        }

        LevelChunk *requestChunk(const ChunkPos &pos, u32 unknown) override;
        bool releaseChunk(LevelChunk *chunk) override;

        void acquireDiscarded() override;

        gstd::map<ChunkPos, ChunkRefCount> &getStoredChunks() override
        {
            return mStoredChunks;
        }

        void Unknown8() override
        {
            mParent->Unknown8();
        }

    private:
        // vtable 0x9AFB28

        gstd::map<ChunkPos, ChunkRefCount> mStoredChunks;
    };
}    // namespace MC3DSPluginFramework