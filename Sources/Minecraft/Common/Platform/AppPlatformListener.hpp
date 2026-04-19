#pragma once

#include "Minecraft/gstd/gstd.hpp"

namespace MC3DSPluginFramework
{
    class AppPlatform;

    class AppPlatformListener
    {
    public:
        // FUN_0x111BD0
        AppPlatformListener(int unused)
        {
            mAppPlatform = nullptr;
        }

        AppPlatformListener()
        {
            reinterpret_cast<AppPlatformListener *(*)(AppPlatformListener *)>(0x3ACAF8)(this);
        }

        virtual ~AppPlatformListener();

        // todo

    private:
        // 0x9BB50C

        AppPlatform *mAppPlatform;
    };
}    // namespace MC3DSPluginFramework