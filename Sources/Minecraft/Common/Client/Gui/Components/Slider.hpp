#pragma once

#include "GuiElement.hpp"
#include "Minecraft/Common/Client/Options/Options.hpp"
#include <cmath>

namespace MC3DSPluginFramework
{
    class MinecraftGame;
    class NinePatchLayer;

    // GuiElementContainerに入れて使う
    // OptionItemに入れないとだめなのかは未検証

    class Slider : public GuiElement
    {
        USE_GAME_ALLOCATOR
    private:
        void buildThumb();

    public:
        Slider(MinecraftGame *minecraftGame, const Options::Option *option, float min, float max);
        ~Slider() override;

        void         Unknown3(MinecraftGame *minecraftGame) override;
        void         render(MinecraftGame *minecraftGame, int touchX, int touchY) override;
        bool         onTouchDown(MinecraftGame *minecraftGame, int x, int y) override;
        bool         onTouchRelease(MinecraftGame *minecraftGame, int x, int y) override;
        virtual void update(MinecraftGame *minecraftGame);

    private:
        // 0x9CCBC0

        MinecraftGame                   *mMinecraftGame;    // +0x38
        bool                             mStepMode;    // +0x3C
        gstd::vector<int>                mStepValues;    // +0x40
        bool                             mHold;    // +0x4C
        float                            mProgressValue;    // +0x50
        int                              mCurrentStepValue;    // +0x54
        int                              mCurrentStep;    // +0x58
        int                              mMaxStep;    // +0x5C
        float                            mMin;    // +0x60
        float                            mMax;    // +0x64
        float                            mUnk10;    // +0x68
        const Options::Option           *mOption;    // +0x6C
        u8                               mUnk11;    // +0x70
        gstd::unique_ptr<NinePatchLayer> mThumb;    // +0x74
    };
}    // namespace MC3DSPluginFramework