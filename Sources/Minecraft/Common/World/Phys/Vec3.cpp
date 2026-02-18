#include "Minecraft/Common/World/Phys/Vec3.hpp"

namespace MC3DSPluginFramework
{
    // FUN_0x582C7C
    Vec3::Vec3(const BlockPos &pos)
    {
        _init(pos.x, pos.y, pos.z);
    }

}    // namespace MC3DSPluginFramework