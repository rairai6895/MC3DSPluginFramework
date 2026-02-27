#pragma once

#include "Minecraft/gstd/gstd.hpp"

namespace MC3DSPluginFramework
{
    class MinecraftGame;

    // 2本目のvtable
    class Screen_UnknownClass1
    {
    public:
        // FUN_0x1CA098

        Screen_UnknownClass1() = default;

    public:
        virtual ~Screen_UnknownClass1() = default;

    private:
    };

    // 3本目のvtable
    class Screen_UnknownClass2
    {
    public:
        virtual ~Screen_UnknownClass2() = default;

        virtual void Unknown1()
        {
            return;
        }

    private:
    };

    // "C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\src\\common\\client\\gui\\screens\\BaseScreen.cpp"
    // Screen系の基盤関数を持ってる
    // 1本目のvtable
    class BaseScreen
    {
    public:
        // FUN_0x14EAD0
        BaseScreen(MinecraftGame *minecraftGame)
        {
            *(u32 *)this   = 0x994E8C;
            mMinecraftGame = minecraftGame;
        }

    public:
        virtual ~BaseScreen() = default;    // +0x0
        // deletingDestructor +0x4

        virtual void Unknown1(u32 unknown1, u32 unknown2);    // +0x8
        virtual void Unknown2(u32 unknown1, u32 unknown2);    // +0xC
        virtual void Unknown3() = delete;    // +0x10
        virtual void Unknown4() = delete;    // +0x14
        virtual void Unknown5();    // +0x18
        virtual void Unknown6();    // +0x1C
        virtual void Unknown7();    // +0x20
        virtual void Unknown8();    // +0x24

        // +0x28
        virtual void Unknown9()
        {
            return;
        }

        // +0x2C
        virtual void Unknown10()
        {
            return;
        }

        virtual void Unknown11() = delete;    // +0x30
        virtual void Unknown12() = delete;    // +0x34
        virtual void Unknown13() = 0;    // +0x38

        // +0x3C
        virtual void Unknown14()
        {
            return;
        }

        virtual void Unknown15();    // +0x40

        // +0x44
        virtual void Unknown17()
        {
            return;
        }

        // +0x48
        virtual void Unknown18()
        {
            return;
        }

        virtual void Unknown19(void *unknown);    // +0x4C

        // +0x50
        virtual void Unknown20()
        {
            return;
        }

        virtual void Unknown21() = delete;    // +0x54

        virtual void Unknown22();    // +0x58
        virtual void Unknown23();    // +0x5C
        virtual void Unknown24();    // +0x60
        virtual void Unknown25();    // +0x64

        virtual void Unknown26() = delete;    // +0x68

        virtual void Unknown27(void *unknown);    // +0x6C
        virtual void Unknown28(u8 unknown);    // +0x70
        virtual void Unknown29();    // +0x74
        virtual void Unknown30(u32 unknown);    // +0x78
        virtual void Unknown31();    // +0x7C
        virtual void Unknown32();    // +0x80

        virtual void Unknown33() = delete;    // +0x84

        virtual void Unknown34();    // +0x88
        virtual void Unknown35() = delete;    // +0x8C
        virtual void Unknown36() = delete;    // +0x90
        virtual void Unknown37();    // +0x94

        // +0x98
        virtual void Unknown38()
        {
            return;
        }

        virtual void Unknown39();    // +0x9C
        virtual bool Unknown40();    // +0xA0
        virtual bool Unknown41();    // +0xA4
        virtual bool Unknown42();    // +0xA8

        // +0xAC
        virtual bool Unknown43()
        {
            return 0;
        }

        // +0xB0
        virtual bool disablesStickInput() const
        {
            return 1;
        }

        // +0xB4
        virtual bool Unknown45()
        {
            return 0;
        }

        // +0xB8
        virtual bool Unknown46()
        {
            return 0;
        }

        // +0xBC
        virtual bool Unknown47()
        {
            return 0;
        }

        virtual void Unknown48() = delete;    // +0xC0
        virtual void Unknown49() = delete;    // +0xC4
        virtual void Unknown50() = delete;    // +0xC8

        // +0xCC
        virtual bool Unknown51()
        {
            return 0;
        }

        // +0xD0
        virtual bool enablesStickInput() const
        {
            return !this->disablesStickInput();
        }

        // +0xD4
        virtual bool Unknown53()
        {
            return 1;
        }

        virtual void Unknown54() = delete;    // +0xD8

        // +0xDC
        virtual bool Unknown55()
        {
            return 0;
        }

        virtual u32 Unknown56();    // +0xE0
        virtual u32 Unknown57();    // +0xE4

        virtual void Unknown58() = delete;    // +0xE8
        virtual void Unknown59() = delete;    // +0xEC

        // +0xF0
        virtual u32 Unknown60()
        {
            return 0xC0;
        }

        // +0xF4
        virtual gstd::string getScreenName()
        {
            return "base_screen";
        }

        virtual void Unknown62() = delete;    // +0xF8
        virtual void Unknown63() = delete;    // +0xFC
        virtual void Unknown64() = delete;    // +0x100

        // +0x104
        virtual void Unknown65()
        {
            return;
        }

        // +0x108
        virtual void Unknown66(u32 unknown1, u32 unknown2, void *unknown3, void *unknown4)
        {
            return;
        }

        // +0x10C
        virtual void Unknown67(u32 unknown)
        {
            reinterpret_cast<void (*)(BaseScreen *, u32)>(0x14E694)(this, unknown);
        }

    protected:
        MinecraftGame *mMinecraftGame;
    };

}    // namespace MC3DSPluginFramework