#pragma once

#include "../Components/IconButton.hpp"
#include "MenuGamePad.hpp"
#include "Minecraft/Common/Client/Gui/Components/GuiElement.hpp"
#include "Minecraft/Common/Client/Gui/Components/GuiElementContainer.hpp"
#include "Minecraft/Common/Client/Gui/GuiComponent.hpp"
#include "Minecraft/Common/Client/Gui/Screens/BaseScreen.hpp"
#include "Minecraft/Common/Logger.hpp"
#include "Minecraft/Common/Util/Util.hpp"
#include "Minecraft/src-deps/3DS/TouchPad.hpp"

namespace MC3DSPluginFramework
{
    class ClientInstance;
    class Font;
    class Button;

    class Screen : public BaseScreen, public GuiComponent, public Screen_UnknownClass2
    {
    public:
        Screen(MinecraftGame *minecraftGame, ClientInstance *clientInstance) :
            BaseScreen(minecraftGame), mClient(*clientInstance)
        {
            reinterpret_cast<Screen *(*)(Screen *, MinecraftGame *, ClientInstance *)>(0x621078)(this, minecraftGame, clientInstance);
        }

    public:
        ~Screen() override = default;

        // +0x8
        void _init(int width, int height) override
        {
            reinterpret_cast<void (*)(Screen *, int, int)>(0x620D24)(this, width, height);
        }

        void setSize(int width, int height) override;

        // +0x18
        void Unknown5() override
        {
            return;
        }

        // +0x1C
        void Unknown6() override
        {
            return;
        }

        // FUN_0x61F198
        // +0x20
        void Unknown7() override
        {
            for (auto &u : mUnk2)
                u->stopDragging();
        }

        // +0x24
        void Unknown8() override
        {
            return;
        }

        // +0x38
        void Unknown13() override
        {
            return;
        }

        // +0x3C
        void Unknown14() override
        {
            reinterpret_cast<void (*)(Screen *)>(0x620CC8)(this);
        }

        void Unknown15() override;

        // +0x4C
        void Unknown19(void *unknown) override
        {
            reinterpret_cast<void (*)(Screen *, void *)>(0x620DDC)(this, unknown);
        }

        // +0x58
        void Unknown22() override
        {
            return;
        }

        // +0x5C
        void Unknown23() override
        {
            return;
        }

        // FUN_0x61FD10
        // +0x60
        void Unknown24(int p1) override
        {
            Unknown81(p1);
        }

        // FUN_0x620510
        // +0x64
        void Unknown25(int p1, int p2) override
        {
            Unknown82(p1, p2);
        }

        bool Unknown27(void *p1) override;
        void setTouch(bool set) override;
        void Unknown29(int p1, int p2, float x, float y) override;
        bool onBack(int p1) override;

        // FUN_0x61F2F4
        // +0x7C
        void Unknown31(int p1, int p2) override
        {
            Unknown83(p1, p2);
        }

        // FUN_0x620520
        // +0x80
        void Unknown32(int p1) override
        {
            Unknown84(p1);
        }

        // +0x88
        void Unknown34() override
        {
            return;
        }

        // FUN_0x620A14
        // +0x94
        void Unknown37(int p1) override
        {
            Unknown88(p1);
        }

        // +0x9C
        void Unknown39() override
        {
            return;
        }

        // +0xA0
        bool Unknown40() override
        {
            return reinterpret_cast<bool (*)(Screen *)>(0x729664)(this);
        }

        bool         disableCstick() override;
        bool         closeOnPlayerHurt() override;
        int          getWidth() override;
        int          getHeight() override;
        gstd::string getName() override;
        void         toGUICoordinate(int width, int height, int &x, int &y) override;
        virtual void render(int touchX, int touchY, int useScreen, float tick);
        virtual void setupComponents();
        virtual void setupPositions();
        virtual void touchEventUpdate();

        // +0x120
        virtual void Unknown72()
        {
            reinterpret_cast<void (*)(Screen *)>(0x620B94)(this);
        }

