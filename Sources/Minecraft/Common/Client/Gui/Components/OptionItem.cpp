#include "OptionItem.hpp"
#include "Minecraft/Common/Client/Game/MinecraftGame.hpp"
#include "Minecraft/Common/Client/Locale/Language.hpp"

namespace MC3DSPluginFramework
{
    // FUN_0x1A0AB4
    OptionItem::OptionItem(const Options::Option *option, BoxedPtr::Shared<GuiElement> element, bool p3, int offsetY) :
        GuiElementContainer(false, true, 0, 0, 24, 12),
        mOption(option),
        mUnk1(p3),
        mOffsetY(offsetY)
    {
        addChild(element, true);
    }

    // FUN_0x1A08D4
    // +0x1C
    void OptionItem::render(MinecraftGame *minecraftGame, int touchX, int touchY)
    {
        reinterpret_cast<void (*)(OptionItem *, MinecraftGame *, int, int)>(0x1A08D4)(this, minecraftGame, touchX, touchY);
    }

    // FUN_0x1A046C
    // +0x24
    void OptionItem::Unknown6()
    {
        int width   = 0;
        int height  = 0;
        int offsetY = getOffsetY();

        for (auto &c : mChildren)
        {
            c->mX = this->mX + 6;
            c->mY = this->mY + this->mOffsetY + offsetY;

            if (width < c->mWidth)
            {
                width = c->mWidth;
            }

            height += (c->mHeight + offsetY);
        }

        this->mWidth  = width;
        this->mHeight = height;
    }

    // FUN_0x6A81F0
    // +0x5C
    bool OptionItem::Unknown19()
    {
        for (auto &c : mChildren)
            if (c->Unknown19())
                return true;

        return false;
    }

    // FUN_0x6A8060
    // +0x68
    int OptionItem::getHeight()
    {
        return (*mChildren.begin())->getHeight() + getOffsetY();
    }

    // FUN_0x1A0468
    // +0x6C
    void OptionItem::drawOutline(int offset)
    {
        return;
    }

    void OptionItem::onSelectedChanged()
    {
        reinterpret_cast<void (*)(OptionItem *)>(0x1A06BC)(this);
    }

    // FUN_0x6A8108
    // +0x94
    gstd::string OptionItem::getLocalizedName(MinecraftGame *minecraftGame)
    {
        if (!mOption || mUnk1)
            return gstd::string::null;

        // ゲーム内の関数には無駄な処理がある

        return Localization::get(mOption->second, nullptr);
    }

    // FUN_0x6A804C
    // +0x98
    int OptionItem::getOffsetY()
    {
        return mUnk1 ? 0 : 26;
    }

}    // namespace MC3DSPluginFramework