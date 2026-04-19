#include "Block.hpp"
#include "../BlockSource.hpp"
#include "../Material/Material.hpp"

namespace MC3DSPluginFramework
{
    // FUN_0x6954E4
    void Block::scheduleNeighborTick(BlockSource *bs, const BlockPos &pos)
    {
        BlockPos blockPos;

        blockPos = { pos.x - 1, pos.y, pos.z };
        if (mUnk6)
            scheduleTick(bs, blockPos, bs->getBlock(blockPos), -1);

        blockPos = { pos.x + 1, pos.y, pos.z };
        if (mUnk6)
            scheduleTick(bs, blockPos, bs->getBlock(blockPos), -1);

        blockPos = { pos.x, pos.y, pos.z - 1 };
        if (mUnk6)
            scheduleTick(bs, blockPos, bs->getBlock(blockPos), -1);

        blockPos = { pos.x, pos.y, pos.z + 1 };
        if (mUnk6)
            scheduleTick(bs, blockPos, bs->getBlock(blockPos), -1);
    }

}    // namespace MC3DSPluginFramework