        virtual void renderBackgroundOrOverlay(int useScreen);
        virtual Mesh buildDirtBackground(int useScreen);
        virtual void renderBackground(int useScreen);
        virtual void renderDirtBackground(int useScreen, const Mesh &mesh);
        virtual void Unknown77() = delete;    // +0x134
        virtual void Unknown78();
        virtual bool Unknown79();
        virtual void Unknown80() = delete;    // +0x140
        virtual void Unknown81(int p1);

        // ボタン入力
        // +0x148
        virtual void Unknown82(int p1, int p2)
        {
            reinterpret_cast<void (*)(Screen *, int, int)>(0x61FFD4)(this, p1, p2);
        }

        virtual void Unknown83(int x, int y);
        virtual void Unknown84(int p1);
        virtual void setTouchPosition(int touchX, int touchY);
        virtual void Unknown86(int p1, float x, float y);
        virtual bool Unknown87();
        virtual void Unknown88(int p1);
        virtual void buttonPressed(BaseButton &button);
        virtual void renderComponents(int touchX, int touchY, int useScreen, float tick);
        virtual void Unknown91(int touchX, int touchY, int useScreen, float tick);
        virtual void touchEvent(int touchX, int touchY, bool touch);
        virtual void updateComponentSelections();
        virtual void handleButtonDown(BoxedPtr::Shared<GuiButton> button, int touchX, int touchY);
        virtual void handleButtonRelease(BoxedPtr::Shared<GuiButton> button, int touchX, int touchY);
        virtual bool Unknown96();
        virtual void onTouchDown(int touchX, int touchY);

        // +0x188
        virtual void onTouchRelease(int touchX, int touchY)
        {
            reinterpret_cast<void (*)(Screen *, int, int)>(0x61F6F8)(this, touchX, touchY);
        }

        // 仮
        enum class InputDevice {
            SlidePad = 1,
            CStick   = 3
        };
        enum class StickKey {
            Top   = 1,
            Down  = 2,
            Left  = 3,
            Right = 4,
        };

        virtual void onKeyPressed(InputDevice type, StickKey key);
        virtual void onKeyRepeat(InputDevice type, StickKey key);
        virtual void onKeyNext();
        virtual void onKeyPrevious();

        // +0x19C
        virtual void renderButtonTips(bool unknown1, bool unknown2)
        {
            reinterpret_cast<void (*)(Screen *, bool, bool)>(0x61EE5C)(this, unknown1, unknown2);
        }

    public:
        void FUN_0061f300(int p1)
        {
            mTabButtonIndex = p1;
            mUnk15          = p1;
        }

    protected:
        // 0x9CC9F4

        int                                                 mWidth;    // +0x10
        int                                                 mHeight;    // +0x14
        ClientInstance                                     &mClient;    // +0x18
        gstd::vector<BoxedPtr::Shared<GuiButton>>           mButtons;    // +0x1C
        gstd::vector<BoxedPtr::Shared<GuiButton>>           mUnk2;    // +0x28 ボタンかどうかは分からない
        gstd::vector<BoxedPtr::Shared<GuiButton>>           mTabButtons;    // +0x34
        gstd::vector<BoxedPtr::Shared<GuiElementContainer>> mUnk8;    // +0x40 同じポインタ
        gstd::vector<BoxedPtr::Shared<GuiElementContainer>> mUnk11;    // +0x4C 同じポインタ
        int                                                 mTabButtonIndex;    // +0x58
        int                                                 mUnk15;    // +0x5C
        gstd::unique_ptr<GuiElement>                        mUnk16;    // +0x60 現在のタブ名とか、ButtonTipsの描画に使われてる文字列関係
        Font                                               *mFont;    // +0x64
        BoxedPtr::Shared<GuiButton>                         mDraggingButton;    // +0x68
        bool                                                mPrevTouch;    // +0x70
        gstd::map<InputDevice, u32>                         mStickInputs;    // +0x74 Cスティックとスライドパッドの入力が入ってる
    };
}    // namespace MC3DSPluginFramework