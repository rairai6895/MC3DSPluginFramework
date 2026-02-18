#pragma once

#include "Minecraft/Common/World/Level/BlockEntity/BlockEntity.hpp"

namespace MC3DSPluginFramework
{
    // "C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\src\\common\\world\\level\\block\\entity\\EndGatewayBlockEntity.cpp"
    class EndGatewayBlockEntity : public BlockEntity
    {
    public:
        // エンド以外で使用するとクラッシュ
        Vec3_Int _findExitPosition(BlockSource *region)
        {
            return reinterpret_cast<Vec3_Int (*)(EndGatewayBlockEntity *, BlockSource *)>(0x40F7DC)(this, region);
        }

    private:
        u32 mRuntime2;
        u32 mBeaconTime;
        Vec3_Int mExitPos;
        bool mUnk11;
    };
}    // namespace MC3DSPluginFramework