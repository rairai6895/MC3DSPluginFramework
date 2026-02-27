#pragma once

#include "Minecraft/Common/Client/Gui/Screens/BaseScreen.hpp"
#include "Minecraft/Common/Logger.hpp"
#include "Minecraft/Common/Util/Util.hpp"

namespace MC3DSPluginFramework
{

    class ClientInstance;

    // Screenのオリジナル仮想関数はBaseScreenのvtableに追加されていく
    // Screenの一本目のvtableがBaseScreenのより大きかったのでほぼ確定
    class C_Screen : public BaseScreen, public Screen_UnknownClass1, public Screen_UnknownClass2
    {
    public:
        C_Screen(MinecraftGame *minecraftGame, ClientInstance *clientInstance, u8 unknown /* 使ってないかも */) :
            BaseScreen(minecraftGame)
        {
            reinterpret_cast<C_Screen *(*)(C_Screen *, MinecraftGame *, ClientInstance *, u8)>(0x621070)(this, minecraftGame, clientInstance, unknown);
        }

    public:
        ~C_Screen() override;

        void Unknown1(u32 unknown1, u32 unknown2) override
        {
            reinterpret_cast<void (*)(C_Screen *, u32, u32)>(0x620D24)(this, unknown1, unknown2);
        }

        void Unknown2(u32 unknown1, u32 unknown2) override
        {
            reinterpret_cast<void (*)(C_Screen *, u32, u32)>(0x620F14)(this, unknown1, unknown2);
        }

        void Unknown5() override
        {
            return;
        }

        void Unknown6() override
        {
            return;
        }

        void Unknown7() override
        {
            reinterpret_cast<void (*)(C_Screen *)>(0x61F198)(this);
        }

        void Unknown8() override
        {
            return;
        }

        void Unknown13() override
        {
            return;
        }

        void Unknown14() override
        {
            reinterpret_cast<void (*)(C_Screen *)>(0x620CC8)(this);
        }

        void Unknown15() override
        {
            reinterpret_cast<void (*)(C_Screen *)>(0x61F24C)(this);
        }

        void Unknown19(void *unknown) override
        {
            reinterpret_cast<void (*)(C_Screen *, void *)>(0x620DDC)(this, unknown);
        }

        void Unknown22() override
        {
            return;
        }

        void Unknown23() override
        {
            return;
        }

        void Unknown24() override
        {
            reinterpret_cast<void (*)(C_Screen *)>(0x61FD10)(this);
        }

        void Unknown25() override
        {
            reinterpret_cast<void (*)(C_Screen *)>(0x620510)(this);
        }

        void Unknown27(void *unknown) override
        {
            reinterpret_cast<void (*)(C_Screen *, void *)>(0x620830)(this, unknown);
        }

        void Unknown28(u8 unknown) override
        {
            reinterpret_cast<void (*)(C_Screen *, u8)>(0x62073C)(this, unknown);
        }

        void Unknown29() override
        {
            reinterpret_cast<void (*)(C_Screen *)>(0x61F69C)(this);
        }

        void Unknown30(u32 unknown) override
        {
            reinterpret_cast<void (*)(C_Screen *, u32)>(0x61F5C8)(this, unknown);
        }

        void Unknown31() override
        {
            reinterpret_cast<void (*)(C_Screen *)>(0x61F2F4)(this);
        }

        void Unknown32() override
        {
            reinterpret_cast<void (*)(C_Screen *)>(0x620520)(this);
        }

        void Unknown34() override
        {
            return;
        }

        void Unknown37() override
        {
            reinterpret_cast<void (*)(C_Screen *)>(0x620A14)(this);
        }

        void Unknown39() override
        {
            return;
        }

        // +0xA0
        bool Unknown40() override
        {
            return reinterpret_cast<bool (*)(C_Screen *)>(0x729664)(this);
        }

        bool Unknown41() override
        {
            return 1;
        }

