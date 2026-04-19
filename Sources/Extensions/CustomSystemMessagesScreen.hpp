#pragma once

#include "Api/Facade.hpp"
#include "Minecraft/Common/Client/Game/MinecraftGame.hpp"
#include "Minecraft/Common/Client/Gui/Components/BaseButton.hpp"
#include "Minecraft/Common/Client/Gui/Screens/SystemMessagesScreen.hpp"
#include "Minecraft/Common/Util/StringUtils.hpp"
#include "Minecraft/Common/World/Level/Level.hpp"
#include "Minecraft/gstd/gstd.hpp"

namespace MC3DSPluginFramework
{

    class MinecraftGame;
    class ClientInstance;

    class CustomSystemMessagesScreen : public SystemMessagesScreen
    {
    public:
        CustomSystemMessagesScreen(MinecraftGame *minecraftGame, ClientInstance *clientInstance) :
            SystemMessagesScreen(minecraftGame, clientInstance) {}

        void render(int touchX, int touchY, int useScreen, float tick) override
        {
            if (useScreen & UseScreen::Top)
            {
                mMutex.lock();

                int y = 216;

                for (auto &msg : mMessages)
                {
                    int h = mFont->getTextHeight(msg.mMessage, mWidth - 2, 0);
                    y     = y - h - 1;
                    int w = mFont->getTextWidth(msg.mMessage, 0, 1);
                    GuiComponent::fill(0, y - 5, w + 5, y + h - 5, Color(0, 0, 0, 0.3f));
                    reinterpret_cast<void (*)(Font *, gstd::string, const Color &, int, u8 *, int, int, float, float)>(0x55BC6C)(mFont, msg.mMessage, Color(1, 0, 0), 1, nullptr, 0, 0, 2, y);
                }

                mMutex.unlock();

                drawOverlay();
            }
        }

    private:
        void drawOverlay()
        {
            int          tick       = Facade::getLocalPlayer()->getLevel().getTime();
            int          ticksInDay = (tick + 6000) % 24000;
            int          seconds    = (ticksInDay * 86400) / 24000;
            int          hour       = seconds / 3600;
            int          minute     = (seconds % 3600) / 60;
            int          second     = seconds % 60;
            gstd::string str        = Util::format("%02d:%02d:%02d", hour, minute, second);
            int          w          = mFont->getTextWidth(str, 0, 1);
            GuiComponent::fill(0, 0, w + 10, 15, Color(0, 0, 0, 0.3f));
            mFont->drawWithShadow(2, 5, 5, str, Color(1, 1, 1), 0, -1);
        }
    };
}    // namespace MC3DSPluginFramework