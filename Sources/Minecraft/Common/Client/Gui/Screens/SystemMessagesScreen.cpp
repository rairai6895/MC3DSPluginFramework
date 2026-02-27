#include "Minecraft/Common/Client/Gui/Screens/SystemMessagesScreen.hpp"

namespace MC3DSPluginFramework
{

    void SystemMessagesScreen::Unknown13()
    {
        reinterpret_cast<void (*)(C_Screen *)>(0x405BCC)(this);
    }

    bool SystemMessagesScreen::Unknown40()
    {
        return 1;
    }

    bool SystemMessagesScreen::Unknown41()
    {
        return 0;
    }

    bool SystemMessagesScreen::Unknown43()
    {
        return 1;
    }

    bool SystemMessagesScreen::disablesStickInput() const
    {
        return 0;
    }

    bool SystemMessagesScreen::Unknown53()
    {
        return 0;
    }

    gstd::string SystemMessagesScreen::getScreenName()
    {
        return "system_messages_screen";
    }

    void SystemMessagesScreen::Unknown68(u32 unknown1, u32 unknown2, u32 unknown3, float unknown4)
    {
        // おそらくメッセージ描画

        if (!mMinecraftGame->isShowingScreen("hud_screen"))
            reinterpret_cast<void (*)(SystemMessagesScreen *, u32, u32, u32, float)>(0x405DFC)(this, unknown1, unknown2, unknown3, unknown4);
    }

    void SystemMessagesScreen::Unknown69()
    {
        mScreenSize_X = *(u32 *)0x919FC4;
    }

}    // namespace MC3DSPluginFramework