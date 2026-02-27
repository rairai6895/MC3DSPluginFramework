#pragma once

#include "Minecraft/Common/Client/Game/MinecraftGame.hpp"
#include "Minecraft/Common/Client/Gui/Screens/C_Screen.hpp"
#include "Minecraft/gstd/gstd.hpp"

namespace MC3DSPluginFramework
{
    class MinecraftGame;
    class ClientInstance;

    class SystemMessagesScreen : public C_Screen
    {
    public:
        static inline SystemMessagesScreen *&RunningInstance = *(SystemMessagesScreen **)0xA31AD8;

        struct Message
        {
            u32 mCurrentTime = 0;
            u32 mMaxTime     = 200;
            gstd::string mFake;
            gstd::string mNull;
            gstd::string mMessage;
            u16 mUnk1;
        };

        SystemMessagesScreen(MinecraftGame *minecraftGame, ClientInstance *clientInstance, u8 unknown) :
            C_Screen(minecraftGame, clientInstance, unknown)
        {
            // reinterpret_cast<void (*)(SystemMessagesScreen *, MinecraftGame *, ClientInstance *, u8)>(0x405F7C)(this, minecraftGame, clientInstance, unknown /* 0固定？*/);

            SystemMessagesScreen *&s_pInstance = *(SystemMessagesScreen **)(0xA31AD4 + 4);

            if (!(s_pInstance == nullptr))
                LOG("Only one system messages screen should be loaded at a time", s_pInstance == nullptr, 0);

            s_pInstance = this;
        }

        void *operator new(size_t s)
        {
            return gstd::malloc(s);
        }

        void *operator new(size_t s, void *p) noexcept
        {
            return p;
        }

        // Default 3
        static void changeMax(u8 max)
        {
            *(u32 *)0x11A778 = (0xE3500000 | max);
            *(u32 *)0x11A7CC = (0xE3500000 | max);
        }

        gstd::vector<Message> &getMessages(void)
        {
            return mMessages;
        }

        void pushMessage(gstd::string message, bool isKey)
        {
            reinterpret_cast<void (*)(SystemMessagesScreen *, gstd::string, bool)>(0x11A680)(this, message, isKey);
        }

    public:
        ~SystemMessagesScreen() override = default;

        void Unknown13() override;
        bool Unknown40() override;
        bool Unknown41() override;
        bool Unknown43() override;
        bool disablesStickInput() const override;
        bool Unknown53() override;
        gstd::string getScreenName() override;
        void Unknown68(u32 unknown1, u32 unknown2, u32 unknown3, float unknown4) override;
        void Unknown69() override;

    private:
        gctr::RecursiveLock mMutex;
        gstd::vector<Message> mMessages;
    };
}    // namespace MC3DSPluginFramework