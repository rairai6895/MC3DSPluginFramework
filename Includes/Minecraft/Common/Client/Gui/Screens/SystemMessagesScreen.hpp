#pragma once

#include "Minecraft/Common/Client/Gui/Screens/BaseScreen.hpp"

namespace MC3DSPluginFramework
{
    class SystemMessagesScreen : public BaseScreen
    {
    public:
        static inline SystemMessagesScreen *&RunningInstance = *(SystemMessagesScreen **)0xA31AD8;

        struct Message {
            u32 mCurrentTime = 0;
            u32 mMaxTime     = 200;
            gstd::string mFake;
            gstd::string mNull;
            gstd::string mMessage;
            u16 mUnk1;
        };

        SystemMessagesScreen(MinecraftGame *minecraftGame, ClientInstance *clientInstance, u8 unknown)
        {
            reinterpret_cast<void (*)(SystemMessagesScreen *, MinecraftGame *, ClientInstance *, u8)>(0x405F7C)(this, minecraftGame, clientInstance, unknown /* 0固定？*/);
        }

        ~SystemMessagesScreen() override;

        void *operator new(size_t size) { return gstd::malloc(size); }

        // Default 3
        static void changeMax(u8 max)
        {
            *(u32 *)0x11A778 = (0xE3500000 | max);
            *(u32 *)0x11A7CC = (0xE3500000 | max);
        }

        gstd::vector<Message> &getMessages(void) { return mMessages; }

        void pushMessage(gstd::string message, bool isKey)
        {
            reinterpret_cast<void (*)(SystemMessagesScreen *, gstd::string, bool)>(0x11A680)(this, message, isKey);
        }

    private:
        gstd::vector<Message> mMessages;
    };
}    // namespace MC3DSPluginFramework