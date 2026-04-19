#pragma once

#include "../GuiComponent.hpp"
#include "Minecraft/src-deps/Core/Math/Color.hpp"

namespace MC3DSPluginFramework
{
    class NinePatchLayer;
    class MinecraftGame;

    class GuiElement_UnknownClass1
    {
    public:
        GuiElement_UnknownClass1()
        {
            reinterpret_cast<GuiElement_UnknownClass1 *(*)(GuiElement_UnknownClass1 *)>(0x26DAC8)(this);
        }

        virtual ~GuiElement_UnknownClass1()
        {
            reinterpret_cast<void (*)(GuiElement_UnknownClass1 *)>(0x26DC20)(this);
        }

        virtual void GuiElement_UnknownClass1_Unknown1()
        {
            return;
        }

    private:
    };

    class GuiElement : public GuiComponent, public GuiElement_UnknownClass1
    {
        USE_GAME_ALLOCATOR
    public:
        // ゲーム内関数呼び出ししかしてないコンストラクタ用のデフォルトコンストラクタ
        GuiElement() = default;

        GuiElement(bool active, bool visible, int x, int y, int w, int h, int useScreen);
        ~GuiElement() override;

        virtual void setSize(int w, int h);
        virtual void setX(int x);
        virtual void setY(int y);
        virtual void Unknown2() {};    // +0x14
        virtual void Unknown3(MinecraftGame *minecraftGame);
        virtual void render(MinecraftGame *minecraftGame, int touchX, int touchY);
        virtual void Unknown5(MinecraftGame *minecraftGame, int touchX, int touchY);
        virtual void Unknown6();
        virtual bool onTouchDown(MinecraftGame *minecraftGame, int touchX, int touchY);
        virtual bool onTouchRelease(MinecraftGame *minecraftGame, int touchX, int touchY);
        virtual void Unknown9(MinecraftGame *minecraftGame, int touchX, int touchY);
        virtual void Unknown10(MinecraftGame *minecraftGame, int x, int y);
        virtual void Unknown11() = delete;    // +0x38
        virtual void Unknown12(MinecraftGame *minecraftGame, int p2);
        virtual void Unknown13(MinecraftGame *minecraftGame, int x, int y);
        virtual void Unknown14() = delete;    // +0x44
        virtual bool onBack(MinecraftGame *minecraftGame, int p2);
        virtual void Unknown16() = delete;    // +0x4C
        virtual bool isInside(int x, int y);
        virtual bool Unknown17();
        virtual void Unknown18() = delete;    // +0x58
        virtual bool Unknown19();
        virtual void Unknown20() = delete;    // +0x60
        virtual void Unknown21() = delete;    // +0x64
        virtual int  getHeight();
        virtual void drawOutline(int offset);
        virtual void Unknown22(int p1) {}    // +0x70
        virtual void Unknown23();
        virtual void onSelectedChanged();
        virtual bool Unknown25();

    public:
        // FUN_0x1524B8
        void setSelected(bool set)
        {
            bool prevSelected = mSelected;
            mSelected         = set;

            if (prevSelected != set)
                onSelectedChanged();
        }

        bool isActive() { return mActive; }
        bool isVisible() { return mVisible; }

    protected:
        // 0x996958

        bool mActive;    // +0x8
        bool mVisible;    // +0x9

    public:
        int mX;    // +0xC
        int mY;    // +0x10
        int mWidth;    // +0x14
        int mHeight;    // +0x18

    protected:
        Color                            mBackgroundColor;    // +0x1C
        gstd::unique_ptr<NinePatchLayer> mUnk2;    // +0x2C
        bool                             mSelected;    // +0x30
        bool                             mUnk3;    // +0x31
        int                              mUseScreen;    // +0x34
    };
}    // namespace MC3DSPluginFramework