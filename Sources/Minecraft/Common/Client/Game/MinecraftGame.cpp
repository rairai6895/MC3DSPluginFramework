#include "MinecraftGame.hpp"
#include "ClientInstance.hpp"
#include "Minecraft/Common/Client/Gui/Screens/ScreenChooser.hpp"
#include "Minecraft/Common/Client/Gui/Screens/ScreenStack.hpp"
#include "Minecraft/Common/Client/Sound/SoundEngine.hpp"
#include "Minecraft/Common/World/Level/Level.hpp"

namespace MC3DSPluginFramework
{
    void MinecraftGame::onAppResumed()
    {
        reinterpret_cast<void (*)(MinecraftGame *)>(0x2269D4)(this);
    }

    void MinecraftGame::_setupLevelRendering(Level *level, LocalPlayer *player)
    {
        reinterpret_cast<void (*)(MinecraftGame *, Level *, LocalPlayer *)>(0x22AD74)(this, level, player);
    }

    void MinecraftGame::pushScreen(BoxedPtr::Shared<Screen> newScreen)
    {
        reinterpret_cast<void (*)(MinecraftGame *, BoxedPtr::Shared<Screen>)>(0x226054)(this, newScreen);
    }

    bool MinecraftGame::isShowingScreen(gstd::string screen) const
    {
        return reinterpret_cast<bool (*)(const MinecraftGame *, gstd::string)>(0x6C12B8)(this, screen);
    }

    ScreenStack &MinecraftGame::getScreenStack() const
    {
        return *mScreenStack;
    }

    gstd::vector<gstd::unique_ptr<ClientInstance>> &MinecraftGame::getClientInstances()
    {
        return mClientInstances;
    }

    // FUN_0x22BF04
    ClientInstance &MinecraftGame::getClientInstance() const
    {
        return *mClientInstances[0];
    }

    // FUN_0x25118C
    LocalPlayer *MinecraftGame::getPlayer()
    {
        return getClientInstance().getLocalPlayer();
    }

    // FUN_0x6C1400
    SkinRepository &MinecraftGame::getSkinRepository() const
    {
        if (!mSkinRepository)
            LOG("The skin repository has not be created yet.", mSkinRepository != nullptr, 0);

        return *mSkinRepository;
    }

    // FUN_0x6C16B4
    ResourcePackRepository &MinecraftGame::getResourcePackRepository() const
    {
        if (!mResourcePackRepository)
            LOG("The resource pack repository has not be created yet.", mResourcePackRepository != nullptr, 0);

        return *mResourcePackRepository;
    }

    // FUN_0x6C15EC
    ResourcePackManager &MinecraftGame::getResourcePackManager() const
    {
        if (!mResourcePackManager)
            LOG("The resource pack manager has not be created yet.", mResourcePackManager != nullptr, 0);

        return *mResourcePackManager;
    }

    // FUN_0x6C1330
    GeometryGroup &MinecraftGame::getGeometryGroup() const
    {
        if (!mGeometryGroup)
            LOG("The model repository has not be created yet.", mGeometryGroup != nullptr, 0);

        return *mGeometryGroup;
    }

    // FUN_0x6C14CC
    SkinGeometryGroup &MinecraftGame::getSkinGeometryGroup() const
    {
        if (!mSkinGeometryGroup)
            LOG("The skin model repository has not be created yet.", mSkinGeometryGroup != nullptr, 0);

        return *mSkinGeometryGroup;
    }

    // FUN_0x6C1220
    UserManager &MinecraftGame::getUserManager() const
    {
        if (!mUserManager)
            LOG("UserManager must have been created here.", mUserManager != nullptr, 0);

        return *mUserManager;
    }

    // FUN_0x6C1178
    void *MinecraftGame::getMultiPlayer() const
    {
        if (!mMultiplayer)
            LOG("Multiplayer must have been created here.", mMultiplayer != nullptr, 0);

        return mMultiplayer.get();
    }

    ScreenChooser &MinecraftGame::getScreenChooser() const
    {
        return *mScreenChooser;
    }

    // FUN_0x12D544
    Screen &MinecraftGame::getScreen() const
    {
        return mScreenStack->getScreen();
    }

    Font &MinecraftGame::getDefaultFont() const
    {
        return *mDefaultFont;
    }

    Font &MinecraftGame::getSGAFont() const
    {
        return *mSGAFont;
    }

    Font &MinecraftGame::getSmallFont() const
    {
        return *mSmallFont;
    }

    ClientInputHandler &MinecraftGame::getClientInputHandler() const
    {
        return *mClientInputHandler;
    }

    // FUN_0x225EC4
    Options &MinecraftGame::getOptions() const
    {
        return *mUserManager->getOptions()->second;
    }

    // FUN_0x1A82FC
    void MinecraftGame::schedulePopScreen(int popCount)
    {
        mScreenStack->schedulePopScreen(popCount);
    }

    TextureGroup &MinecraftGame::getTextures() const
    {
        return *mTextures;
    }

    LevelRenderer *MinecraftGame::getLevelRenderer() const
    {
        return mLevelRenderer.get();
    }

    // FUN_0x230B18
    void MinecraftGame::playSound(u32 hashId, float volume, float pitch)
    {
        mSoundEngine->play(hashId, volume, pitch);
    }

    // FUN_0x225EAC
    Gui &MinecraftGame::getGui() const
    {
        return *mGui;
    }

    // virtual
    // FUN_0x251144
    Minecraft &MinecraftGame::getServerData() const
    {
        return getClientInstance().getServerData();
    }

}    // namespace MC3DSPluginFramework