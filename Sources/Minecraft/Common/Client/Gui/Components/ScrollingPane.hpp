#pragma once

#include "../IntRectangle.hpp"
#include "../Screens/Screen.hpp"
#include "GuiElement.hpp"
#include "Minecraft/Common/World/Phys/Vec3.hpp"
#include "Minecraft/src-deps/Input/RectangleArea.hpp"

namespace MC3DSPluginFramework
{
    class ScrollGuiElementContainer;

    class ScrollingPane : public GuiElement
    {
        USE_GAME_ALLOCATOR
    public:
        ScrollingPane(MinecraftGame *minecraftGame, int p2, const IntRectangle &p3, const IntRectangle &p4, int p5, int p6, const IntRectangle &p7) :
            GuiElement(true, true, 0, 0, 24, 24, UseScreen::Both)
        {
            using sig = ScrollingPane *(*)(ScrollingPane *, MinecraftGame *, int, const IntRectangle &, const IntRectangle &, int, int, const IntRectangle &);
            sig(0x241668)(this, minecraftGame, p2, p3, p4, p5, p6, p7);
        }

        // FUN_0x241C98
        ~ScrollingPane() override = default;

        void Unknown2() override
        {
            reinterpret_cast<void (*)(ScrollingPane *)>(0x24148C)(this);
        }

        virtual void FUN_0023fba8(const gstd::vector<gstd::type_unknown<0x18>> &unknown1, float unknown)
        {
            for (auto &data : unknown1)
                FUN_0023f310(data);
        }

        virtual void FUN_0023f310(const gstd::type_unknown<0x18> &unknown)
        {
            return;
        }

        virtual void FUN_00240258()
        {
            return;
        }

        virtual void FUN_002409c4()
        {
            return;
        }

        virtual void FUN_002409c8()
        {
            return;
        }

        virtual void FUN_002409c0()
        {
            return;
        }

        virtual int FUN_00241588(int p1, int p2)
        {
            return p2;
        }

        virtual void FUN_0023fc30()
        {
            return;
        }

    private:
        // 0x9A7638

        MinecraftGame                     *mMinecraftGame;    // +0x38
        ScrollGuiElementContainer         *mParent;    // +0x3C
        int                                mUnk1;    // +0x40
        int                                mUnk2;    // +0x44
        int                                mUnk3;    // +0x48
        int                                mUnk4;    // +0x4C
        int                                mUnk5;    // +0x50
        int                                mUnk6;    // +0x54
        float                              mUnk7;    //+0x58
        float                              mUnk8;    //+0x5C
        float                              mUnk9;    //+0x60
        float                              mUnk10;    //+0x64
        IntRectangle                       mUnk11;    //+0x68
        IntRectangle                       mUnk12;    //+0x78
        IntRectangle                       mUnk13;    //+0x88
        RectangleArea                      mUnk14;    //+0x98
        RectangleArea                      mUnk15;    //+0xA8
        gstd::vector<gstd::type_unknown<>> mUnk16;    //+0xB8
        int                                mUnk17;    //+0xC4
        Vec3<float>                        mUnk18;    //+0xC8
        Vec3<float>                        mUnk19;    //+0xD4
        int                                mUnk20;    //+0xE0
        Vec3<float>                        mUnk21;    //+0xE4
        Vec3<float>                        mUnk22;    //+0xF0
        float                              mUnk23;    //+0xFC
        int                                mUnk24;    //+0x100
        int                                mUnk25;    //+0x104
        bool                               mUnk26;    //+0x108
        bool                               mUnk27;    //+0x109
        bool                               mUnk28;    //+0x10A
        bool                               mUnk29;    //+0x10B
        Vec3<float>                        mUnk30;    //+10C
        Vec3<float>                        mUnk31;    //+118
        int                                mUnk32;    //+0x124
        Vec3<float>                        mUnk33;    //+128
        Vec3<float>                        mUnk34;    //+134
        Vec3<float>                        mUnk35;    //+140
        int                                mUnk36;    //+0x14C
        int                                mUnk37;    //+0x150
        Vec3<float>                        mUnk38;    //+154
        Vec3<float>                        mUnk39;    //+160
        Vec3<float>                        mUnk40;    //+16C
        Vec3<float>                        mUnk41;    //+178
        int                                mUnk42;    //+0x184
        int                                mUnk43;    //+0x188
        IntRectangle                       mUnk44;    //+0x18C
        int                                mUnk45;    //+0x19C
        bool                               mUnk46;    //+0x1A0
        int                                mUnk47;    //+0x1A4
        int                                mUnk48;    //+0x1A8
        int                                mUnk49;    //+0x1AC
        int                                mUnk50;    //+0x1B0
        int                                mUnk51;    //+0x1B4
        int                                mUnk52;    //+0x1B8
        int                                mUnk53;    //+0x1BC
        int                                mUnk54;    //+0x1C0
        float                              mUnk55;    //+0x1C4
        float                              mUnk56;    //+0x1C8
        bool                               mUnk57;    //+0x1CC
        gstd::vector<bool>                 mUnk58;    //+0x1D0
        int                                mUnk59;    //+0x1E4
        int                                mUnk60;    //+0x1E8

        struct UnknownStruct
        {
            float                           mUnk1;    //+0x0
            float                           mUnk2;    //+0x4
            float                           mUnk3;    //+0x8
            float                           mUnk4;    //+0xC
            float                           mUnk5;    //+0x10
            float                           mUnk6;    //+0x14
            int                             mUnk7;    //+0x18
            float                           mUnk8;    //+0x1C
            float                           mUnk9;    //+0x20
            float                           mUnk10;    //+0x24
            bool                            mUnk11;    //+0x28
            bool                            mUnk12;    //+0x29
            GuiElement                     *mUnk13;    //+0x2C
            RectangleArea                   mUnk14;    //+0x30
            BoxedPtr::Shared<UnknownStruct> mUnk15;    //+0x40
            BoxedPtr::Shared<UnknownStruct> mUnk16;    //+0x48
        };

        UnknownStruct mUnk61;    //+0x1EC
        UnknownStruct mUnk62;    //+0x23C

        char todo[76];
    };
}    // namespace MC3DSPluginFramework