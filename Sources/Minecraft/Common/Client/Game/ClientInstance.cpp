#include "Minecraft/Common/Client/Game/ClientInstance.hpp"
#include "Minecraft/Common/Client/Game/MinecraftGame.hpp"
#include "Minecraft/Common/Client/Gui/Screens/ScreenChooser.hpp"
#include "Minecraft/Common/Client/Gui/Screens/ScreenStack.hpp"
#include "Minecraft/Common/Client/Input/PlayerController.hpp"
#include "Minecraft/Common/World/Level/Level.hpp"

namespace MC3DSPluginFramework
{
    MinecraftGame *ClientInstance::getMinecraftGame() const
    {
        return mMinecraftGame;
    }

    void ClientInstance::onTick(u32 tick, u32 maxtick)
    {
        reinterpret_cast<void (*)(ClientInstance *, u32, u32)>(0x2520FC)(this, tick, maxtick);
    }

    void *ClientInstance::getServerData() const
    {
        return mServerData;

        // FUN_0x124DD0 getLevel
    }

    // FUN_0x6C72CC
    Entity *ClientInstance::getPlayer() const
    {
        if (!mUnk9)
            return mLocalPlayer;

        return nullptr;
    }

    Entity *ClientInstance::getLocalPlayer() const
    {
        return mLocalPlayer;
    }

    Level *ClientInstance::getLevel() const
    {
        return reinterpret_cast<Level *(*)(const ClientInstance *)>(0x124DC8)(this);
    }

    PlayerController *ClientInstance::getController() const
    {
        return reinterpret_cast<PlayerController *(*)(const ClientInstance *)>(0x12AAD4)(this);
    }

    // FUN_0x6C13E8
    ScreenChooser *ClientInstance::getScreenChooser() const
    {
        return mMinecraftGame->getScreenChooser();
    }

    // FUN_0x22743C
    ScreenStack *ClientInstance::getScreenStack() const
    {
        return mMinecraftGame->getScreenStack();
    }

    // FUN_0x252474
    C_Screen &ClientInstance::getScreen() const
    {
        return mMinecraftGame->getScreen();
    }

    // FUN_0x6C734C
    bool ClientInstance::isStickInputEnabled() const
    {
        auto screenStack = mMinecraftGame->getScreenStack();
        auto &stack      = screenStack->mScreenStack;
        auto &unkStack   = screenStack->mUnk1;

        bool enabled = true;

        if (!stack.empty()) {
            auto &top = stack.back();
            enabled   = top->enablesStickInput();
        }

        if (enabled) {
            for (auto &unk : unkStack)
                if (!unk->enablesStickInput())
                    return false;
        }

        return enabled;
    }

    // FUN_0x251158
    bool ClientInstance::pause()
    {
        if (this->isStickInputEnabled())
            this->getScreenChooser()->openPauseMenu();

        return true;
    }

    bool ClientInstance::FUN_0012aae4() const
    {
        auto screenStack = mMinecraftGame->getScreenStack();

        if (!screenStack->empty())
            if (!screenStack->getScreen().disablesStickInput())
                return 1;

        return 0;
    }

}    // namespace MC3DSPluginFramework