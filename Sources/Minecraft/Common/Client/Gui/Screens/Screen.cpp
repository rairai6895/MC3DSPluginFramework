#include "Minecraft/Common/Client/Gui/Screens/Screen.hpp"
#include "../../Game/MinecraftGame.hpp"
#include "Minecraft/Common/Client/Gui/Components/GuiElement.hpp"
#include "Minecraft/src-deps/3DS/TouchPad.hpp"

namespace MC3DSPluginFramework
{
    // FUN_0x620F14
    // +0xC
    void Screen::setSize(int width, int height)
    {
        mWidth  = width;
        mHeight = height;

        setupPositions();
    }

    // FUN_0x61F24C
    // +0x40
    void Screen::Unknown15()
    {
        touchEventUpdate();
        Unknown72();
    }

    // FUN_0x620830
    // +0x6C
    bool Screen::Unknown27(void *p1)
    {
        setTouchPosition(*(short *)((u32)p1 + 4), *(short *)((u32)p1 + 6));
        return true;
    }

    // FUN_0x62073C
    // +0x70
    void Screen::setTouch(bool set)
    {
        TouchPad::setTouch(set);
    }

    // FUN_0x61F69C
    // +0x74
    void Screen::Unknown29(int p1, int p2, float x, float y)
    {
        Unknown86(p1, x, y);
    }

    // FUN_0x61F5C8
    // +0x78
    bool Screen::onBack(int p1)
    {
        for (auto &element : mUnk8)
            if (element->onBack(mMinecraftGame, p1))
                return true;

        return false;
    }

    // FUN_0x729640
    // +0xA4
    bool Screen::disableCstick()
    {
        return 1;
    }

    // FUN_0x7296B4
    // +0xA8
    bool Screen::closeOnPlayerHurt()
    {
        return false;
    }

    // FUN_0x621064
    // +0xE0
    int Screen::getWidth()
    {
        return mWidth;
    }

    // FUN_0x62106C
    // +0xE4
    int Screen::getHeight()
    {
        return mHeight;
    }

    // FUN_0x729648
    // +0xF4
    gstd::string Screen::getName()
    {
        return "screen";
    }

    // FUN_0x61F6A8
    // +0x108
    void Screen::toGUICoordinate(int width, int height, int &x, int &y)
    {
        x = x * mWidth / width;
        y = y * mHeight / height - 1;
    }

    // FUN_0x620E94
    // +0x110
    void Screen::render(int touchX, int touchY, int useScreen, float tick)
    {
        if (Unknown79())
        {
            Unknown91(touchX, touchY, useScreen, tick);
            return;
        }

        renderComponents(touchX, touchY, useScreen, tick);
    }

    // FUN_0x620CC4
    // +0x114
    void Screen::setupComponents()
    {
        return;
    }

    // FUN_0x61F30C
    // +0x118
    void Screen::setupPositions()
    {
        for (auto &u : mUnk8)
            u->Unknown6();
    }

    // FUN_0x62066C
    // +0x11C
    void Screen::touchEventUpdate()
    {
        if (!mPrevTouch && TouchPad::isTouch())
            touchEvent(TouchPad::getX(), TouchPad::getY(), true);
        else if (mPrevTouch && !TouchPad::isTouch())
            touchEvent(TouchPad::getX(), TouchPad::getY(), false);

        mPrevTouch = TouchPad::isTouch();
    }

    // FUN_0x61FA2C
    // +0x124
    void Screen::renderBackgroundOrOverlay(int useScreen)
    {
        if (!Unknown40())
        {
            renderBackground(useScreen);
            return;
        }

        if (useScreen & UseScreen::Top)
            GuiComponent::fill(0, 0, 400, 240, Color(0, 0, 0, 127));
        else
            GuiComponent::fill(0, 0, 320, 240, Color(0, 0, 0, 127));
    }

    // +0x128
    Mesh Screen::buildDirtBackground(int useScreen)
    {
        return reinterpret_cast<Mesh (*)(Screen *, int)>(0x61FE40)(this, useScreen);
    }

    // FUN_0x620744
    // +0x12C
    void Screen::renderBackground(int useScreen)
    {
        renderDirtBackground(useScreen, buildDirtBackground(useScreen));
    }

    // +0x130
    void Screen::renderDirtBackground(int useScreen, const Mesh &mesh)
    {
        reinterpret_cast<void (*)(Screen *, int, const Mesh &)>(0x620794)(this, useScreen, mesh);
    }

    // FUN_0x61F278
    // +0x138
    void Screen::Unknown78()
    {
        return;
    }

    // FUN_0x620850
    // +0x13C
    bool Screen::Unknown79()
    {
        if (mUnk8.empty())
        {
            for (auto &b : mButtons)
                if (b->Unknown17())
                    return true;

            return false;
        }

        for (auto &u : mUnk8)
            if (u->Unknown17())
                break;

        return true;
    }

    // FUN_0x61FD0C
    // +0x144
    void Screen::Unknown81(int p1)
    {
        return;
    }

    // FUN_0x61F284
    // +0x14C
    void Screen::Unknown83(int x, int y)
    {
        for (auto &u : mUnk8)
            if (u->Unknown17())
                u->Unknown13(mMinecraftGame, x, y);
    }

    // FUN_0x62051C
    // +0x150
    void Screen::Unknown84(int p1)
    {
        return;
    }

    // FUN_0x19C05C
    // +0x154
    void Screen::setTouchPosition(int touchX, int touchY)
    {
        TouchPad::setX(touchX);
        TouchPad::setY(touchY);
    }

