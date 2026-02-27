#include "Minecraft/Common/Client/Gui/Screens/ScreenChooser.hpp"
#include "Minecraft/Common/Client/Game/ClientInstance.hpp"
#include "Minecraft/Common/Client/Game/MinecraftGame.hpp"
#include "Minecraft/Common/Client/Gui/Screens/SystemMessagesScreen.hpp"

namespace MC3DSPluginFramework
{
    C_Screen *ScreenChooser::createContainerCreativeScreen(u8 startTab)
    {
        if (void *mem = gstd::malloc(0x664))
            return reinterpret_cast<C_Screen *(*)(void *, MinecraftGame *, ClientInstance *, u8)>(0x45C338)(mem, mMinecraftGame, mClientInstance, startTab);

        return nullptr;
    }

    C_Screen *ScreenChooser::createContanerInventoryScreen(bool creative, bool workbench, bool unknown)
    {
        if (void *mem = gstd::malloc(0x198)) {
            u32 data[3] = {};
            if (workbench) {
                data[0] = 0;
                data[1] = 0x49;
                data[2] = 6;
            }
            return reinterpret_cast<C_Screen *(*)(void *, MinecraftGame *, ClientInstance *, bool, u32 *, bool)>(0x42F1DC)(mem, mMinecraftGame, mClientInstance, creative, data, unknown);
        }

        return nullptr;
    }

    // FUN_0x23AC6C
    void ScreenChooser::_pushScreen(Util::BoxedPtr::Shared<C_Screen> screen, bool unknown)
    {
        mMinecraftGame->pushScreen(screen, unknown);
    }

    void ScreenChooser::openPauseMenu()
    {
        reinterpret_cast<void (*)(ScreenChooser *)>(0x23B758)(this);
    }

    // FUN_0x23E50C
    void ScreenChooser::initSystemMessagesScreen()
    {
        this->_pushScreen(gstd::make_unique<SystemMessagesScreen>(mMinecraftGame, mClientInstance, 0), false);
    }

}    // namespace MC3DSPluginFramework