#pragma once

#include "Minecraft/gstd/gstd.hpp"

namespace MC3DSPluginFramework
{
    class MinecraftGame;
    class PlayerController;
    class Entity;
    class ScreenChooser;
    class Level;
    class ScreenStack;
    class C_Screen;

    // "C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\src\\common\\client\\game\\ClientInstance.cpp"
    class ClientInstance
    {
    public:
        MinecraftGame *getMinecraftGame() const;
        void onTick(u32 tick, u32 maxtick);
        void *getServerData() const;
        Entity *getPlayer() const;
        Entity *getLocalPlayer() const;
        Level *getLevel() const;
        PlayerController *getController() const;
        ScreenChooser *getScreenChooser() const;
        ScreenStack *getScreenStack() const;
        C_Screen &getScreen() const;
        bool isStickInputEnabled() const;
        bool pause();

        bool FUN_0012aae4() const;

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