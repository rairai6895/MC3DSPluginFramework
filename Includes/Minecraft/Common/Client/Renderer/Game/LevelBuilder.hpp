#pragma once

#include "Minecraft/Common/Util/Boxed.hpp"
#include "Minecraft/Helper/Structs.hpp"

namespace MC3DSPluginFramework
{
    // "C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\src\\common\\client\\renderer\\game\\LevelBuilder.cpp"
    class LevelBuilder
    {
    public:
        void buildLevel(Util::Boxed<void *> unknown1, bool unknown2)
        {
            reinterpret_cast<void (*)(LevelBuilder *, Util::Boxed<void *>, bool)>(0x1D5360)(this, unknown1, unknown2);
        }

        void recreateTessellators()
        {
            reinterpret_cast<void (*)(LevelBuilder *)>(0x1D6614)(this);
        }

        void *scheduleChunksForBuildAndCull(const Vec3_Float &unknown1, u32 unknown2, u32 unknown3)
        {
            return reinterpret_cast<void *(*)(LevelBuilder *, const Vec3_Float &, u32, u32)>(0x1D6CAC)(this, unknown1, unknown2, unknown3);
        }

    private:
    };
}    // namespace MC3DSPluginFramework