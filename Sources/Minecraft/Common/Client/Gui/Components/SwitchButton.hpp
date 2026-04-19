#pragma once

#include "BaseSwitchButton.hpp"
#include "Minecraft/Common/Client/Options/Options.hpp"
#include "NinePatch.hpp"

namespace MC3DSPluginFramework
{
    class SwitchButton : public BaseSwitchButton
    {
        USE_GAME_ALLOCATOR
    public:
        // FUN_0x1DD760
        SwitchButton(MinecraftGame *minecraftGame, const Options::Option *option, const BaseSwitchButton_UnknownStruct &p3, int id) :
            BaseSwitchButton(minecraftGame, id, "")
        {
            mOption = option;
            mUnk26  = 0;
            mUnk13  = p3;
            reinterpret_cast<void (*)(SwitchButton *)>(0x1DD020)(this);
        }

        ~SwitchButton() override = default;

        // FUN_0x1DD4FC
        // +0x18
        void Unknown3(MinecraftGame *minecraftGame) override
        {
            reinterpret_cast<void (*)(SwitchButton *, MinecraftGame *)>(0x1DD4FC)(this, minecraftGame);
        }

        // FUN_0x1DD398
        // +0x28
        bool onTouchDown(MinecraftGame *minecraftGame, int touchX, int touchY) override
        {
            return reinterpret_cast<bool (*)(SwitchButton *, MinecraftGame *, int, int)>(0x1DD398)(this, minecraftGame, touchX, touchY);
        }

        // FUN_0x1DD3F8
        // +0x3C
        void Unknown12(MinecraftGame *minecraftGame, int p2) override
        {
            reinterpret_cast<void (*)(SwitchButton *, MinecraftGame *, int)>(0x1DD3F8)(this, minecraftGame, p2);
        }

        // FUN_0x1DD150
        // +0xB0
        void Unknown35(int p1) override
        {
            reinterpret_cast<void (*)(SwitchButton *, int)>(0x1DD150)(this, p1);
        }

    private:
        // 0x9A1420

        const Options::Option           *mOption;    // +0xF4
        u8                               mUnk24;    // +0xF8
        BaseSwitchButton_UnknownStruct   mUnk25;    // +0xFC
        int                              mUnk26;    // +0x140
        gstd::unique_ptr<NinePatchLayer> mThumb;    // +0x144
    };
}    // namespace MC3DSPluginFramework