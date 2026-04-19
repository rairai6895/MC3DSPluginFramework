#include "Slider.hpp"
#include "Minecraft/Common/Client/Game/MinecraftGame.hpp"
#include "NinePatch.hpp"

namespace MC3DSPluginFramework
{
    // FUN_0x6219B8
    void Slider::buildThumb()
    {
        NinePatchFactory factory(mMinecraftGame->getTextures(), ResourceLocation("textures/gui/spritesheet", 0));
        mThumb = factory.createSymmetrical(IntRectangle(64, 144, 8, 8), 2, 2, 8, 16);
    }

    // FUN_0x621FC0
    Slider::Slider(MinecraftGame *minecraftGame, const Options::Option *option, float min, float max) :
        GuiElement(true, true, 0, 0, 24, 24, UseScreen::Both)
    {
        mMinecraftGame    = minecraftGame;
        mStepMode         = 0;
        mHold             = 0;
        mCurrentStepValue = 0;
        mCurrentStep      = 0;
        mMaxStep          = 0;
        mMin              = min;
        mMax              = max;
        mUnk10            = 0;    //*(float *)0x6220B0;    // 0
        mOption           = option;
        mUnk11            = 0;

        if (mOption)
        {
            float val      = minecraftGame->getOptions().getFloat(*mOption);
            mProgressValue = (val - mMin / (mMax - mMin));
        }

        buildThumb();
    }

    Slider::~Slider() = default;

    // FUN_0x621A94
    // +0x18
    void Slider::Unknown3(MinecraftGame *minecraftGame)
    {
        reinterpret_cast<void (*)(Slider *, MinecraftGame *)>(0x621A94)(this, minecraftGame);
    }

    // FUN_0x621BEC
    // +0x18
    void Slider::render(MinecraftGame *minecraftGame, int touchX, int touchY)
    {
        reinterpret_cast<void (*)(Slider *, MinecraftGame *, int, int)>(0x621BEC)(this, minecraftGame, touchX, touchY);
    }

    // FUN_0x6216B8
    // +0x28
    bool Slider::onTouchDown(MinecraftGame *minecraftGame, int x, int y)
    {
        if (isInside(x, y))
            return mHold = true;

        return false;
    }

    // FUN_0x6216EC
    // +0x2C
    bool Slider::onTouchRelease(MinecraftGame *minecraftGame, int x, int y)
    {
        bool wasHold = mHold;
        mHold        = false;

        if (wasHold && mStepMode)
        {
            int   maxIndex    = mMaxStep - 1;
            float scaled      = 0.5f + mProgressValue * static_cast<float>(maxIndex);
            mCurrentStep      = std::min(static_cast<int>(std::floor(scaled)), maxIndex);
            mCurrentStepValue = mStepValues[mCurrentStep];
            mProgressValue    = static_cast<float>(mCurrentStep) / static_cast<float>(maxIndex);
            update(minecraftGame);
        }

        return wasHold;
    }

    // FUN_0x621EF0
    // +0x80
    void Slider::update(MinecraftGame *minecraftGame)
    {
        if (!mOption)
            return;

        Options &options = minecraftGame->getOptions();
        int      v       = reinterpret_cast<int (*)(Options &, const Options::Option &)>(0x6353D4)(options, *mOption);

        if (!v)
            return;

        if (mStepMode)
        {
            if (options.getInt(*mOption) != mCurrentStepValue)
                options.setInt(*mOption, mCurrentStepValue);
        }
        else if (options.getFloat(*mOption) != mMin + mProgressValue * (mMax - mMin))
            options.setFloat(*mOption, mMin + mProgressValue * (mMax - mMin));
    }
}    // namespace MC3DSPluginFramework