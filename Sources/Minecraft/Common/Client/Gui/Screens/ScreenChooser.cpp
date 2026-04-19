#include "Minecraft/Common/Client/Gui/Screens/ScreenChooser.hpp"
#include "Minecraft/Common/Client/Game/ClientInstance.hpp"
#include "Minecraft/Common/Client/Game/MinecraftGame.hpp"
#include "Minecraft/Common/Client/Gui/Screens/SystemMessagesScreen.hpp"

namespace MC3DSPluginFramework
{
    // FUN_0x23F2B4
    ScreenChooser::ScreenChooser(MinecraftGame *minecraftGame, ClientInstance *clientInstance, u8 p3) :
        mMinecraftGame(minecraftGame),
        mClientInstance(clientInstance),
        m0x8(p3)
    {
    }

    Screen *ScreenChooser::createContainerCreativeScreen(u8 startTab)
    {
        if (void *mem = gstd::malloc(0x664))
            return reinterpret_cast<Screen *(*)(void *, MinecraftGame *, ClientInstance *, u8)>(0x45C338)(mem, mMinecraftGame, mClientInstance, startTab);

        return nullptr;
    }

    Screen *ScreenChooser::createContanerInventoryScreen(bool creative, bool workbench, bool unknown)
    {
        if (void *mem = gstd::malloc(0x198))
        {
            u32 data[3] = {};
            if (workbench)
            {
                data[0] = 0;
                data[1] = 0x49;
                data[2] = 6;
            }
            return reinterpret_cast<Screen *(*)(void *, MinecraftGame *, ClientInstance *, bool, u32 *, bool)>(0x42F1DC)(mem, mMinecraftGame, mClientInstance, creative, data, unknown);
        }

        return nullptr;
    }

    // FUN_0x23AC6C
    void ScreenChooser::_pushScreen(BoxedPtr::Shared<Screen> screen)
    {
        mMinecraftGame->pushScreen(screen);
    }

    void ScreenChooser::pushPauseScreen()
    {
        reinterpret_cast<void (*)(ScreenChooser *)>(0x23B758)(this);
    }

    // FUN_0x23E50C
    void ScreenChooser::pushSystemMessagesScreen()
    {
        _pushScreen(gstd::make_unique<SystemMessagesScreen>(mMinecraftGame, mClientInstance));
    }

    // FUN_0x23C55C
    void ScreenChooser::schedulePopScreen(int popCount)
    {
        mMinecraftGame->schedulePopScreen(popCount);
    }

}    // namespace MC3DSPluginFramework