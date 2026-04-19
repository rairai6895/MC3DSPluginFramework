#include "GuiElementContainer.hpp"

namespace MC3DSPluginFramework
{
    GuiElementContainer::GuiElementContainer(bool active, bool visible, int x, int y, int w, int h) :
        GuiElement(active, visible, x, y, w, h, UseScreen::Both)
    {
        mUnk2 = x;
        mUnk3 = y;
    }

    // FUN_0x3BFBF8
    // +0x18
    void GuiElementContainer::Unknown3(MinecraftGame *minecraftGame)
    {
        for (auto &c : mChildren)
            c->Unknown3(minecraftGame);
    }

    // FUN_0x3BFC40
    // +0x1C
    void GuiElementContainer::render(MinecraftGame *minecraftGame, int touchX, int touchY)
    {
        GuiElement::render(minecraftGame, touchX, touchY);

        for (auto &c : mChildren)
            c->render(minecraftGame, touchX, touchY);
    }

    // FUN_0x3BFE9C
    // +0x20
    void GuiElementContainer::Unknown5(MinecraftGame *minecraftGame, int touchX, int touchY)
    {
        for (auto &c : mChildren)
            if (c->Unknown17())
                c->Unknown5(minecraftGame, touchX, touchY);
    }

    // FUN_0x3BF9C4
    // +0x24
    void GuiElementContainer::Unknown6()
    {
        for (auto &c : mChildren)
        {
            c->mX += (mX - mUnk2);
            c->mY += (mY - mUnk3);
            c->Unknown6();
        }

        mUnk2 = mX;
        mUnk3 = mY;
    }

    // FUN_0x3BF968
    // +0x28
    bool GuiElementContainer::onTouchDown(MinecraftGame *minecraftGame, int touchX, int touchY)
    {
        for (auto &c : mChildren)
            if (c->onTouchDown(minecraftGame, touchX, touchY))
                return true;

        return false;
    }

    // FUN_0x3BFA40
    // +0x2C
    bool GuiElementContainer::onTouchRelease(MinecraftGame *minecraftGame, int touchX, int touchY)
    {
        for (auto &c : mChildren)
            if (c->onTouchRelease(minecraftGame, touchX, touchY))
                return true;

        return false;
    }

    // FUN_0x3BFAE4
    // +0x30
    void GuiElementContainer::Unknown9(MinecraftGame *minecraftGame, int touchX, int touchY)
    {
        for (auto &c : mChildren)
            if (c->Unknown17())
                c->Unknown9(minecraftGame, touchX, touchY);
    }

    // FUN_0x3BFB90
    // +0x34
    void GuiElementContainer::Unknown10(MinecraftGame *minecraftGame, int x, int y)
    {
        for (auto &c : mChildren)
            if (c->Unknown17())
                c->Unknown10(minecraftGame, x, y);
    }

    // FUN_0x3BFB4C
    // +0x3C
    void GuiElementContainer::Unknown12(MinecraftGame *minecraftGame, int p2)
    {
        for (auto &c : mChildren)
            c->Unknown12(minecraftGame, p2);
    }

    // FUN_0x3BF91C
    // +0x40
    void GuiElementContainer::Unknown13(MinecraftGame *minecraftGame, int x, int y)
    {
        for (auto &c : mChildren)
            c->Unknown13(minecraftGame, x, y);
    }

    // FUN_0x3BF8C0
    // +0x48
    bool GuiElementContainer::onBack(MinecraftGame *minecraftGame, int p2)
    {
        bool res = false;

        for (auto &c : mChildren)
            if (c->onBack(minecraftGame, p2))
                res = true;

        return res;
    }

    // FUN_0x3BFA9C
    // +0x54
    bool GuiElementContainer::Unknown17()
    {
        for (auto &c : mChildren)
            if (c->Unknown17())
                return true;

        return false;
    }

    // FUN_0x6FEF00
    // +0x7C
    bool GuiElementContainer::Unknown25()
    {
        return true;
    }

    // FUN_0x3BFC94
    // +0x80
    void GuiElementContainer::addChild(BoxedPtr::Shared<GuiElement> element, bool p2)
    {
        if (!(std::find(mChildren.begin(), mChildren.end(), element) == mChildren.end()))
            LOG("The element is already a child", std::find(mChildren.begin(), mChildren.end(), element) == mChildren.end(), 0);

        element->mX += this->mX;
        element->mY += this->mY;
        mChildren.push_back(element);
        mUnk1.push_back(p2);
    }

    // FUN_0x3BF7E4
    // +0x84
    void GuiElementContainer::addChild(GuiElement *element, bool p2)
    {
        element->mX += this->mX;
        element->mY += this->mY;
        mChildren.push_back(BoxedPtr::Shared(element));
        mUnk1.push_back(p2);
    }

    // FUN_0x3BFDB4
    // +0x8C
    void GuiElementContainer::clearChildren()
    {
        mChildren.clear();
        mUnk1.clear();
    }
}    // namespace MC3DSPluginFramework