    // FUN_0x61F62C
    // +0x158
    void Screen::Unknown86(int p1 /*0:スライドパッド, 3:Cスティック*/, float x, float y)
    {
        if (p1 == 2)
        {
            Unknown87();
            return;
        }

        int stickId;

        if (p1 < 2)
        {
            stickId = 1;
        }
        else
        {
            if (p1 != 3)
                return;

            stickId = 0;
        }

        stickId += p1;
        MenuGamePad::setX(stickId, x);
        MenuGamePad::setY(stickId, y);
    }

    // FUN_0x61FD1C
    // +0x15C
    bool Screen::Unknown87()
    {
        return 0;
    }

    // FUN_0x620A10
    // +0x160
    void Screen::Unknown88(int p1)
    {
        return;
    }

    // FUN_0x61F280
    // +0x164
    void Screen::buttonPressed(BaseButton &button)
    {
        return;
    }

    // FUN_0x61ECD0
    // +0x168
    void Screen::renderComponents(int touchX, int touchY, int useScreen, float tick)
    {
        for (auto &u : mUnk8)
            u->render(mMinecraftGame, touchX, touchY);

        for (auto &b : mButtons)
            if (!b->mUnk8)
                b->render(mMinecraftGame, touchX, touchY);
    }

    // FUN_0x61FB14
    // +0x16C
    void Screen::Unknown91(int touchX, int touchY, int useScreen, float tick)
    {
        for (auto &u : mUnk8)
        {
            u->Unknown5(mMinecraftGame, touchX, touchY);
        }

        for (auto &b : mButtons)
        {
            b->Unknown5(mMinecraftGame, touchX, touchY);
        }
    }

    // FUN_0x6205E8
    // +0x170
    void Screen::touchEvent(int touchX, int touchY, bool touch)
    {
        int x = mWidth * touchX / 320;
        int y = mHeight * touchY / 240;

        if (touch)
            onTouchDown(x, y - 1);
        else
            onTouchRelease(x, y - 1);
    }

    // FUN_0x620A84
    // +0x174
    void Screen::updateComponentSelections()
    {
        for (int i = 0; i < mUnk11.size(); ++i)
            mUnk11[i]->setSelected(mUnk15 == i);

        for (int i = 0; i < mTabButtons.size(); ++i)
            mTabButtons[i]->setSelected(mTabButtonIndex == i);
    }

    // FUN_0x61FC74
    // +0x178
    void Screen::handleButtonDown(BoxedPtr::Shared<GuiButton> button, int touchX, int touchY)
    {
        if (!button->isActive())
            return;

        if (!button->isHovered(touchX, touchY))
            return;

        button->onTouchDown(mMinecraftGame, touchX, touchY);
        button->setDragging(true);
        mDraggingButton = button;
    }

    // FUN_0x61FD30
    // +0x17C
    void Screen::handleButtonRelease(BoxedPtr::Shared<GuiButton> button, int touchX, int touchY)
    {
        if (mDraggingButton != button)
            return;

        if (!button->isHovered(touchX, touchY))
            return;

        buttonPressed(*button);
    }

    // FUN_0x61FD24
    // +0x180
    bool Screen::Unknown96()
    {
        return 0;
    }

    // FUN_0x61F34C
    // +0x184
    void Screen::onTouchDown(int touchX, int touchY)
    {
        if (!Unknown79())
        {
            for (auto &u : mUnk8)
                if (u->onTouchDown(mMinecraftGame, touchX, touchY))
                    return;

            for (auto &b : mButtons)
                handleButtonDown(b, touchX, touchY);
        }
        else
        {
            for (auto &b : mButtons)
                if (b->Unknown17())
                    b->Unknown9(mMinecraftGame, touchX, touchY);

            for (auto &u : mUnk8)
                if (u->Unknown17())
                    u->Unknown9(mMinecraftGame, touchX, touchY);
        }
    }

    // FUN_0x620B34
    // +0x18C
    void Screen::onKeyPressed(InputDevice type, StickKey key)
    {
        if (type != InputDevice::SlidePad)
            return;

        if (key == StickKey::Top)
            onKeyPrevious();
        else if (key == StickKey::Down)
            onKeyNext();

        updateComponentSelections();
    }

    // FUN_0x620A24
    // +0x190
    void Screen::onKeyRepeat(InputDevice type, StickKey key)
    {
        Screen::onKeyPressed(type, key);    // 同じコードだからそのまま呼び出し
    }

    // FUN_0x620F28
    // +0x194
    void Screen::onKeyNext()
    {
        if (mUnk11.empty() && mTabButtons.empty())
            return;

        mMinecraftGame->playSound(Util::hashCode("random.click") /*0x7E943735*/, 1, 1);

        if (mUnk11.size() == ++mUnk15)
            mUnk15 = 0;

        if (mTabButtons.size() == ++mTabButtonIndex)
            mTabButtonIndex = 0;
    }

    // FUN_0x620FC4
    // +0x198
    void Screen::onKeyPrevious()
    {
        if (mUnk11.empty() && mTabButtons.empty())
            return;

        mMinecraftGame->playSound(Util::hashCode("random.click") /*0x7E943735*/, 1, 1);

        if (mUnk15-- == 0)
            mUnk15 = mUnk11.size() - 1;

        if (mTabButtonIndex-- == 0)
            mTabButtonIndex = mTabButtons.size() - 1;
    }

}    // namespace MC3DSPluginFramework