#pragma once

#include "../Entity/Entity.hpp"
#include "../Level/BlockPos.hpp"

namespace MC3DSPluginFramework
{
    class HitResult
    {
    public:
        enum HitType {
            Block  = 0,
            Entity = 1,
            None   = 3,
        };

        enum BlockFace {
            Bottom,
            Top,
            North,
            South,
            West,
            East,
        };

        u8            mType;    // +0x0
        int           mFace;    // +0x4
        BlockPos      mBlockPos;    // +0x8
        Vec3<float>   m0x10;
        class Entity *mEntity;    // +0x14
    };

}    // namespace MC3DSPluginFramework