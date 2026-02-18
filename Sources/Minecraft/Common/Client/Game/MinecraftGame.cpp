#include "Minecraft/Common/Client/Game/MinecraftGame.hpp"

namespace MC3DSPluginFramework
{
    // FUN_0x25118C
    Entity *MinecraftGame::getPlayer(void)
    {
        return this->getClientInstances()[0]->getLocalPlayer();
    }

}    // namespace MC3DSPluginFramework