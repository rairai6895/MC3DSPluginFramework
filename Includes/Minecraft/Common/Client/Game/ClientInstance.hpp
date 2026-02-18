#pragma once

#include "Minecraft/Common/Client/Game/MinecraftGame.hpp"
#include "Minecraft/Common/Client/Gui/Screens/ScreenChooser.hpp"
#include "Minecraft/Common/World/Level/Level.hpp"
#include "Minecraft/Other/PlayerController.hpp"

namespace MC3DSPluginFramework
{
    class MinecraftGame;
    class PlayerController;
    class ScreenChooser;

    // "C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\src\\common\\client\\game\\ClientInstance.cpp"
    class ClientInstance
    {
    public:
        MinecraftGame *getMinecraftGame(void) const { return mMinecraftGame; }

        void onTick(u32 tick, u32 maxtick)
        {
            reinterpret_cast<void (*)(ClientInstance *, u32, u32)>(0x2520FC)(this, tick, maxtick);
        }

        void *getServerData(void)
        {
            return mServerData;

            // FUN_0x124DD0 getLevel
        }

        Entity *getPlayer(void) const;

        Entity *getLocalPlayer(void) const { return mLocalPlayer; }

        Level *getLevel(void) const
        {
            return reinterpret_cast<Level *(*)(const ClientInstance *)>(0x124DC8)(this);
        }

        PlayerController *getController(void) const
        {
            return reinterpret_cast<PlayerController *(*)(const ClientInstance *)>(0x12AAD4)(this);
        }

        ScreenChooser *getScreenChooser(void) const;

        bool isPaused(void) const
        {
            return !reinterpret_cast<bool (*)(const ClientInstance *)>(0x6C734C)(this);
        }

        void pause(void);

    private:
        u32 mVtable1;    // +0x0 0x9A8EE4
        u32 mVtable2;    // +0x4 0x9A8F10
        u32 mUnk1;    // +0x8 0
        u32 mUnk2;    // +0xC 0
        bool mUnk3;    // +0x10 0
        void *mUnk6;    // +0x14
        MinecraftGame *mMinecraftGame;    // +0x18
        void *mServerData;    // +0x1C
        void *mUnk7;    // +0x20
        void *mUnk8;    // +0x24
        void *mUnk9;    // +0x28  MultiPlayer?
        Entity *mPlayer;    // +0x2C  読み取り専用？
        Entity *mLocalPlayer;    // +0x30
        u32 mUnk10;
        u32 mUnk11;
        float mUnk12;
        float mUnk13;
        u32 mUnk14;
        u32 mUnk15;
        u32 mUnk16;
        u32 mUnk17;
        gstd::string mUnk18;    // empty
        u32 mUnk19;    // 400
        u32 mUnk20;    // 240
        float mUnk21;
        float mUnk22;
        u32 mUnk23;
        u32 mUnk24;
    };
}    // namespace MC3DSPluginFramework