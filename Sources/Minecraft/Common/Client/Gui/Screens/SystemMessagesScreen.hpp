#pragma once

#include "Minecraft/Common/Client/Game/MinecraftGame.hpp"
#include "Minecraft/Common/Client/Gui/Screens/Screen.hpp"
#include "Minecraft/gstd/gstd.hpp"

namespace MC3DSPluginFramework
{
    class MinecraftGame;
    class ClientInstance;

    class SystemMessagesScreen : public Screen
    {
        USE_GAME_ALLOCATOR
    public:
        static inline SystemMessagesScreen *&RunningInstance = *(SystemMessagesScreen **)0xA31AD8;

        struct Message
        {
            u32          mCurrentTime = 0;
            u32          mMaxTime     = 200;
            gstd::string mFake;
            gstd::string mNull;
            gstd::string mMessage;
            u16          mUnk1;
        };

        // Default 3
        static void changeMax(u8 max)
        {
            *(u32 *)0x11A778 = (0xE3500000 | max);
            *(u32 *)0x11A7CC = (0xE3500000 | max);
        }

        gstd::vector<Message> &getMessages()
        {
            return mMessages;
        }

        void pushMessage(gstd::string message, bool islocalizeKey)
        {
            reinterpret_cast<void (*)(SystemMessagesScreen *, gstd::string, bool)>(0x11A680)(this, message, islocalizeKey);
        }

    public:
        SystemMessagesScreen(MinecraftGame *minecraftGame, ClientInstance *clientInstance);
        ~SystemMessagesScreen() override = default;

        void         Unknown13() override;
        bool         Unknown40() override;
        bool         disableCstick() override;
        bool         allowsHotbarInput() override;
        bool         Unknown44() const override;
        bool         renderBehind() override;
        gstd::string getName() override;
        void         render(int touchX, int touchY, int useScreen, float tick) override;
        void         setupComponents() override;

    private:
        // void renderMessages(int touchX, int touchY, int useScreen, float tick);

    protected:
        gctr::RecursiveLock   mMutex;
        gstd::vector<Message> mMessages;
    };
}    // namespace MC3DSPluginFramework