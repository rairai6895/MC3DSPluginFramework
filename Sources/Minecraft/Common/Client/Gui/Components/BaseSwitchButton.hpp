#pragma once

#include "../IntRectangle.hpp"
#include "BaseButton.hpp"
#include "Minecraft/src-deps/Renderer/TexturePtr.hpp"

namespace MC3DSPluginFramework
{
    struct BaseSwitchButton_UnknownStruct
    {
        TexturePtr   mTexturePtr;    //+0x0
        int          mUnk2 = 0;    // +0x20
        int          mUnk3 = 0;    // +0x24
        float        mUnk4 = 16.f;    // +0x28
        float        mUnk5 = 16.f;    // +0x2C
        IntRectangle mUnk6;    // +0x30 uv?
        u8           mUnk7 = 0;    //+0x40
    };

    class BaseSwitchButton : public BaseButton
    {
        USE_GAME_ALLOCATOR
    public:
        BaseSwitchButton(MinecraftGame *minecraftGame, int id, gstd::string localizeKey) :
            BaseButton(minecraftGame, id, localizeKey, false)
        {
            mUnk20  = Color::WHITE;
            mUnk23  = 16;
            mWidth  = 48;
            mHeight = 48;
            mUnk21  = 1;
        }

        ~BaseSwitchButton() override = default;

        // FUN_0x190498
        // +0x1C
        void render(MinecraftGame *minecraftGame, int touchX, int touchY) override
        {
            reinterpret_cast<void (*)(BaseSwitchButton *, MinecraftGame *, int, int)>(0x190498)(this, minecraftGame, touchX, touchY);
        }

        // FUN_0x1906C4
        // +0xA0
        void renderBackground(MinecraftGame *minecraftGame, int touchX, int touchY) override
        {
            return;
        }

        virtual void Unknown33() = delete;    // +0xA8
        virtual void Unknown34() = delete;    // +0xAC

        // FUN_0x1901B8
        // +0xB0
        virtual void Unknown35(int p1)
        {
            reinterpret_cast<void (*)(BaseSwitchButton *, int)>(0x1901B8)(this, p1);
        }

        // FUN_0x190198
        // +0xB4
        virtual bool Unknown36(int p1)
        {
            return (!p1 || mUnk22) ? false : true;
        }

    protected:
        // 0x99BB7C

        u8                             mUnk10;    // +0x8C
        gstd::string                   mUnk11;    // +0x90
        int                            mUnk12;    // +0x94
        BaseSwitchButton_UnknownStruct mUnk13;    // +0x98
        Color                          mUnk20;    // +0xDC
        u8                             mUnk21;    // +0xEC
        u8                             mUnk22;    // +0xED
        int                            mUnk23;    // +0xF0
    };
}    // namespace MC3DSPluginFramework