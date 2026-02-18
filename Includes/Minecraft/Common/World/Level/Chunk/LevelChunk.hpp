#pragma once

#include "Minecraft/Common/World/Level/BlockPos.hpp"
#include "Minecraft/Common/World/Level/BlockSource.hpp"
#include "Minecraft/Common/World/Level/Chunk/SubChunk.hpp"
#include "Minecraft/Common/World/Level/ChunkBlockPos.hpp"
#include "Minecraft/Common/World/Level/SubChunkBlockPos.hpp"

namespace MC3DSPluginFramework
{
    class Level;
    class BlockSource;

    // "C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\src\\common\\world\\level\\chunk\\LevelChunk.cpp"
    class LevelChunk
    {
    public:
        // fireBlockEntityChanged FUN_0x179094

        struct SubChunks {
            SubChunk *operator[](size_t index) { return mChunks[index]; }
            size_t size(void) { return mSize; }

        private:
            SubChunk *mChunks[8];
            size_t mSize;
        };

        void *operator new(size_t size)
        {
            return reinterpret_cast<void *(*)(size_t)>(0x15D164)(size);
        }

        void changeState(s32 from, s32 to);

        void _placeBlockEntity(BlockEntity *te)
        {
            reinterpret_cast<void (*)(LevelChunk *, BlockEntity *)>(0x15870C)(this, te);
        }

        void _changeTerrainDataState(u32 from, u32 to)
        {
            reinterpret_cast<void (*)(LevelChunk *, u32, u32)>(0x15A58C)(this, from, to);
        }

        void _setGenerator(void *generator);

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

        void _removeCallbacks(const ChunkBlockPos &pos, const BlockData &oldId, const BlockData &newId, BlockSource *blockSource)
        {
            reinterpret_cast<void (*)(LevelChunk *, const ChunkBlockPos &, const BlockData &, const BlockData &, BlockSource *)>(0x157E08)(this, pos, oldId, newId, blockSource);
        }

        void _placeCallbacks(const ChunkBlockPos &pos, const BlockData &oldId, const BlockData &newId, BlockSource *blockSource, gstd::unique_ptr<BlockEntity> &&tileEntity)
        {
            reinterpret_cast<void (*)(LevelChunk *, const ChunkBlockPos &, const BlockData &, const BlockData &, BlockSource *, gstd::unique_ptr<BlockEntity> &&)>(0x15764C)(this, pos, oldId, newId, blockSource, std::move(tileEntity));
        }

        void setBlockData(const BlockPos &pos, const BlockData &block);
        BlockData getBlockData(const BlockPos &pos);

        bool isBlockInChunk(const BlockPos &pos)
        {
            return reinterpret_cast<bool (*)(LevelChunk *, const BlockPos &)>(0x695BD0)(this, pos);
        }

        void *getTickQueue()
        {
            return mUnk13;
        }

    private:
        class UnknownClass1
        {
        public:
            // FUN_0x108FA0
            bool tryChangeState(s32 &from, s32 to)
            {
                s32 stateValue;

                do {
                    stateValue = __ldrex(&mState);
                    if (from != stateValue) {
                        from = stateValue;
                        return false;
                    }
                } while (__strex(&mState, to));

                return true;
            }

        private:
            s32 mState;
        };

    private:
        static constexpr int MAX_CHUNK_HEIGHT = 128 / 16;

        Level *mLevel;
        void *mDimention;
        Vec3_Int mStart;
        Vec3_Int mEnd;
        u32 mUnk1;
        u32 mUnk2;
        u32 mUnk3;
        void *mGenerator;
        u32 mUnk4;
        gstd::string mUnk5;
        UnknownClass1 mUnk6;
        u32 mTerrainDataState;
        u32 mUnk7;
        u32 mUnk8;
        u32 mUnk9;
        u32 mUnk10;
        u32 mUnk11;
        u32 mUnk12;
        void *mUnk13;    // TickQueue ?
        SubChunks mSubChunks;
        //...
    };
}    // namespace MC3DSPluginFramework