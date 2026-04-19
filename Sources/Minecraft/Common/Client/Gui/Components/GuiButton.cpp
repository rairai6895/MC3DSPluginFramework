#include "GuiButton.hpp"
#include "Minecraft/Common/Client/Game/MinecraftGame.hpp"
#include "NinePatch.hpp"

namespace MC3DSPluginFramework
{
    GuiButton::GuiButton(MinecraftGame *minecraftGame, int id, int x, int y, int w, int h, const char *localizeKey, bool visualPressOnDrag, int p9)
    {
        using sig = GuiButton *(*)(GuiButton *, MinecraftGame *, int, int, int, int, int, const char *, bool, int);
        sig(0x5DB924)(this, minecraftGame, id, x, y, w, h, localizeKey, visualPressOnDrag, p9);
    }

    GuiButton::~GuiButton() = default;

    // FUN_0x5DB6A4
    // +0xA0
    void GuiButton::renderBackground(MinecraftGame *minecraftGame, int touchX, int touchY)
    {
        float x = mX;
        float y = mY;
        float w = mWidth;
        float h = mHeight;

        mDefaultBackground->setSize(w, h);
        mDownedBackground->setSize(w, h);
        mInActiveBackground->setSize(w, h);

        if (FUN_005e6338(touchX, touchY))
        {
            mDownedBackground->draw(Tessellator::instance, x, y);
            return;
        }

        if (mActive)
        {
            mDefaultBackground->draw(Tessellator::instance, x, y);
            return;
        }

        mInActiveBackground->draw(Tessellator::instance, x, y);
    }

    // FUN_0x5DB4B0
    // +0xA8
    void GuiButton::buildBackground()
    {
        NinePatchFactory factory(mMinecraftGame->getTextures(), ResourceLocation("textures/gui/spritesheet", 0));

        mDefaultBackground  = factory.createSymmetrical(IntRectangle(64, 144, 8, 8), 2, 2, mWidth, mHeight);
        mDownedBackground   = factory.createSymmetrical(IntRectangle(56, 144, 8, 8), 2, 2, mWidth, mHeight);
        mInActiveBackground = factory.createSymmetrical(IntRectangle(64, 208, 8, 8), 2, 2, mWidth, mHeight);
    }
}    // namespace MC3DSPluginFramework