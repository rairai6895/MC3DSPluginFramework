#pragma once

#include "Minecraft/Common/Client/Game/ClientInstance.hpp"

namespace MC3DSPluginFramework
{
    // "C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\src\\common\\client\\renderer\\blockentity\\BlockEntityRenderDispatcher.cpp"
    class BlockEntityRenderDispatcher
    {
    public:
        static void createInstance(MinecraftGame *minecraftGame, ClientInstance *clientInstance)
        {
            reinterpret_cast<void (*)(MinecraftGame *, ClientInstance *)>(0x494570)(minecraftGame, clientInstance);
        }

        // FUN_0x4944F8
        static BlockEntityRenderDispatcher *getInstance(void) { return mInstance; }

    private:
        static inline BlockEntityRenderDispatcher *&mInstance = *(BlockEntityRenderDispatcher **)0xA320F0;
    };
}    // namespace MC3DSPluginFramework