#pragma once

#include "Minecraft/Common/Logger.hpp"
#include "Minecraft/gstd/gstd.hpp"

namespace MC3DSPluginFramework
{
    // "C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\src\\common\\client\\renderer\\entity\\ItemRenderer.cpp"
    class ItemRenderer
    {
        USE_GAME_ALLOCATOR
    public:
        // FUN_0x1D2E04
        static ItemRenderer &getInstance()
        {
            if (!instance)
                LOG("createSingleton must be called before referencing.", instance, 0);

            return *instance;
        }

    private:
        static inline ItemRenderer *&instance = *(ItemRenderer **)0xA32288;

        // 0x9A0C90
    };
}    // namespace MC3DSPluginFramework