#pragma once

#include "Minecraft/Common/Client/Options/Options.hpp"
#include "Minecraft/Common/Platform/App.hpp"
#include "Minecraft/Common/Util/BoxedPtr.hpp"
#include "UserManager.hpp"

namespace MC3DSPluginFramework
{
    class ClientInstance;
    class Level;
    class Entity;
    class ScreenStack;
    class ScreenChooser;
    class Screen;
    class Dimension;
    class BlockPos;
    class BaseScreen;
    class Font;
    class ClientInputHandler;
    class ResourcePackManager;
    class ResourcePackRepository;
    class UserManager;
    class Options;
    class LocalPlayer;
    class GeometryGroup;
    class SkinRepository;
    class SkinGeometryGroup;
    class TextureGroup;
    class SoundEngine;
    class GameRenderer;
    class LevelRenderer;
    class Gui;
    class MinecraftEventing;
    class Minecraft;

    using ClientInstances = gstd::vector<gstd::unique_ptr<ClientInstance>>;

    // "C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\src\\common\\client\\game\\MinecraftGame.cpp"
    class MinecraftGame : public App
    {
        USE_GAME_ALLOCATOR
    public:
        ~MinecraftGame() override;

        u32 offset(u32 offset = 0) const
        {
            return (u32)this + offset;
        }

        void                    onAppResumed();
        void                    _setupLevelRendering(Level *level, LocalPlayer *player);
        void                    pushScreen(BoxedPtr::Shared<Screen> newScreen);
        bool                    isShowingScreen(gstd::string screen) const;
        ScreenStack            &getScreenStack() const;
        ClientInstances        &getClientInstances();
        ClientInstance         &getClientInstance() const;
        LocalPlayer            *getPlayer();
        SkinRepository         &getSkinRepository() const;
        ResourcePackRepository &getResourcePackRepository() const;
        ResourcePackManager    &getResourcePackManager() const;
        GeometryGroup          &getGeometryGroup() const;
        SkinGeometryGroup      &getSkinGeometryGroup() const;
        UserManager            &getUserManager() const;
        void                   *getMultiPlayer() const;
        ScreenChooser          &getScreenChooser() const;
        Screen                 &getScreen() const;
        Font                   &getDefaultFont() const;
        Font                   &getSGAFont() const;
        Font                   &getSmallFont() const;
        ClientInputHandler     &getClientInputHandler() const;
        Options                &getOptions() const;
        void                    schedulePopScreen(int popCount);
        TextureGroup           &getTextures() const;
        LevelRenderer          *getLevelRenderer() const;
        void                    playSound(u32 hashId, float volume, float pitch);
        Gui                    &getGui() const;
        Minecraft              &getServerData() const;

    private:
        // 0x9A6644

