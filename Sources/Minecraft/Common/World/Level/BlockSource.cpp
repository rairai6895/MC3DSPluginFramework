#include "Minecraft/Common/World/Level/BlockSource.hpp"
#include "Minecraft/Common/World/Level/Chunk/LevelChunk.hpp"

namespace MC3DSPluginFramework
{
    // FUN_0x69DF9C
    Level *BlockSource::getLevel(void) const
    {
        if (gstd::this_thread::get_id() != gMainThread)
            LOG("This code should only be executed on the main thread", std::this_thread::get_id() == gMainThread, 0);

        if (!mPublicSource)
            LOG("Cannot get the level on a temporary tileSource", mPublicSource, 0);

        return mLevel;
    }

    // FUN_0x69DE2C
    Dimension *BlockSource::getDimension(void) const
    {
        if (gstd::this_thread::get_id() != gMainThread)
            LOG("This code should only be executed on the main thread", std::this_thread::get_id() == gMainThread, 0);

        if (!mPublicSource)
            LOG("Cannot get the dimension on a temporary tileSource", mPublicSource, 0);

        return mDimension;
    }

    // FUN_0x17AAD8
    Block *BlockSource::getBlock(const BlockPos &pos) const
    {
        return Block::mBlocks[(u8)this->getBlockId(pos).blockId];
    }

    // FUN_0x17AB00
    Block *BlockSource::getBlock(int x, int y, int z) const
    {
        // return Block::mBlocks[(u8)this->getBlockId(BlockPos(x, y, z)).blockId];
        return this->getBlock(BlockPos(x, y, z));
    }

    // FUN_0x176B24
    void BlockSource::setBlockData(const BlockPos &pos, const BlockData &block, UpdateFlag flag, Entity *entity)
    {
        this->setBlockAndData(pos, block, flag, entity, {});
    }

    // FUN_0x1762A8
    BlockEntity *BlockSource::getBlockEntity(const BlockPos &pos)
    {
        BlockEntity *res = nullptr;

        if (LevelChunk *lc = this->getLevelChunk(ChunkPos(pos)))
            res = reinterpret_cast<BlockEntity *(*)(LevelChunk *, const ChunkBlockPos &)>(0x157350)(lc, ChunkBlockPos(pos));

        return res;
    }

    // FUN_0x1762F4
    BlockEntity *BlockSource::getBlockEntity(int x, int y, int z)
    {
        return this->getBlockEntity(BlockPos(x, y, z));
    }

    // FUN_0x175770
    void *BlockSource::getTickQueue(const BlockPos &pos)
    {
        if (!mUnk11) {
            LevelChunk *lc = this->getLevelChunk(ChunkPos(pos));

            if (!lc) {
                LOG("This shouldn't happen, ticking an unloaded tile", false, 0);
                return nullptr;
            }

            return lc->getTickQueue();
        }

        return mUnk11;
    }

    // FUN_0x178910
    int BlockSource::getLoadedHeight(const BlockPos &pos)
    {
        if (LevelChunk *lc = this->getLevelChunk(ChunkPos(pos)))
            return lc->getSubChunks().size() << 4;    // size * 16

        return 0;
    }

}    // namespace MC3DSPluginFramework