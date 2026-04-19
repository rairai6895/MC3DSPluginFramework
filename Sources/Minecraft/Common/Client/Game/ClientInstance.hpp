#pragma once

#include "Minecraft/Common/Util/BoxedPtr.hpp"
#include "Minecraft/Common/World/Minecraft.hpp"
#include "Minecraft/Common/World/Phys/Vec3.hpp"
#include "Minecraft/gstd/gstd.hpp"

namespace MC3DSPluginFramework
{
    class MinecraftGame;
    class ClientInputHandler;
    class Entity;
    class ScreenChooser;
    class Level;
    class ScreenStack;
    class Screen;
    class Font;
    class Options;
    class LocalPlayer;
    class TextureGroup;
    class Gui;
    class LevelRenderer;
    class SkinRepository;

    // "C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\src\\common\\client\\game\\ClientInstance.cpp"
    class ClientInstance
    {
        USE_GAME_ALLOCATOR
    public:
        MinecraftGame       *getMinecraftGame() const;
        Minecraft           &getServerData() const;
        LocalPlayer         *getPlayer() const;
        LocalPlayer         *getLocalPlayer() const;
        Level               *getLevel() const;
        ClientInputHandler  &getClientInputHandler() const;
        ScreenChooser       &getScreenChooser() const;
        ScreenStack         &getScreenStack() const;
        Screen              &getScreen() const;
        Options             &getOptions() const;
        bool                 FUN_006c734c() const;
        bool                 pushPauseScreen();
        bool                 FUN_0012aae4() const;
        bool                 FUN_006c1130() const;
        Font                &getDefaultFont() const;
        Font                &getSGAFont() const;
        Font                &getSmallFont() const;
        TextureGroup        &getTextures() const;
        void                 FUN_00251e5c();
        LevelRenderer       *getLevelRenderer() const;
        Gui                 &getGui() const;
        void                 toggleSpectator();
        ResourcePackManager &getResourcePackManager() const;
        SkinRepository      &getSkinRepository() const;
        void                 pickBlockCreative();

    private:
        u32                                         mVtable1;    // +0x0 0x9A8EE4
        u32                                         mVtable2;    // +0x4 0x9A8F10
        BoxedPtr::Weak<gstd::type_unknown<>>        m0x8;    // +0x8
        u8                                          m0x10;    // +0x10
        void                                       *m0x14;    // +0x14
        MinecraftGame                              *mMinecraftGame;    // +0x18
        gstd::unique_ptr<Minecraft>                 mServerData;    // +0x1C
        gstd::unique_ptr<gstd::type_unknown<0x234>> m0x20;    // +0x20
        gstd::unique_ptr<gstd::type_unknown<0x8>>   m0x24;    // +0x24
        void                                       *m0x28;    // +0x28  MultiPlayer?
        Entity                                     *mPlayer;    // +0x2C
        LocalPlayer                                *mLocalPlayer;    // +0x30
        gstd::unique_ptr<gstd::type_unknown<>>      m0x34;    // +0x34
        u32                                         m0x38;    // +0x38
        float                                       m0x3C;    // +0x3C
        float                                       m0x40;    // +0x40
        u32                                         m0x44;    // +0x44
        u32                                         m0x48;    // +0x48
        u8                                          m0x4C;    // +0x4C
        u32                                         m0x50;    // +0x50
        gstd::string                                m0x54;    // +0x54 empty
        u32                                         m0x58;    // +0x58 400
        u32                                         m0x5C;    // +0x5C 240
        Vec3<float>                                 m0x60;    // +0x60
        u32                                         m0x6C;    // +0x6C
    };
}    // namespace MC3DSPluginFramework