#pragma once

#include "Minecraft/Common/Client/Game/MinecraftGame.hpp"
#include "Minecraft/Common/Client/Gui/Screens/BaseScreen.hpp"
#include "Minecraft/Common/Client/Gui/Screens/SystemMessagesScreen.hpp"

namespace MC3DSPluginFramework
{
    class ScreenChooser
    {
    public:
        BaseScreen *createContainerCreativeScreen(u8 startTab)
        {
            if (void *mem = gstd::malloc(0x664))
                return reinterpret_cast<BaseScreen *(*)(void *, MinecraftGame *, ClientInstance *, u8)>(0x45C338)(mem, mMinecraftGame, mClientInstance, startTab);

            return nullptr;
        }

        BaseScreen *createContanerInventoryScreen(bool creative, bool workbench, bool unknown)
        {
            if (void *mem = gstd::malloc(0x198)) {
                u32 data[3] = {};
                if (workbench) {
                    data[0] = 0;
                    data[1] = 0x49;
                    data[2] = 6;
                }
                return reinterpret_cast<BaseScreen *(*)(void *, MinecraftGame *, ClientInstance *, bool, u32 *, bool)>(0x42F1DC)(mem, mMinecraftGame, mClientInstance, creative, data, unknown);
            }

            return nullptr;
        }

        void _pushScreen(Util::BoxedPtr::Shared<BaseScreen> screen, bool unknown);

        void openPauseMenu(void)
        {
            reinterpret_cast<void (*)(ScreenChooser *)>(0x23B758)(this);
        }

        // FUN_0x23E50C
        void initSystemMessagesScreen(void)
        {
            _pushScreen(new SystemMessagesScreen(mMinecraftGame, mClientInstance, 0), false);
        }

    private:
        MinecraftGame *mMinecraftGame;
        ClientInstance *mClientInstance;
        u32 mUnk1[3];
    };
}    // namespace MC3DSPluginFramework