        u32                                                   vtable2;    // +0x10 0x9A66E4
        u32                                                   vtable3;    // +0x14 0x9A670C
        u32                                                   mUnk4;    // +0x18 0x736B6360
        u32                                                   mUnk5;    // +0x1C 0
        u32                                                   vtable4;    // +0x20 0x9A6744 LevelListener
        u32                                                   vtable5;    // +0x24 0x9A67BC
        u32                                                   mUnk6;    // +0x28 0x400
        u32                                                   mUnk7;    // +0x2C 0
        u32                                                   mUnk8;    // +0x30 0
        u32                                                   mUnk9;    // +0x34 0
        gstd::string                                          mUnk10;    // +0x38 serviceconfig.json
        u32                                                   mWidth;    // +0x3C 0x190
        u32                                                   mHeight;    // +0x40 0xF0
        u32                                                   mUnk13;    // +0x44 0
        gstd::unique_ptr<gstd::type_unknown<0x8>>             mUnk14;    // +0x48 { vtable(0x9A4CFC), MinecraftGame* }
        gstd::unique_ptr<LevelRenderer>                       mLevelRenderer;    // +0x4C
        gstd::unique_ptr<GameRenderer>                        mGameRenderer;    // +0x50
        void                                                 *mUnk16;    // +0x54
        gstd::unique_ptr<TextureGroup>                        mTextures;    // +0x58
        gstd::unique_ptr<Font>                                mDefaultFont;    // +0x5C
        gstd::unique_ptr<Font>                                mSGAFont;    // +0x60
        gstd::unique_ptr<Font>                                mSmallFont;    // +0x64
        void                                                 *mUnk20;    // +0x68 { vtable(0x9C4F24) }
        gstd::unique_ptr<ScreenStack>                         mScreenStack;    // +0x6C
        u8                                                    mUnk21;    // +0x70 1
        gstd::unique_ptr<gstd::type_unknown<0x7C>>            mUnk22;    // +0x74
        gstd::unique_ptr<gstd::type_unknown<0x14>>            mUnk23;    // +0x78
        void                                                 *mUnk24;    // +0x7C
        u8                                                    mUnk25;    // +0x80  0
        gstd::map<gstd::type_unknown<>, gstd::type_unknown<>> mUnk26;    // 空
        gstd::map<gstd::type_unknown<>, gstd::type_unknown<>> mUnk27;    // 空
        gstd::unique_ptr<gstd::type_unknown<>>                mUnk28;    // +0xBC
        ClientInstances                                       mClientInstances;    // +0xC0
        u32                                                   mUnk30;    // +0xCC
        gstd::unique_ptr<ClientInputHandler>                  mClientInputHandler;    // +0xD0
        gstd::unique_ptr<Gui>                                 mGui;    // +0xD4
        void                                                 *mUnk32;    // +0xD8
        gstd::unique_ptr<SoundEngine>                         mSoundEngine;    // +0xDC
        void                                                 *mUnk34;    // +0xE0
        gstd::unique_ptr<gstd::type_unknown<0x40>>            mUnk35;    // +0xE4
        gstd::unique_ptr<gstd::type_unknown<0x30>>            mUnk36;    // +0xE8
        u32                                                   mUnk37;    // +0xEC 0
        u32                                                   mUnk38;    // +0xF0 0
        gstd::unique_ptr<SkinRepository>                      mSkinRepository;    // +0xF4
        void                                                 *mUnk39;    // +0xF8
        u32                                                   mUnk40;    // +0xFC 0
        gstd::unique_ptr<ResourcePackRepository>              mResourcePackRepository;    // +0x100
        gstd::unique_ptr<ResourcePackManager>                 mResourcePackManager;    // +0x104
        void                                                 *mUnk41;    // +0x108
        gstd::unique_ptr<GeometryGroup>                       mGeometryGroup;    // +0x10C
        gstd::unique_ptr<SkinGeometryGroup>                   mSkinGeometryGroup;    // +0x110
        gstd::unique_ptr<UserManager>                         mUserManager;    // +0x114
        gstd::unique_ptr<gstd::type_unknown<>>                mMultiplayer;    // +0x118
        void                                                 *mUnk42;    // +0x11C { vtable(0x9DAE54), void* }
        void                                                 *mUnk43;    // +0x120 { vtable(0x9DAE68), void*}
        u32                                                   mUnk44;    // +0x124 0
        u32                                                   mUnk45;    // +0x128 0
        u32                                                   mUnk46;    // +0x12C 0
        u32                                                   mUnk47;    // +0x130 0
        u32                                                   mUnk48;    // +0x134 0
        BoxedPtr::Shared<gstd::type_unknown<>>                mUnk50;    // +0x138
        BoxedPtr::Shared<gstd::type_unknown<>>                mUnk51;    // +0x140
        gstd::unique_ptr<ScreenChooser>                       mScreenChooser;    // +0x148
        gstd::unique_ptr<gstd::type_unknown<>>                mUnk52;    // +0x14C 0
        u32                                                   mUnk53;    // +0x150 0
        gstd::unique_ptr<gstd::type_unknown<>>                mUnk54;    // +0x154
        u32                                                   mUnk55;    // +0x158 0
        u8                                                    mUnk56;    // +0x15C
        void                                                 *mUnk57;    // +0x160 { float(2.75), float(0.3636) }
        u32                                                   mUnk58;    // +0x164 0x72757478
        u32                                                   mUnk59;    // +0x168 0
        u32                                                   mUnk60;    // +0x16C 0
        u32                                                   mUnk61;    // +0x170 0
        u32                                                   mUnk62;    // +0x174 0
        u32                                                   mUnk63;    // +0x178 0x0A007400
        u32                                                   mUnk64;    // +0x17C 0
        gstd::string                                          mUnk65;    // +0x180
        gstd::string                                          mUnk66;    // +0x184
        u32                                                   mUnk67;    // +0x188 0x61000000
        u32                                                   mUnk68;    // +0x18C 0xFFFFFFFF
        u32                                                   mUnk69;    // +0x190 0xFFFFFFFF
        u8                                                    mUnk70;    // +0x194
        gstd::string                                          mUnk71;    // +0x198
        u16                                                   mUnk72;    // +0x19C
        gstd::unique_ptr<MinecraftEventing>                   mMinecraftEventing;    // +0x1A0

        // ...
    };
}    // namespace MC3DSPluginFramework