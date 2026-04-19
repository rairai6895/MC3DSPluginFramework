#pragma once

#include "GuiElementContainer.hpp"
#include "ScrollingPane.hpp"

namespace MC3DSPluginFramework
{
    class ScrollingPane;

    class ScrollGuiElementContainer_UnknownClass1
    {
        USE_GAME_ALLOCATOR
    public:
        virtual ~ScrollGuiElementContainer_UnknownClass1() = default;
        virtual void onScroll();

    private:
    };

    class ScrollGuiElementContainer : public GuiElementContainer, public ScrollGuiElementContainer_UnknownClass1
    {
        USE_GAME_ALLOCATOR
    public:
        ScrollGuiElementContainer(MinecraftGame *minecraftGame, int x, int y, int w, int h, bool p6, bool p7) :
            GuiElementContainer(true, true, x, y, w, h)
        {
            mMinecraftGame   = minecraftGame;
            mUnk1            = 0;
            mUnk2            = 0;
            mUnk3            = 0;
            mUnk4            = 0;
            mUnk5            = 0;
            mScrollingPane   = nullptr;
            mScrollLength    = 0;
            mUnk6            = 0;
            mUnk7            = 0;
            mUnk8            = true;
            mUnk9            = p6;
            mUnk10           = p7;
            mUnk11           = 0;
            mUnk12           = 0;
            mElementInterval = 0;
        }

        ~ScrollGuiElementContainer() override = default;

        // FUN_0x42BB20
        // +0x18
        void Unknown3(MinecraftGame *minecraftGame) override
        {
            if (mScrollingPane)
                mScrollingPane->Unknown2();
            else
                Unknown6();

            GuiElementContainer::Unknown3(minecraftGame);
        }

        // FUN_0x42BB64
        // +0x1C
        void render(MinecraftGame *minecraftGame, int touchX, int touchY) override
        {
            reinterpret_cast<void (*)(ScrollGuiElementContainer *, MinecraftGame *, int, int)>(0x42BB64)(this, minecraftGame, touchX, touchY);
        }

        // FUN_0x42B1F8
        // +0x24
        void Unknown6() override
        {
            reinterpret_cast<void (*)(ScrollGuiElementContainer *)>(0x42B1F8)(this);
        }

        // FUN_0x42B16C
        // +0x28
        bool onTouchDown(MinecraftGame *minecraftGame, int touchX, int touchY) override
        {
            if (!isInside(touchX, touchY))
                return false;

            for (auto &c : mChildren)
                if (c->onTouchDown(minecraftGame, touchX, touchY))
                    return true;

            return false;
        }

        // FUN_0x74B468
        void onScroll() override
        {
            Unknown6();
        }

    private:
        // 0x9C0E18
        // 0x9C0EB4
        // 0x9C0EC8

        MinecraftGame                  *mMinecraftGame;    // +0x64
        float                           mUnk1;    // +0x68
        float                           mUnk2;    // +0x6C
        float                           mUnk3;    // +0x70
        int                             mUnk4;    // +0x74
        int                             mUnk5;    // +0x78
        gstd::unique_ptr<ScrollingPane> mScrollingPane;    // +0x7C
        int                             mScrollLength;    // +0x80
        int                             mUnk6;    // +0x84
        int                             mUnk7;    // +0x88
        bool                            mUnk8;    // +0x8C
        bool                            mUnk9;    // +0x8D
        bool                            mUnk10;    // +0x8E
        int                             mUnk11;    // +0x90
        int                             mUnk12;    // +0x94
        int                             mElementInterval;    // +0x98
    };
}    // namespace MC3DSPluginFramework