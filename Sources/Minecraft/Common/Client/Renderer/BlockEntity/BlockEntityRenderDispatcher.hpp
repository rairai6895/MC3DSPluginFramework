#pragma once

#include "Minecraft/Common/Client/Game/ClientInstance.hpp"

namespace MC3DSPluginFramework
{
    // "C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\src\\common\\client\\renderer\\blockentity\\BlockEntityRenderDispatcher.cpp"
    class BlockEntityRenderDispatcher
    {
        USE_GAME_ALLOCATOR
    public:
        static void createInstance(MinecraftGame *minecraftGame, ClientInstance *clientInstance)
        {
            reinterpret_cast<void (*)(MinecraftGame *, ClientInstance *)>(0x494570)(minecraftGame, clientInstance);
        }

        // FUN_0x4944F8
        static BlockEntityRenderDispatcher *getInstance(void)
        {
            return instance.get();
        }

    private:
        static inline gstd::unique_ptr<BlockEntityRenderDispatcher> &instance = *(gstd::unique_ptr<BlockEntityRenderDispatcher> *)0xA320F0;
    };
}    // namespace MC3DSPluginFramework