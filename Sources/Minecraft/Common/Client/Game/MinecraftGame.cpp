#include "Minecraft/Common/Client/Game/MinecraftGame.hpp"
#include "Minecraft/Common/Client/Game/ClientInstance.hpp"
#include "Minecraft/Common/Client/Gui/Screens/ScreenChooser.hpp"
#include "Minecraft/Common/Client/Gui/Screens/ScreenStack.hpp"
#include "Minecraft/Common/World/Level/Level.hpp"

namespace MC3DSPluginFramework
{
    void MinecraftGame::onAppResumed(void)
    {
        reinterpret_cast<void (*)(MinecraftGame *)>(0x2269D4)(this);
    }

    void MinecraftGame::_setupLevelRendering(Level *level, Entity *player)
    {
        reinterpret_cast<void (*)(MinecraftGame *, Level *, Entity *)>(0x22AD74)(this, level, player);
    }

    void MinecraftGame::pushScreen(Util::BoxedPtr::Shared<C_Screen> screen, bool unknown)
    {
        reinterpret_cast<void (*)(MinecraftGame *, Util::BoxedPtr::Shared<C_Screen>, bool)>(0x226054)(this, screen, unknown);
    }

    bool MinecraftGame::isShowingScreen(gstd::string screen) const
    {
        return reinterpret_cast<bool (*)(const MinecraftGame *, gstd::string)>(0x6C12B8)(this, screen);
    }

    ScreenStack *MinecraftGame::getScreenStack(void) const
    {
        return mScreenStack;
    }

    gstd::vector<ClientInstance *> &MinecraftGame::getClientInstances()
    {
        return mUnk29;
    }

    // FUN_0x25118C
    Entity *MinecraftGame::getPlayer()
    {
        return this->getClientInstances()[0]->getLocalPlayer();
    }

    // FUN_0x6C1400
    void *MinecraftGame::getSkinRepository() const
    {
        if (!mSkinRepository)
            LOG("The skin repository has not be created yet.", mSkinRepository != nullptr, 0);

        return mSkinRepository;
    }

    // FUN_0x6C16B4
    void *MinecraftGame::getResourcePackRepository() const
    {
        if (!mResourcePackRepository)
            LOG("The resource pack repository has not be created yet.", mResourcePackRepository != nullptr, 0);

        return mResourcePackRepository;
    }

    // FUN_0x6C15EC
    void *MinecraftGame::getResourcePackManager() const
    {
        if (!mResourcePackManager)
            LOG("The resource pack manager has not be created yet.", mResourcePackManager != nullptr, 0);

        return mResourcePackManager;
    }

    // FUN_0x6C14CC
    void *MinecraftGame::getSkinGeometryGroup() const
    {
        if (!mSkinGeometryGroup)
            LOG("The skin model repository has not be created yet.", mSkinGeometryGroup != nullptr, 0);

        return mSkinGeometryGroup;
    }

    // FUN_0x6C1220
    void *MinecraftGame::getUserManager() const
    {
        if (!mUserManager)
            LOG("UserManager must have been created here.", mUserManager != nullptr, 0);

        return mUserManager;
    }

    // FUN_0x6C1178
    void *MinecraftGame::getMultiPlayer() const
    {
        if (!mMultiplayer)
            LOG("Multiplayer must have been created here.", mMultiplayer != nullptr, 0);

        return mMultiplayer;
    }

    ScreenChooser *MinecraftGame::getScreenChooser() const
    {
        return mScreenChooser;
    }

    // FUN_0x12D544
    C_Screen &MinecraftGame::getScreen() const
    {
        return mScreenStack->getScreen();
    }

}    // namespace MC3DSPluginFramework