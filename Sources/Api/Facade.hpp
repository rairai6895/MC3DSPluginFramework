#pragma once

#include "Minecraft/Common/Client/Game/ClientInstance.hpp"
#include "Minecraft/Common/Client/Game/MinecraftGame.hpp"
#include "Minecraft/Common/Client/Player/LocalPlayer.hpp"
#include "Minecraft/Common/Client/Renderer/Entity/EntityRenderDispatcher.hpp"

namespace MC3DSPluginFramework
{
    class Facade
    {
    public:
        static bool appStarted()
        {
            return EntityRenderDispatcher::hasInstance();
        }

        static MinecraftGame *getMinecraftGame()
        {
            return appStarted() ? &EntityRenderDispatcher::getInstance()->getMinecraftGame() : nullptr;
        }

        static ClientInstance *getClient()
        {
            return appStarted() ? &EntityRenderDispatcher::getInstance()->getClientInstance() : nullptr;
        }

        static LocalPlayer *getLocalPlayer()
        {
            return isInLevel() ? getClient()->getLocalPlayer() : nullptr;
        }

        static bool isInLevel()
        {
            return appStarted() && getClient()->getLevel();
        }

        static gstd::vector<Entity *> *getEntityList()
        {
            /*
            if (auto addr = *(u32 *)(0xA32244))
                return (gstd::vector<Entity *> *)(addr + 0x110);
            */

            return (gstd::vector<Entity *> *)((u32)getClient()->getLevelRenderer() + 0x744);
        }

    private:
    };
}    // namespace MC3DSPluginFramework