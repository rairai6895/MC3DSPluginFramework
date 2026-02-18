#include "Minecraft/Common/World/Level/Block.hpp"

namespace MC3DSPluginFramework
{
    // FUN_0x6954E4
    void Block::scheduleNeighborTick(BlockSource *bs, const Vec3_Int &pos)
    {
        BlockPos blockPos;
        Block *target;

        blockPos = { pos.x - 1, pos.y, pos.z };
        target   = bs->getBlock(blockPos);
        if (mUnk6)
            this->scheduleTick(bs, blockPos, target, -1);

        blockPos = { pos.x + 1, pos.y, pos.z };
        target   = bs->getBlock(blockPos);
        if (mUnk6)
            this->scheduleTick(bs, blockPos, target, -1);

        blockPos = { pos.x, pos.y, pos.z - 1 };
        target   = bs->getBlock(blockPos);
        if (mUnk6)
            this->scheduleTick(bs, blockPos, target, -1);

        blockPos = { pos.x, pos.y, pos.z + 1 };
        target   = bs->getBlock(blockPos);
        if (mUnk6)
            this->scheduleTick(bs, blockPos, target, -1);
    }

}    // namespace MC3DSPluginFramework