        bool Unknown42() override
        {
            return 0;
        }

        u32 Unknown56() override
        {
            return mScreenSize_X;
        }

        u32 Unknown57() override
        {
            return mScreenSize_Y;
        }

        gstd::string getScreenName() override
        {
            return "screen";
        }

        // +0x108
        void Unknown66(u32 unknown1, u32 unknown2, void *unknown3, void *unknown4) override
        {
            reinterpret_cast<void (*)(C_Screen *, u32, u32, void *, void *)>(0x61F6A8)(this, unknown1, unknown2, unknown3, unknown4);
        }

        // Screenの仮想関数

        // +0x110
        virtual void Unknown68(u32 unknown1, u32 unknown2, u32 unknown3, float unknown4)
        {
            reinterpret_cast<void (*)(C_Screen *, u32, u32, u32, float)>(0x620E94)(this, unknown1, unknown2, unknown3, unknown4);
        }

        // +0x114
        virtual void Unknown69()
        {
            return;
        }

        // +0x118
        virtual void Unknown70()
        {
            reinterpret_cast<void (*)(C_Screen *)>(0x61F30C)(this);
        }

        // +0x11C
        virtual void Unknown71()
        {
            reinterpret_cast<void (*)(C_Screen *)>(0x62066C)(this);
        }

        // +0x120
        virtual void Unknown72()
        {
            reinterpret_cast<void (*)(C_Screen *)>(0x620B94)(this);
        }

        // +0x124
        virtual void Unknown73(u32 unknown)
        {
            reinterpret_cast<void (*)(C_Screen *, u32)>(0x61FA2C)(this, unknown);
        }

        // +0x128
        virtual void Unknown74(u32 unknown1, u32 unknown2)
        {
            reinterpret_cast<void (*)(C_Screen *, u32, u32)>(0x61FE40)(this, unknown1, unknown2);
        }

        // +0x12C
        virtual void Unknown75(u32 unknown1)
        {
            reinterpret_cast<void (*)(C_Screen *, u32)>(0x620744)(this, unknown1);
        }

        // +0x130
        virtual void Unknown76(u32 unknown1, u32 unknown2)
        {
            reinterpret_cast<void (*)(C_Screen *, u32, u32)>(0x620794)(this, unknown1, unknown2);
        }

        // +0x134
        virtual void Unknown77() = delete;

        // +0x138
        virtual void Unknown78()
        {
            return;
        }

        // +0x13C
        virtual void Unknown79()
        {
            reinterpret_cast<void (*)(C_Screen *)>(0x620850)(this);
        }

        // +0x140
        virtual void Unknown80() = delete;

        // +0x144
        virtual void Unknown81()
        {
            return;
        }

        // +0x148
        virtual void Unknown82(u32 unknown)
        {
            reinterpret_cast<void (*)(C_Screen *, u32)>(0x61FFD4)(this, unknown);
        }

        // +0x14C
        virtual void Unknown83(u32 unknown1, u32 unknown2)
        {
            reinterpret_cast<void (*)(C_Screen *, u32, u32)>(0x61F284)(this, unknown1, unknown2);
        }

        // +0x150
        virtual void Unknown84()
        {
            return;
        }

        // +0x154
        virtual void Unknown85(u32 unknown1, u32 unknown2)
        {
            reinterpret_cast<void (*)(C_Screen *, u32, u32)>(0x19C05C)(this, unknown1, unknown2);
        }

        // +0x158
        virtual void Unknown86(float unknown1, float unknown2, int unknown3)
        {
            reinterpret_cast<void (*)(C_Screen *, float, float, int)>(0x61F62C)(this, unknown1, unknown2, unknown3);
        }

        // +0x15C
        virtual void Unknown87()
        {
            return;
        }

        // +0x160
        virtual void Unknown88()
        {
            return;
        }

        // +0x164
        virtual void Unknown89()
        {
            return;
        }

