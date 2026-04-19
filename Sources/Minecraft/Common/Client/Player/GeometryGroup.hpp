#pragma once

#include "Minecraft/gstd/gstd.hpp"

namespace MC3DSPluginFramework
{
    class ResourcePackManager;

    class GeometryGroup
    {
        USE_GAME_ALLOCATOR
    public:
        GeometryGroup(ResourcePackManager *resourcePackManager);
        virtual ~GeometryGroup();

    private:
        // 0x9A4D40

        gstd::map<u32, gstd::type_unknown<0x38> *> mUnk1;
        ResourcePackManager                       *mResourcePackManager;
        int                                        mUnk2;
        int                                        mUnk3;
        int                                        mUnk4;
        int                                        mUnk5;
    };
}    // namespace MC3DSPluginFramework