#include "BlockSource.hpp"
#include "Block/Block.hpp"
#include "Chunk/LevelChunk.hpp"
#include "Minecraft/Common/Logger.hpp"
#include "Minecraft/Common/Thread.hpp"

namespace MC3DSPluginFramework
{
    // FUN_0x69DF9C
    Level *BlockSource::getLevel() const
    {
        if (gstd::this_thread::get_id() != gMainThread)
            LOG("This code should only be executed on the main thread", std::this_thread::get_id() == gMainThread, 0);

        if (!mPublicSource)
            LOG("Cannot get the level on a temporary tileSource", mPublicSource, 0);

        return mLevel;
    }

    // FUN_0x69DE2C
    Dimension *BlockSource::getDimension() const
    {
        if (gstd::this_thread::get_id() != gMainThread)
            LOG("This code should only be executed on the main thread", std::this_thread::get_id() == gMainThread, 0);

        if (!mPublicSource)
            LOG("Cannot get the dimension on a temporary tileSource", mPublicSource, 0);

        return mDimension;
    }

    int BlockSource::getDimensionId() const
    {
        return reinterpret_cast<int (*)(const BlockSource *)>(0x69DF64)(this);
    }

    // FUN_0x17AAD8
    Block *BlockSource::getBlock(const BlockPos &pos) const
    {
        return Block::mBlocks[(u8)getBlockId(pos).blockId];
    }

    // FUN_0x17AB00
    Block *BlockSource::getBlock(int x, int y, int z) const
    {
        return getBlock(BlockPos(x, y, z));
    }

    // FUN_0x174648
    BlockData BlockSource::getBlockId(const BlockPos &pos) const
    {
        return reinterpret_cast<BlockData (*)(const BlockSource *, const BlockPos &)>(0x174648)(this, pos);
    }

    // FUN_0x176778
    BlockData BlockSource::getBlockIdAndData(const BlockPos &pos) const
    {
        return reinterpret_cast<BlockData (*)(const BlockSource *, const BlockPos &)>(0x176778)(this, pos);
    }

    void BlockSource::setBlockAndData(const BlockPos &pos, const BlockData &block, UpdateFlag flag, Entity *entity, gstd::unique_ptr<BlockEntity> tileEntity)
    {
        reinterpret_cast<void (*)(BlockSource *, const BlockPos &, const BlockData &, UpdateFlag, Entity *, gstd::unique_ptr<BlockEntity> &&)>(0x176B88)(this, pos, block, flag, entity, std::move(tileEntity));
    }

    // FUN_0x176B24
    void BlockSource::setBlockData(const BlockPos &pos, const BlockData &block, UpdateFlag flag, Entity *entity)
    {
        setBlockAndData(pos, block, flag, entity, {});
    }

    // FUN_0x1762A8
    BlockEntity *BlockSource::getBlockEntity(const BlockPos &pos)
    {
        LevelChunk *lc = getLevelChunk(ChunkPos(pos));

        if (!lc)
            return nullptr;

        return reinterpret_cast<BlockEntity *(*)(LevelChunk *, const ChunkBlockPos &)>(0x157350)(lc, ChunkBlockPos(pos));
    }

    // FUN_0x1762F4
    BlockEntity *BlockSource::getBlockEntity(int x, int y, int z)
    {
        return getBlockEntity(BlockPos(x, y, z));
    }

    // FUN_0x175770
    void *BlockSource::getTickQueue(const BlockPos &pos)
    {
        if (mUnk11)
            return mUnk11;

        LevelChunk *lc = getLevelChunk(ChunkPos(pos));

        if (!lc)
        {
            LOG("This shouldn't happen, ticking an unloaded tile", false, 0);
            return nullptr;
        }

        return lc->getTickQueue();
    }

    LevelChunk *BlockSource::getLevelChunk(const ChunkPos &pos)
    {
        return reinterpret_cast<LevelChunk *(*)(BlockSource *, const ChunkPos &)>(0x17AB3C)(this, pos);
    }

    // FUN_0x174964
    LevelChunk *BlockSource::getLevelChunk(const BlockPos &pos)
    {
        return getLevelChunk(ChunkPos(pos));
    }

    // FUN_0x178910
    int BlockSource::getLoadedHeight(const BlockPos &pos)
    {
        LevelChunk *lc = getLevelChunk(ChunkPos(pos));

        if (!lc)
            return 0;

        return lc->getSubChunks().size() << 4;    // size * 16
    }

    void BlockSource::FUN_00175c44(const BlockPos &pos, const BlockData &block_new, const BlockData &block_old, int flag, Entity *player)
    {
        reinterpret_cast<void (*)(BlockSource *, const BlockPos &, const BlockData &, const BlockData &, int, Entity *)>(0x175C44)(this, pos, block_new, block_old, flag, player);
    }

    // FUN_0x1771DC
    void BlockSource::fireBlockChanged(const BlockPos &pos, BlockData newData, BlockData oldData, int p4, Entity *e)
    {
        if (gstd::this_thread::get_id() != gMainThread)
            LOG("This code should only be executed on the main thread", std::this_thread::get_id() == gMainThread, 0);

        for (auto listener : mListeners)
            listener->blockChanged(*this, pos, newData, oldData, p4, e);
    }

    // FUN_0x175828
    bool BlockSource::isAir(const BlockPos &pos)
    {
        return getBlockId(pos).blockId == BlockId::air;
    }

    // FUN_0x175850
    bool BlockSource::isAir(int x, int y, int z)
    {
        return isAir(BlockPos(x, y, z));
    }

    // FUN_0x17947C
    bool BlockSource::isTransparent(const BlockPos &pos)
    {
        return getBlock(pos)->isTransparent();
    }

    // FUN_0x174140
    void BlockSource::blockEvent(int x, int y, int z, int p4, int p5)
    {
        reinterpret_cast<void (*)(BlockSource *, int, int, int, int, int)>(0x174140)(this, x, y, z, p4, p5);
    }

    // FUN_0x174124
    void BlockSource::blockEvent(const BlockPos &pos, int p2, int p3)
    {
        blockEvent(pos.x, pos.y, pos.z, p2, p3);
    }

    // FUN_0x176594
    void BlockSource::removeListener(const BlockSourceListener &listener)
    {
        mListeners.erase(std::remove(mListeners.begin(), mListeners.end(), &listener));
    }

}    // namespace MC3DSPluginFramework