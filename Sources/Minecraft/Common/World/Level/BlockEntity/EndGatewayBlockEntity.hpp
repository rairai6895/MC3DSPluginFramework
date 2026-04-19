#pragma once

#include "Minecraft/Common/World/Level/BlockEntity/BlockEntity.hpp"

namespace MC3DSPluginFramework
{
    // "C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\src\\common\\world\\level\\block\\entity\\EndGatewayBlockEntity.cpp"
    class EndGatewayBlockEntity : public BlockEntity
    {
        USE_GAME_ALLOCATOR
    public:
        // エンド以外で使用するとクラッシュ
        BlockPos _findExitPosition(BlockSource *region)
        {
            return reinterpret_cast<BlockPos (*)(EndGatewayBlockEntity *, BlockSource *)>(0x40F7DC)(this, region);
        }

    private:
        u32      mRuntime2;
        u32      mBeaconTime;
        BlockPos mExitPos;
        bool     mUnk11;
    };
}    // namespace MC3DSPluginFramework