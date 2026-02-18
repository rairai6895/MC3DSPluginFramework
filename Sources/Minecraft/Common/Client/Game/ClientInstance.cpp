#include "Minecraft/Common/Client/Game/ClientInstance.hpp"

namespace MC3DSPluginFramework
{
    // FUN_0x6C72CC
    Entity *ClientInstance::getPlayer(void) const
    {
        if (!mUnk9)
            return mLocalPlayer;

        return nullptr;
    }

    // FUN_0x6C13E8
    ScreenChooser *ClientInstance::getScreenChooser(void) const
    {
        return mMinecraftGame->getScreenChooser();
    }

    // FUN_0x251158
    void ClientInstance::pause(void)
    {
        if (!this->isPaused())
            this->getScreenChooser()->openPauseMenu();
    }

}    // namespace MC3DSPluginFramework