#pragma once

#include "../BlockPos.hpp"
#include "../BlockSource.hpp"
#include "../ChunkBlockPos.hpp"
#include "../SubChunkBlockPos.hpp"
#include "Minecraft/gstd/gstd.hpp"
#include "SubChunk.hpp"

namespace MC3DSPluginFramework
{
    class Level;
    class BlockSource;
    class BlockEntity;

    class AtomicState
    {
    public:
        // FUN_0x108FA0
        bool tryChangeState(int32_t &from, int32_t to)
        {
            int32_t stateValue;

            do
            {
                stateValue = __ldrex(&mState);
                if (from != stateValue)
                {
                    from = stateValue;
                    return false;
                }
            } while (__strex(&mState, to));

            return true;
        }

        int32_t get()
        {
            return mState;
        }

    private:
        int32_t mState;
    };

    // "C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\src\\common\\world\\level\\chunk\\LevelChunk.cpp"
    class LevelChunk
    {
        // fireBlockEntityChanged FUN_0x179094
    public:
        static constexpr int ChunkState_Generated     = 2;
        static constexpr int ChunkState_NeedsLighting = 4;
        static constexpr int ChunkState_Loaded        = 6;

    public:
        struct SubChunks
        {
            SubChunk *operator[](size_t index) { return mChunks[index]; }
            size_t    size(void) { return mSize; }

        private:
            SubChunk *mChunks[8];
            size_t    mSize;
        };

        void *operator new(size_t size);
        void  operator delete(void *m);

        ~LevelChunk();

        void changeState(int32_t from, int32_t to);

        void _placeBlockEntity(gstd::unique_ptr<BlockEntity> te)
        {
            reinterpret_cast<void (*)(LevelChunk *, gstd::unique_ptr<BlockEntity>)>(0x15870C)(this, std::move(te));
        }

        void _changeTerrainDataState(u32 from, u32 to)
        {
            reinterpret_cast<void (*)(LevelChunk *, u32, u32)>(0x15A58C)(this, from, to);
        }

        void _setGenerator(ChunkSource *generator);

        void *getBiome(const ChunkBlockPos &pos) const
        {
            return reinterpret_cast<void *(*)(const LevelChunk *, const ChunkBlockPos &)>(0x696604)(this, pos);
        }

        SubChunks &getSubChunks(void)
        {
            return mSubChunks;
        }

        SubChunk *getSubChunk(u8 index)
        {
            if (index < MAX_CHUNK_HEIGHT)
                return mSubChunks[index];

            return nullptr;
        }

        void newSubChunk(u8 index)
        {
            reinterpret_cast<void (*)(LevelChunk *, u8, u32)>(0x15750C)(this, index, 1);
        }

        void _placeBlockEntity(gstd::unique_ptr<BlockEntity> &&tileEntity)
        {
            reinterpret_cast<void (*)(LevelChunk *, gstd::unique_ptr<BlockEntity> &&)>(0x15870C)(this, std::move(tileEntity));
        }

        void _removeCallbacks(const ChunkBlockPos &pos, BlockData oldId, BlockData newId, BlockSource &region)
        {
            reinterpret_cast<void (*)(LevelChunk *, const ChunkBlockPos &, BlockData, BlockData, BlockSource &)>(0x157E08)(this, pos, oldId, newId, region);
        }

        void _placeCallbacks(const ChunkBlockPos &pos, BlockData oldId, BlockData newId, BlockSource &region, gstd::unique_ptr<BlockEntity> &&te)
        {
            reinterpret_cast<void (*)(LevelChunk *, const ChunkBlockPos &, BlockData, BlockData, BlockSource &, gstd::unique_ptr<BlockEntity> &&)>(0x15764C)(this, pos, oldId, newId, region, std::move(te));
        }

        void      setBlockData(const BlockPos &pos, const BlockData &block);
        BlockData getBlockData(const BlockPos &pos);

        bool isBlockInChunk(const BlockPos &pos)
        {
            return reinterpret_cast<bool (*)(LevelChunk *, const BlockPos &)>(0x695BD0)(this, pos);
        }

        void *getTickQueue()
        {
            return mUnk13;
        }

        int getState()
        {
            return mChunkState.get();
        }

        ChunkPos &getChunkPos()
        {
            return mChunkPos;
        }

    private:
        static constexpr int MAX_CHUNK_HEIGHT = 128 / 16;

        Level       *mLevel;
        void        *mDimention;
        BlockPos     mStart;
        BlockPos     mEnd;
        ChunkPos     mChunkPos;
        u32          mUnk3;
        ChunkSource *mGenerator;
        u32          mUnk4;
        gstd::string mUnk5;
        AtomicState  mChunkState;
        u32          mTerrainDataState;
        u32          mUnk7;
        u32          mUnk8;
        u32          mUnk9;
        u32          mUnk10;
        u32          mUnk11;
        u32          mUnk12;
        void        *mUnk13;    // TickQueue ?
        SubChunks    mSubChunks;
        //...
    };
}    // namespace MC3DSPluginFramework