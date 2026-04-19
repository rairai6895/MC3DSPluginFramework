#include "BaseButton.hpp"
#include "Minecraft/Common/Client/Game/MinecraftGame.hpp"
#include "Minecraft/Common/Client/Gui/Screens/BaseScreen.hpp"
#include "Minecraft/Common/Client/Locale/Language.hpp"

namespace MC3DSPluginFramework
{
    // 自作ラップ
    void BaseButton::init(MinecraftGame *minecraftGame, int id, bool visualPressOnDrag, const gstd::string &localizeKey)
    {
        mUnk1                 = 0;
        mLabelColor           = Color(0, 0, 0);
        mPressedLabelColor    = Color(152, 152, 152);
        mUnk4                 = Color(44, 44, 44);
        mMinecraftGame        = minecraftGame;
        mId                   = id;
        mVisualPressOnDrag    = visualPressOnDrag;
        mDragging             = false;
        mUnk8                 = false;
        mUnk9                 = 2;
        mScreen_UnknownClass2 = nullptr;

        if (localizeKey.empty())
        {
            mLabel      = *(gstd::string *)0xA332D8;    // 仮のラベル(nullstring)
            mLabelWidth = 0;
        }
        else
            setLabel();
    }

    // FUN_0x5E6770
    BaseButton::BaseButton(MinecraftGame *minecraftGame, int id, int x, int y, int w, int h, gstd::string localizeKey, bool visualPressOnDrag) :
        GuiElement(true, true, x, y, w, h, UseScreen::Both)
    {
        init(minecraftGame, id, visualPressOnDrag, localizeKey);
    }

    // FUN_0x5E64FC
    BaseButton::BaseButton(MinecraftGame *minecraftGame, int id, gstd::string localizeKey, bool visualPressOnDrag) :
        GuiElement(true, true, 0, 0, 200, 24, UseScreen::Both)
    {
        init(minecraftGame, id, visualPressOnDrag, localizeKey);
    }

    // FUN_0x5E663C
    BaseButton::BaseButton(MinecraftGame *minecraftGame, int id, int x, int y, gstd::string localizeKey) :
        GuiElement(true, true, x, y, 200, 24, UseScreen::Both)
    {
        init(minecraftGame, id, false, localizeKey);
    }

    // FUN_0x5E620C
    // +0x1C
    void BaseButton::render(MinecraftGame *minecraftGame, int touchX, int touchY)
    {
        if (!mVisible)
            return;

        Unanalyzed::setShaderColor(Color::WHITE);

        if (mSelected)
            drawOutline(!mUnk1);

        if (!mUnk1 || ((mDragging && (Unknown22(0), !mUnk1))))
            renderBackground(minecraftGame, touchX, touchY);

        drawLabel(touchX, touchY);
    }

    // FUN_0x5E6134
    // +0x28
    bool BaseButton::onTouchDown(MinecraftGame *minecraftGame, int touchX, int touchY)
    {
        if (mActive && isHovered(touchX, touchY))
        {
            setDragging(true);
            return true;
        }

        return false;
    }

    // FUN_0x5E618C
    // +0x2C
    bool BaseButton::onTouchRelease(MinecraftGame *minecraftGame, int touchX, int touchY)
    {
        bool clicked = mDragging && isHovered(touchX, touchY);
        stopDragging();

        if (!clicked)
            return false;

        if (mScreen_UnknownClass2)
            mScreen_UnknownClass2->Unknown1(*this);

        return true;
    }

    // FUN_0x5E6074
    // +0x70
    void BaseButton::Unknown22(int p1)
    {
        GuiComponent::outline(mX + 3, mY + 3, (mX + mWidth + p1 - 3), (mY + mHeight + p1 - 3), Color::WHITE, 1);
    }

    // FUN_0x5E62E4
    // +0x80
    bool BaseButton::isHovered(int touchX, int touchY)
    {
        return mActive ? GuiElement::isInside(touchX, touchY) : false;
    }

    // FUN_0x5E63E8
    // +0x84
    void BaseButton::stopDragging()
    {
        mDragging = false;
    }

    // FUN_0x5E605C
    // +0x88
    void BaseButton::toggleDragging()
    {
        mDragging = !mDragging;
    }

    // FUN_0x5E6054
    // +0x8C
    void BaseButton::setDragging(bool set)
    {
        mDragging = set;
    }

    // FUN_0x5E60E4
    // +0x98
    void BaseButton::setLabel()
    {
        mLabel      = Localization::get(mLocalizeKey, nullptr);
        mLabelWidth = mMinecraftGame->getDefaultFont().getTextWidth(mLabel, false, 1.f);
    }

    // FUN_0x5E64DC
    // +0x9C
    u8 BaseButton::Unknown31(int p1)
    {
        return (mActive && p1) ? 2 : mActive;
    }

    // +0xA0
    void BaseButton::renderBackground(MinecraftGame *minecraftGame, int touchX, int touchY)
    {
        reinterpret_cast<void (*)(BaseButton *, MinecraftGame *, int, int)>(0x5E63F4)(this, minecraftGame, touchX, touchY);
    }

    // +0xA4
    void BaseButton::drawLabel(int touchX, int touchY)
    {
        reinterpret_cast<void (*)(BaseButton *, int, int)>(0x5E5F1C)(this, touchX, touchY);
    }

}    // namespace MC3DSPluginFramework