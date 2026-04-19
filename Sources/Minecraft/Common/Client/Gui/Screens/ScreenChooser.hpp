#pragma once

#include "Minecraft/Common/Util/BoxedPtr.hpp"

namespace MC3DSPluginFramework
{
    class Screen;
    class MinecraftGame;
    class ClientInstance;

    class ScreenChooser
    {
        USE_GAME_ALLOCATOR
    public:
        ScreenChooser(MinecraftGame *minecraftGame, ClientInstance *clientInstance, u8 p3);
        ~ScreenChooser() = default;    // FUN_0x23F2E0

        Screen *createContainerCreativeScreen(u8 startTab);
        Screen *createContanerInventoryScreen(bool creative, bool workbench, bool unknown);
        void    _pushScreen(BoxedPtr::Shared<Screen> screen);
        void    pushPauseScreen();
        void    pushSystemMessagesScreen();
        void    schedulePopScreen(int popCount);

    private:
        MinecraftGame           *mMinecraftGame;    // +0x0
        ClientInstance          *mClientInstance;    // +0x4
        u8                       m0x8;    // +0x8
        BoxedPtr::Shared<void *> m0xC;    // +0xC
    };
}    // namespace MC3DSPluginFramework