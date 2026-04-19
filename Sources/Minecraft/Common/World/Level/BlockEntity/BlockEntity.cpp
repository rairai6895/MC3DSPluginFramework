#include "BlockEntity.hpp"

namespace MC3DSPluginFramework
{
    // FUN_0x173F50
    BlockEntity::BlockEntity(BlockEntityType type, const BlockPos &pos) :
        mRuntime(0),
        mBlock(nullptr),
        m0xC(0),
        m0x10(0),
        m0x14(0),
        m0x18(0),
        m0x1C(0),
        mPos(pos),
        mAABB((Vec3<float>(pos) + *(Vec3<float> *)0xB17278), Vec3<float>(pos)),
        m0x48(0),
        mType(type),
        mRunningId(++(*(int *)0xA34CE0)),
        m0x54(0),
        mMovable(1),
        m0x56(0),
        m0x57(0),
        mNamed(0),
        m0x5D(1)
    {
        Vec3<float> min(mPos);
        mAABB.set(min, min + *(Vec3<float> *)0xB17278);
    }
}    // namespace MC3DSPluginFramework