#include "ClientInstance.hpp"
#include "../Gui/Screens/Screen.hpp"
#include "../Gui/Screens/ScreenChooser.hpp"
#include "../Gui/Screens/ScreenStack.hpp"
#include "../Input/ClientInputHandler.hpp"
#include "../Player/LocalPlayer.hpp"
#include "Minecraft/Common/World/Entity/Entity.hpp"
#include "Minecraft/Common/World/Entity/Player/Abilities.hpp"
#include "Minecraft/Common/World/Level/Level.hpp"
#include "MinecraftGame.hpp"

namespace MC3DSPluginFramework
{

    MinecraftGame *ClientInstance::getMinecraftGame() const
    {
        return mMinecraftGame;
    }

    Minecraft &ClientInstance::getServerData() const
    {
        return *mServerData;
    }

    // FUN_0x6C72CC
    LocalPlayer *ClientInstance::getPlayer() const
    {
        if (!m0x28)
            return mLocalPlayer;

        return nullptr;
    }

    LocalPlayer *ClientInstance::getLocalPlayer() const
    {
        return mLocalPlayer;
    }

    // FUN_0x124DC8
    Level *ClientInstance::getLevel() const
    {
        return mServerData->getLevel();
    }

    // FUN_0x12AAD4
    ClientInputHandler &ClientInstance::getClientInputHandler() const
    {
        return mMinecraftGame->getClientInputHandler();
    }

    // FUN_0x6C13E8
    ScreenChooser &ClientInstance::getScreenChooser() const
    {
        return mMinecraftGame->getScreenChooser();
    }

    // FUN_0x22743C
    ScreenStack &ClientInstance::getScreenStack() const
    {
        return mMinecraftGame->getScreenStack();
    }

    // FUN_0x252474
    Screen &ClientInstance::getScreen() const
    {
        return mMinecraftGame->getScreen();
    }

    // FUN_0x225EBC
    Options &ClientInstance::getOptions() const
    {
        return mMinecraftGame->getOptions();
    }

    // FUN_0x6C734C
    bool ClientInstance::FUN_006c734c() const
    {
        return reinterpret_cast<bool (*)(const ClientInstance *)>(0x6C734C)(this);

        /*
        auto  screenStack = mMinecraftGame->getScreenStack();
        auto &stack       = screenStack->mScreenStack;
        auto &queue       = screenStack->mPushQueue;
        bool  enabled     = true;

        if (!stack.empty()) {
            auto &top = stack.back();
            enabled   = top->Unknown52();
        }

        if (!enabled)
            return false;

        for (auto &q : queue)
            if (!q->Unknown52())
                return false;

        return false;
        */
    }

    // FUN_0x251158
    bool ClientInstance::pushPauseScreen()
    {
        if (FUN_006c734c())
            getScreenChooser().pushPauseScreen();

        return true;
    }

    // isInGame?
    // FUN_0x12AAE4
    bool ClientInstance::FUN_0012aae4() const
    {
        ScreenStack &screenStack = mMinecraftGame->getScreenStack();

        if (!screenStack.empty())
            if (!screenStack.getScreen().Unknown44())
                return true;

        return false;
    }

    // FUN_0x6C1130
    bool ClientInstance::FUN_006c1130() const
    {
        return mMinecraftGame->getScreenStack().getScreen().Unknown44();
    }

    // FUN_0x6C7368
    Font &ClientInstance::getDefaultFont() const
    {
        return mMinecraftGame->getDefaultFont();
    }

    Font &ClientInstance::getSGAFont() const
    {
        return mMinecraftGame->getSGAFont();
    }

    Font &ClientInstance::getSmallFont() const
    {
        return mMinecraftGame->getSmallFont();
    }

    // FUN_0x6C1120
    TextureGroup &ClientInstance::getTextures() const
    {
        return mMinecraftGame->getTextures();
    }

    void ClientInstance::FUN_00251e5c()
    {
        mMinecraftGame->getScreen().Unknown5();
    }

    // FUN_0x6C13D8
    LevelRenderer *ClientInstance::getLevelRenderer() const
    {
        return mMinecraftGame->getLevelRenderer();
    }

    // FUN_0x225EAC
    Gui &ClientInstance::getGui() const
    {
        return mMinecraftGame->getGui();
    }

    // FUN_0x3E907C
    void ClientInstance::toggleSpectator()
    {
        Abilities &abilities = mLocalPlayer->getAbilities();
        abilities.setBool(Abilities::NOCLIP, !abilities.getBool(Abilities::NOCLIP));
    }

    // FUN_0x6C15E4
    ResourcePackManager &ClientInstance::getResourcePackManager() const
    {
        return mMinecraftGame->getResourcePackManager();
    }

    // FUN_0x6C13F8
    SkinRepository &ClientInstance::getSkinRepository() const
    {
        return mMinecraftGame->getSkinRepository();
    }

    // FUN_0x3E99DC
    void ClientInstance::pickBlockCreative()
    {
        if (mLocalPlayer->isCreative())
            mLocalPlayer->pickBlockCreative(getLevel()->getHitResult(), false);
    }

}    // namespace MC3DSPluginFramework