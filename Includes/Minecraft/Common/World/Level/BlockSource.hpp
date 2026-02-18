#pragma once

#include "Minecraft/Common/Logger.hpp"
#include "Minecraft/Common/Thread.hpp"
#include "Minecraft/Common/World/Level/Block.hpp"
#include "Minecraft/Common/World/Level/BlockEntity/BlockEntity.hpp"
#include "Minecraft/Common/World/Level/Chunk/LevelChunk.hpp"
#include "Minecraft/Common/World/Level/ChunkPos.hpp"
#include "Minecraft/Common/World/Level/Dimension/Dimension.hpp"
#include "Minecraft/Common/World/Level/Level.hpp"
#include "Minecraft/Helper/GameStructs.hpp"
#include "Minecraft/gstd/gstd.hpp"

namespace MC3DSPluginFramework
{
    class Entity;
    class Level;
    class Block;
    class LevelChunk;
    class BlockEntity;

    // "C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\src\\common\\world\\level\\BlockSource.cpp"
    class BlockSource
    {
    public:
        virtual ~BlockSource();

        Level *getLevel(void) const;

        Dimension *getDimension(void) const;

        DimensionId getDimensionId(void) const
        {
            return reinterpret_cast<DimensionId (*)(const BlockSource *)>(0x69DF64)(this);
        }

        Block *getBlock(const BlockPos &pos) const;

        Block *getBlock(int x, int y, int z) const;

        BlockData getBlockId(const BlockPos &pos) const
        {
            return reinterpret_cast<BlockData (*)(const BlockSource *, const BlockPos &)>(0x174648)(this, pos);
        }

        BlockData getBlockIdAndData(const Vec3_Int &pos) const
        {
            return reinterpret_cast<BlockData (*)(const BlockSource *, const Vec3_Int &)>(0x176778)(this, pos);
        }

        void setBlockAndData(const BlockPos &pos, const BlockData &block, UpdateFlag flag, Entity *entity, gstd::unique_ptr<BlockEntity> &&tileEntity)
        {
            reinterpret_cast<void (*)(BlockSource *, const BlockPos &, const BlockData &, UpdateFlag, Entity *, gstd::unique_ptr<BlockEntity> &&)>(0x176B88)(this, pos, block, flag, entity, std::move(tileEntity));
        }

        void setBlockData(const BlockPos &pos, const BlockData &block, UpdateFlag flag, Entity *entity);

        BlockEntity *getBlockEntity(const BlockPos &pos);

        BlockEntity *getBlockEntity(int x, int y, int z);

        void *getTickQueue(const BlockPos &pos);

        LevelChunk *getLevelChunk(const ChunkPos &pos)
        {
            return reinterpret_cast<LevelChunk *(*)(BlockSource *, const ChunkPos &)>(0x17AB3C)(this, pos);
        }

        int getLoadedHeight(const BlockPos &pos);

        void fireBlockChanged(const BlockPos &pos, const BlockData &block_new, const BlockData &block_old, u32 flag, Entity *player)
        {
            reinterpret_cast<void (*)(BlockSource *, const BlockPos &, const BlockData &, const BlockData &, u32, Entity *)>(0x175C44)(this, pos, block_new, block_old, flag, player);
        }

    private:
        // u32 mVtable;    // 0x999A6C
        u32 mUnk1;    // bools?
        char mUnk2;
        bool mPublicSource;
        u16 mUnk3;
        Level *mLevel;
        void *mChunkSource;    // ChunkSourceっぽい
        Dimension *mDimension;
        u32 mUnk5;
        u32 mUnk6;
        u32 mUnk7;
        u32 mUnk8;
        gstd::vector<void *> mUnk9;
        LevelChunk *mUnk10;
        void *mUnk11;    // TickQueue ?
        u32 mUnk12;
        gstd::vector<Entity *> mEntities;
        gstd::vector<float> mUnk13;
    };
}    // namespace MC3DSPluginFramework