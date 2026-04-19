#include "Minecraft/Common/Client/Gui/Screens/SystemMessagesScreen.hpp"

namespace MC3DSPluginFramework
{

    SystemMessagesScreen::SystemMessagesScreen(MinecraftGame *minecraftGame, ClientInstance *clientInstance) :
        Screen(minecraftGame, clientInstance)
    {
        // reinterpret_cast<void (*)(SystemMessagesScreen *, MinecraftGame *, ClientInstance *, u8)>(0x405F7C)(this, minecraftGame, clientInstance, unknown /* 0固定？*/);

        SystemMessagesScreen *&s_pInstance = *(SystemMessagesScreen **)(0xA31AD4 + 4);

        if (!(s_pInstance == nullptr))
            LOG("Only one system messages screen should be loaded at a time", s_pInstance == nullptr, 0);

        s_pInstance = this;
    }

    void SystemMessagesScreen::Unknown13()
    {
        reinterpret_cast<void (*)(Screen *)>(0x405BCC)(this);
    }

    bool SystemMessagesScreen::Unknown40()
    {
        return true;
    }

    bool SystemMessagesScreen::disableCstick()
    {
        return false;
    }

    bool SystemMessagesScreen::allowsHotbarInput()
    {
        return true;
    }

    bool SystemMessagesScreen::Unknown44() const
    {
        return false;
    }

    bool SystemMessagesScreen::renderBehind()
    {
        return false;
    }

    gstd::string SystemMessagesScreen::getName()
    {
        return "system_messages_screen";
    }

    void SystemMessagesScreen::render(int touchX, int touchY, int useScreen, float tick)
    {
        if (!mMinecraftGame->isShowingScreen("hud_screen"))
            reinterpret_cast<void (*)(SystemMessagesScreen *, int, int, int, float)>(0x405DFC)(this, touchX, touchY, useScreen, tick);
    }

    void SystemMessagesScreen::setupComponents()
    {
        mWidth = *(int *)0x919FC4;
    }

}    // namespace MC3DSPluginFramework