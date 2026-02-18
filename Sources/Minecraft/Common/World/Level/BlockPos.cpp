#include "Minecraft/Common/World/Level/BlockPos.hpp"

namespace MC3DSPluginFramework
{
    // FUN_0x64A984
    BlockPos::BlockPos(const Vec3 &pos)
    {
        _init(gstd::truncf(pos.x), gstd::truncf(pos.y), gstd::truncf(pos.z));
    }
}