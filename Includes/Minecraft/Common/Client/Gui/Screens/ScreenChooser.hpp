#pragma once

#include "Minecraft/Common/Util/BoxedPtr.hpp"

namespace MC3DSPluginFramework
{
    class C_Screen;
    class MinecraftGame;
    class ClientInstance;

    class ScreenChooser
    {
    public:
        C_Screen *createContainerCreativeScreen(u8 startTab);
        C_Screen *createContanerInventoryScreen(bool creative, bool workbench, bool unknown);
        void _pushScreen(Util::BoxedPtr::Shared<C_Screen> screen, bool unknown);
        void openPauseMenu(void);
        void initSystemMessagesScreen(void);

    private:
        MinecraftGame *mMinecraftGame;
        ClientInstance *mClientInstance;
        u32 mUnk1[3];
    };
}    // namespace MC3DSPluginFramework