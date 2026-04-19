#pragma once

#include "../ChunkPos.hpp"
#include "ChunkRefCount.hpp"
#include "Minecraft/gstd/gstd.hpp"

namespace MC3DSPluginFramework
{
    class CompoundTag;
    class Dimension;
    class Level;

    // "C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\src\\common\\world\\level\\chunk\\ChunkSource.cpp"
    class ChunkSource
    {
        USE_GAME_ALLOCATOR
    public:
        static u32          getFeatureId(gstd::string featureName);
        static gstd::string getFeatureName(u32 featureId);

        ChunkSource(Dimension *dimension, int p1);
        ChunkSource(ChunkSource *parent);
        ChunkSource(gstd::unique_ptr<ChunkSource> &&parent);

        virtual ~ChunkSource() = default;
        virtual LevelChunk                         *getChunk(const ChunkPos &pos);
        virtual LevelChunk                         *requestChunk(const ChunkPos &pos, u32 unknown);
        virtual bool                                releaseChunk(LevelChunk *chunk);
        virtual bool                                postProcess();
        virtual void                                Unknown2();
        virtual void                                loadChunk();
        virtual void                                Unknown3();
        virtual void                                Unknown4();
        virtual gstd::unique_ptr<CompoundTag>       getStructureTag();
        virtual void                                readStructureTag(CompoundTag *tag);
        virtual void                                saveLiveChunk(LevelChunk *lc);
        virtual void                                hintDiscardBatchBegin();
        virtual void                                hintDiscardBatchEnd();
        virtual void                                acquireDiscarded(gstd::unique_ptr<LevelChunk> &lc);
        virtual void                                Unknown5() = delete;    // +0x40
        virtual gstd::map<ChunkPos, ChunkRefCount> &getStoredChunks();
        virtual void                                Unknown6();
        virtual void                                flushPendingWrites();
        virtual void                                Unknown7();    // +0x50
        virtual void                                Unknown8();
        virtual void                                Unknown9() = delete;    // +0x58

    protected:
        // 0x99A150

        int                           mUnk1;
        Level                        *mLevel;
        Dimension                    *mDimension;
        ChunkSource                  *mParent;
        gstd::unique_ptr<ChunkSource> mUnk2;
    };
}    // namespace MC3DSPluginFramework