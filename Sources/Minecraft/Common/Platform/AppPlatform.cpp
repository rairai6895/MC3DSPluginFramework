#include "AppPlatform.hpp"

namespace MC3DSPluginFramework
{
    AppPlatform *AppPlatform::singleton()
    {
        // 0x0FFFF5C0 おそらくmain loop前にローカル変数として作ってる

        return reinterpret_cast<AppPlatform *(*)()>(0x10FFD4)();
    }

    void *AppPlatform::getUIScalingRules()
    {
        return reinterpret_cast<void *(*)(AppPlatform *)>(0x69D224)(this);
    }
}    // namespace MC3DSPluginFramework