        // +0x168
        virtual void Unknown90(u32 unknown1, u32 unknown2)
        {
            reinterpret_cast<void (*)(C_Screen *, u32, u32)>(0x61ECD0)(this, unknown1, unknown2);
        }

        // +0x16C
        virtual void Unknown91(u32 unknown1, u32 unknown2)
        {
            reinterpret_cast<void (*)(C_Screen *, u32, u32)>(0x61FB14)(this, unknown1, unknown2);
        }

        // +0x170
        virtual void Unknown92(int unknown1, int unknown2, bool unknown3)
        {
            reinterpret_cast<void (*)(C_Screen *, int, int, bool)>(0x6205E8)(this, unknown1, unknown2, unknown3);
        }

        // +0x174
        virtual void Unknown93()
        {
            reinterpret_cast<void (*)(C_Screen *)>(0x620A74)(this);
        }

        // +0x178
        virtual void Unknown94(int unknown1, int unknown2, int unknown3)
        {
            reinterpret_cast<void (*)(C_Screen *, int, int, int)>(0x61FC74)(this, unknown1, unknown2, unknown3);
        }

        // +0x17C
        virtual void Unknown95(Util::BoxedPtr::Shared<void *> unknown1, int unknown2, int unknown3)
        {
            reinterpret_cast<void (*)(C_Screen *, Util::BoxedPtr::Shared<void *>, int, int)>(0x61FD30)(this, unknown1, unknown2, unknown3);
        }

        // +0x180
        virtual void Unknown96()
        {
            return;
        }

        // +0x184
        virtual void Unknown97(u32 unknown1, u32 unknown2)
        {
            reinterpret_cast<void (*)(C_Screen *, u32, u32)>(0x61F34C)(this, unknown1, unknown2);
        }

        // +0x188
        virtual void Unknown98(u32 unknown1, u32 unknown2)
        {
            reinterpret_cast<void (*)(C_Screen *, u32, u32)>(0x61F6F8)(this, unknown1, unknown2);
        }

        // +0x18C
        virtual void Unknown99(int unknown1, int unknown2)
        {
            reinterpret_cast<void (*)(C_Screen *, int, int)>(0x620B34)(this, unknown1, unknown2);
        }

        // +0x190
        virtual void Unknown100(int unknown1, int unknown2)
        {
            reinterpret_cast<void (*)(C_Screen *, int, int)>(0x620A24)(this, unknown1, unknown2);
        }

        // +0x194
        virtual void Unknown101()
        {
            reinterpret_cast<void (*)(C_Screen *)>(0x620F28)(this);
        }

        // +0x198
        virtual void Unknown102()
        {
            reinterpret_cast<void (*)(C_Screen *)>(0x620FC4)(this);
        }

        // +0x19C
        virtual void Unknown103(int unknown1, int unknown2)
        {
            reinterpret_cast<void (*)(C_Screen *, int, int)>(0x61EE5C)(this, unknown1, unknown2);
        }

    protected:
        // 0x9CC9F4

        u32 mScreenSize_X;
        u32 mScreenSize_Y;
        ClientInstance *mClientInstance;
        gstd::vector<Util::BoxedPtr::Shared<u32>> mUnk1;
        u32 mUnk2;
        u32 mUnk3;
        u32 mUnk4;
        u32 mUnk5;
        u32 mUnk6;
        u32 mUnk7;
        u32 mUnk8;
        u32 mUnk9;
        u32 mUnk10;
        u32 mUnk11;
        u32 mUnk12;
        u32 mUnk13;

        u32 mUnk14;    // 0xFFFFFFFF
        u32 mUnk15;    // 0xFFFFFFFF
        void *mUnk16;
        void *mUnk17;    // Fonts?
        u32 mUnk18;
        u32 mUnk19;
        u32 mUnk20;
        gstd::map<u32, u32> mUnk21;
    };
}    // namespace MC3DSPluginFramework