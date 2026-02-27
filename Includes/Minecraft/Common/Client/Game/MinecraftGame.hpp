#pragma once

#include "Minecraft/Common/Util/BoxedPtr.hpp"

namespace MC3DSPluginFramework
{
    class ClientInstance;
    class Level;
    class Entity;
    class ScreenStack;
    class ScreenChooser;
    class C_Screen;
    class Dimension;
    class BlockPos;
    class BaseScreen;

    // "C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\src\\common\\client\\game\\MinecraftGame.cpp"
    class MinecraftGame
    {
    public:
        static inline bool InitializedNbtTags;

        virtual ~MinecraftGame();

        u32 offset(u32 offset = 0) const
        {
            return (u32)this + offset;
        }

        void operator()()
        {
        }

        void onAppResumed(void);
        void _setupLevelRendering(Level *level, Entity *player);
        void pushScreen(Util::BoxedPtr::Shared<C_Screen> screen, bool unknown);
        bool isShowingScreen(gstd::string screen) const;
        ScreenStack *getScreenStack(void) const;
        gstd::vector<ClientInstance *> &getClientInstances();
        Entity *getPlayer();
        void *getSkinRepository() const;
        void *getResourcePackRepository() const;
        void *getResourcePackManager() const;
        void *getSkinGeometryGroup() const;
        void *getUserManager() const;
        void *getMultiPlayer() const;
        ScreenChooser *getScreenChooser() const;
        C_Screen &getScreen() const;

    private:
        // vtable = 0x9A6644

        void *mUnk1;
        u16 mUnk2;    // 1
        u32 mUnk3;    // 0x0FFFFFB8
        u32 vtable2;    // 0x9A66E4 オブジェクトとして持ってる？
        u32 vtable3;    // 0x9A670C
        u32 mUnk4;    // 0x736B6360
        u32 mUnk5;    // 0
        u32 vtable4;    // 0x9A6644 オブジェクトとして持ってる？
        u32 vtable5;    // 0x9A67BC
        u32 mUnk6;    // 0x400
        u32 mUnk7;    // 0
        u32 mUnk8;    // 0
        u32 mUnk9;    // 0
        gstd::string mUnk10;    // serviceconfig.json
        u32 mUnk11;    // 0x190
        u32 mUnk12;    // 0xF0
        u32 mUnk13;    // 0
        void *mUnk14;    // { vtable(0x9A4CFC), MinecraftGame* }
        void *mLevelRenderer;    // +0x4C  (mTextures持ってる)
        void *mUnk15;    // +0x50
        void *mUnk16;    // +0x54
        gstd::map<gstd::string, void *> *mTextures;    // +0x58

        // 同じ型かも
        void *mUnk17;    // +0x5C
        void *mUnk18;    // +0x60
        void *mUnk19;    // +0x64

        void *mUnk20;    // +0x68 { vtable(0x9C4F24) }
        ScreenStack *mScreenStack;    // +0x6C
        u8 mUnk21;    // +0x70 1
        void *mUnk22;    // +0x74
        void *mUnk23;    // +0x78
        void *mUnk24;    // +0x7C
        u8 mUnk25;    // +0x80  0
        gstd::map<void *, void *> mUnk26;    // 空
        gstd::map<void *, void *> mUnk27;    // 空
        u32 mUnk28;    // +0xBC
        gstd::vector<ClientInstance *> mUnk29;    // +0xC0
        u32 mUnk30;    // +0xCC
        void *mController;    // +0xD0
        void *mUnk31;    // +0xD4
        void *mUnk32;    // +0xD8
        void *mUnk33;    // +0xDC
        void *mUnk34;    // +0xE0
        void *mUnk35;    // +0xE4
        void *mUnk36;    // +0xE8
        u32 mUnk37;    // +0xEC 0
        u32 mUnk38;    // +0xF0 0
        void *mSkinRepository;    // +0xF4
        void *mUnk39;    // +0xF8
        u32 mUnk40;    // +0xFC 0
        void *mResourcePackRepository;    // +0x100
        void *mResourcePackManager;    // +0x104
        void *mUnk41;    // +0x108
        void *mGeometryGroup;    // +0x10C
        void *mSkinGeometryGroup;    // +0x110
        void *mUserManager;    // +0x114
        void *mMultiplayer;    // +0x118
        void *mUnk42;    // +0x11C { vtable(0x9DAE54), void* }
        void *mUnk43;    // +0x120 { vtable(0x9DAE68), void*}
        u32 mUnk44;    // +0x124 0
        u32 mUnk45;    // +0x128 0
        u32 mUnk46;    // +0x12C 0
        u32 mUnk47;    // +0x130 0
        u32 mUnk48;    // +0x134 0
        Util::BoxedPtr::Shared<void *> mUnk50;    // +0x138
        Util::BoxedPtr::Shared<void *> mUnk51;    // +0x140
        ScreenChooser *mScreenChooser;    // +0x148
        u32 mUnk52;    // +0x14C 0
        u32 mUnk53;    // +0x150 0
        void *mUnk54;    // +0x154
        u32 mUnk55;    // +0x158 0
        u8 mUnk56;    // +0x15C
        void *mUnk57;    // +0x160 { float(2.75), float(0.3636) }
        u32 mUnk58;    // +0x164 0x72757478
        u32 mUnk59;    // +0x168 0
        u32 mUnk60;    // +0x16C 0
        u32 mUnk61;    // +0x170 0
        u32 mUnk62;    // +0x174 0
        u32 mUnk63;    // +0x178 0x0A007400
        u32 mUnk64;    // +0x17C 0
        gstd::string mUnk65;    // +0x180
        gstd::string mUnk66;    // +0x184
        u32 mUnk67;    // +0x188 0x61000000
        u32 mUnk68;    // +0x18C 0xFFFFFFFF
        u32 mUnk69;    // +0x190 0xFFFFFFFF
        u8 mUnk70;    // +0x194
        gstd::string mUnk71;    // +0x198
        // ...
    };
}    // namespace MC3DSPluginFramework