#include "GuiElement.hpp"
#include "NinePatch.hpp"

namespace MC3DSPluginFramework
{
    GuiElement::GuiElement(bool active, bool visible, int x, int y, int w, int h, int useScreen) :
        GuiComponent(), GuiElement_UnknownClass1()
    {
        mActive          = active;
        mVisible         = visible;
        mX               = x;
        mY               = y;
        mWidth           = w;
        mHeight          = h;
        mBackgroundColor = *(Color *)0xB2E560;
        mSelected        = false;
        mUnk3            = false;
        mUseScreen       = useScreen;
    }

    // コンパイルエラー回避のためにcppに書く
    GuiElement::~GuiElement() = default;

    // FUN_0x152698
    // +0x8
    void GuiElement::setSize(int w, int h)
    {
        mWidth  = w;
        mHeight = h;
    }

    // FUN_0x1525C0
    // +0xC
    void GuiElement::setX(int x)
    {
        mX = x;
    }

    // FUN_0x1525C8
    // +0x10
    void GuiElement::setY(int y)
    {
        mY = y;
    }

    // FUN_0x1525D0
    // +0x18
    void GuiElement::Unknown3(MinecraftGame *minecraftGame)
    {
        return;
    }

    // +0x1C
    void GuiElement::render(MinecraftGame *minecraftGame, int touchX, int touchY)
    {
        reinterpret_cast<void (*)(GuiElement *, MinecraftGame *, int, int)>(0x1525D4)(this, minecraftGame, touchX, touchY);
    }

    // FUN_0x1526A4
    // +0x20
    void GuiElement::Unknown5(MinecraftGame *minecraftGame, int touchX, int touchY)
    {
        return;
    }

    // FUN_0x152538
    // +0x24
    void GuiElement::Unknown6()
    {
        return;
    }

    // FUN_0x152530
    // +0x28
    bool GuiElement::onTouchDown(MinecraftGame *minecraftGame, int touchX, int touchY)
    {
        return 0;
    }

    // FUN_0x15253C
    // +0x2C
    bool GuiElement::onTouchRelease(MinecraftGame *minecraftGame, int touchX, int touchY)
    {
        return 0;
    }

    // FUN_0x15259C
    // +0x30
    void GuiElement::Unknown9(MinecraftGame *minecraftGame, int touchX, int touchY)
    {
        return;
    }

    // FUN_0x1525A4
    // +0x34
    void GuiElement::Unknown10(MinecraftGame *minecraftGame, int x, int y)
    {
        return;
    }

    // FUN_0x1525A0
    // +0x3C
    void GuiElement::Unknown12(MinecraftGame *minecraftGame, int p2)
    {
        return;
    }

    // FUN_0x15252C
    // +0x40
    void GuiElement::Unknown13(MinecraftGame *minecraftGame, int x, int y)
    {
        return;
    }

    // FUN_0x15246C
    // +0x48
    bool GuiElement::onBack(MinecraftGame *minecraftGame, int p2)
    {
        return 0;
    }

    // FUN_0x152474
    // +0x50
    bool GuiElement::isInside(int x, int y)
    {
        return (x >= mX) && (x < (mX + mWidth)) && (y >= mY) && (y < (mY + mHeight));
    }

    // FUN_0x152544
    // +0x54
    bool GuiElement::Unknown17()
    {
        return 0;
    }

    // FUN_0x6950E8
    // +0x5C
    bool GuiElement::Unknown19()
    {
        return mUnk3;
    }

    // FUN_0x6950E0
    // +0x68
    int GuiElement::getHeight()
    {
        return mHeight;
    }

    // FUN_0x1524D8
    // +0x6C
    void GuiElement::drawOutline(int offset)
    {
        GuiComponent::outline(mX - offset, mY - offset, mX + mWidth + offset, mHeight + mY + offset, Color::YELLOW, 1);
    }

    // FUN_0x152550
    // +0x74
    void GuiElement::Unknown23()
    {
        GuiComponent::outline(mX + -3, mY + -3, mWidth + mX + 2, mHeight + mY + 3, Color::YELLOW, 1);
    }

    // FUN_0x15254C
    // +0x78
    void GuiElement::onSelectedChanged()
    {
        return;
    }

    // FUN_0x6950D8
    // +0x7C
    bool GuiElement::Unknown25()
    {
        return 0;
    }
}    // namespace MC3DSPluginFramework