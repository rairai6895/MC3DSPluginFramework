#include "GeometryGroup.hpp"

namespace MC3DSPluginFramework
{
    // FUN_0x21A94C
    GeometryGroup::GeometryGroup(ResourcePackManager *resourcePackManager) :
        mResourcePackManager(resourcePackManager),
        mUnk2(0),
        mUnk3(0),
        mUnk4(0),
        mUnk5(0)
    {
    }

    GeometryGroup::~GeometryGroup()
    {
        reinterpret_cast<GeometryGroup *(*)(GeometryGroup *)>(0x21AC94)(this);
    }
}    // namespace MC3DSPluginFramework