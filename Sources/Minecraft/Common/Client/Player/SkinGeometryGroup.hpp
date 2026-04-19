#pragma once

#include "GeometryGroup.hpp"

namespace MC3DSPluginFramework
{
    class SkinGeometryGroup : public GeometryGroup
    {
        USE_GAME_ALLOCATOR
    public:
        SkinGeometryGroup(ResourcePackManager *resourcePackManager);
        ~SkinGeometryGroup() override = default;

    private:
        // 0x9B8924
    };
}    // namespace MC3DSPluginFramework