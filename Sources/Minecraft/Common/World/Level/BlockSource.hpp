#pragma once

#include "Block/BlockData.hpp"
#include "ChunkPos.hpp"
#include "Dimension/Dimension.hpp"
#include "LevelListener.hpp"
#include "Minecraft/Common/Thread.hpp"
#include "Minecraft/gstd/gstd.hpp"

namespace MC3DSPluginFramework
{
    class Entity;
    class Level;
    class Block;
    class LevelChunk;
    class BlockEntity;
    class Dimension;
    class ChunkSource;

    // "C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\src\\common\\world\\level\\BlockSource.cpp"
    class BlockSource
    {
        USE_GAME_ALLOCATOR
    public:
        virtual ~BlockSource();

        Level       *getLevel() const;
        Dimension   *getDimension() const;
        int          getDimensionId() const;
        Block       *getBlock(const BlockPos &pos) const;
        Block       *getBlock(int x, int y, int z) const;
        BlockData    getBlockId(const BlockPos &pos) const;
        BlockData    getBlockIdAndData(const BlockPos &pos) const;
        void         setBlockAndData(const BlockPos &pos, const BlockData &block, UpdateFlag flag, Entity *entity, gstd::unique_ptr<BlockEntity> tileEntity);
        void         setBlockData(const BlockPos &pos, const BlockData &block, UpdateFlag flag, Entity *entity);
        BlockEntity *getBlockEntity(const BlockPos &pos);
        BlockEntity *getBlockEntity(int x, int y, int z);
        void        *getTickQueue(const BlockPos &pos);
        LevelChunk  *getLevelChunk(const ChunkPos &pos);
        LevelChunk  *getLevelChunk(const BlockPos &pos);
        int          getLoadedHeight(const BlockPos &pos);
        void         FUN_00175c44(const BlockPos &pos, const BlockData &block_new, const BlockData &block_old, int flag, Entity *player);
        void         fireBlockChanged(const BlockPos &pos, BlockData newData, BlockData oldData, int p4, Entity *e);
        bool         isAir(const BlockPos &pos);
        bool         isAir(int x, int y, int z);
        bool         isTransparent(const BlockPos &pos);
        void         blockEvent(int x, int y, int z, int p4, int p5);
        void         blockEvent(const BlockPos &pos, int p2, int p3);
        void         removeListener(const BlockSourceListener &listener);

    private:
        // 0x999A6C

        gstd::thread::id                    mThreadId;    // +0x4
        u8                                  mUnk2;    // +0x8
        bool                                mPublicSource;    // +0x9
        u16                                 mUnk3;    // +0xA
        Level                              *mLevel;    // +0xC
        ChunkSource                        *mChunkSource;    // +0x10
        Dimension                          *mDimension;    // +0x14
        u16                                 mUnk5;    // +0x18
        u32                                 mUnk6;    // +0x1C
        u32                                 mUnk7;    // +0x20
        u32                                 mUnk8;    // +0x24
        gstd::vector<BlockSourceListener *> mListeners;    // +0x28
        LevelChunk                         *mLastAccessChunk;    // +0x34
        void                               *mUnk11;    // +0x38 TickQueue ?
        u8                                  mUnk12;    // +0x3C
        u8                                  mUnk13;    // +0x3D
        gstd::vector<Entity *>              mEntities;    // +0x40
        gstd::vector<float>                 mUnk14;    // +0x4C
    };
}    // namespace MC3DSPluginFramework