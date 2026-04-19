#pragma once

#include "Minecraft/Common/Client/Gui/Components/IconButton.hpp"
#include "Minecraft/Common/Client/Gui/Components/NinePatch.hpp"
#include "Minecraft/Common/Client/Gui/Components/OptionItem.hpp"
#include "Minecraft/Common/Client/Gui/Components/Slider.hpp"
#include "Minecraft/Common/Client/Gui/Screens/Screen.hpp"
#include "Minecraft/Common/Client/Gui/Screens/SystemMessagesScreen.hpp"
#include "Minecraft/Common/Platform/AppPlatform.hpp"
#include <CTRPluginFramework.hpp>

namespace MC3DSPluginFramework
{
    class CustomScreen : public Screen
    {
        USE_GAME_ALLOCATOR
    private:
        enum ButtonId {
            test1,
            test2,
            test3,
        };

    public:
        CustomScreen(MinecraftGame *mg, ClientInstance *ci) :
            Screen(mg, ci) {}

        ~CustomScreen() override = default;

        void setupComponents() override
        {
            // IntRectangle uv1(64, 144, 8, 8);
            // IntRectangle uv2(56, 144, 8, 8);
            // void *unk = (void *)0xABFD74;
            // int Y     = 15;

            // BoxedPtr::Shared<IconButton> button1(std::make_unique<IconButton>(mMinecraftGame, 1, 110, Y, 200, 0x1C, "menu.options", false));
            // button1->setTexture(unk, 224, 144, 16, 16, 0, uv1, uv2, 2, 2, 0);
            // mButtons.push_back(std::move(button1));

            NinePatchFactory factory(mMinecraftGame->getTextures(), *(ResourceLocation *)0xABFD74);
            mBackgroundFrame = factory.createSymmetrical(IntRectangle(56, 160, 8, 8), 2, 2, AppPlatform::BOTTOM_SCREEN_WIDTH, AppPlatform::BOTTOM_SCREEN_HEIGHT);
            mBackground      = factory.createSymmetrical(IntRectangle(80, 176, 8, 8), 3, 3, 308, 204);

            ResourceLocation &loc = *(ResourceLocation *)0xABFD74;
            mSprite1              = gstd::make_unique<Sprite>(mMinecraftGame, 7, 7, 16, 16, loc, 200, 25, 8, 8);
        }

        void buttonPressed(BaseButton &b) override
        {
            switch (b.getId())
            {
                default: break;
                case ButtonId::test1:
                    SystemMessagesScreen::RunningInstance->pushMessage("Hello", 0);
                    break;
                case ButtonId::test2:
                    SystemMessagesScreen::RunningInstance->pushMessage("World", 0);
                    break;
                case ButtonId::test3:
                    SystemMessagesScreen::RunningInstance->pushMessage("!", 0);
                    break;
            }
        }

        bool onBack(int p1) override
        {
            SystemMessagesScreen::RunningInstance->pushMessage(__func__, 0);
            return true;
        }

        /*
        // handleInput?
        void Unknown82(u32 unknown) override
        {
        }
        */

        // +0x18
        void Unknown5() override
        {
            SystemMessagesScreen::RunningInstance->pushMessage(__func__, 0);
            return;
        }

        // 表示したときに呼ばれる
        // +0x1C
        void Unknown6() override
        {
            SystemMessagesScreen::RunningInstance->pushMessage(__func__, 0);
            return;
        }

        void Unknown24(int p1) override
        {
            SystemMessagesScreen::RunningInstance->pushMessage(CTRPluginFramework::Utils::ToHex(p1).c_str(), 0);
            return;
        }

        // tick?
        // trueを返すようにしないとバグるっぽい？
        // LevelRendererで呼ばれてる
        bool Unknown40() override
        {
            return true;
        }

        // cスティックとスライドパッドを動かすと呼ばれる
        bool disableCstick() override
        {
            return *(bool *)0x918F01;
        }

        // ZLZR、左右十字でのホットバー操作を受け付けるか
        bool allowsHotbarInput() override
        {
            return false;
        }

        // 下画面タッチ時に二回呼ばれて、他のボタンを押したあとに下画面タッチすると、再度2回呼ばれる
        // UIが手前に来た際にも一度呼ばれる
        bool Unknown45() override
        {
            return *(bool *)0x918F03;
        }

        bool Unknown46() override
        {
            // SystemMessagesScreen::RunningInstance->pushMessage(__func__, 0);
            return *(bool *)0x918F04;
        }

        // 他のスクリーンよりも手前表示
        bool isOverlay() override
        {
            return true;
        }

        bool Unknown51() override
        {
            // SystemMessagesScreen::RunningInstance->pushMessage(__func__, 0);
            return *(bool *)0x918F06;
        }

        // 他スクリーンがあると非表示
        // isOverlayより優先される
        bool renderBehind() override
        {
            return false;
        }

        // ポーズ中以外の時に呼ばれてる
        bool Unknown55() override
        {
            // SystemMessagesScreen::RunningInstance->pushMessage(__func__, 0);
            return *(bool *)0x918F08;
        }

        // 他スクリーンのスティック、XY、Start、Selectが無効化される
        // もしかしたら、他のスクリーンを開くことができるかのフラグかもしれない
        /*
        bool disablesStickInput() const override
        {
            // SystemMessagesScreen::RunningInstance->pushMessage(__func__, 0);
            return *(bool *)0x918F09;
        }
        */

        void Unknown86(int p1, float x, float y) override
        {
            // Cスティック動かすとunknown3は1、離すとunknown3が3になる。スティックを動かすと0
            // unknown3はInputHandlerのメンバーから来てる

            // SystemMessagesScreen::RunningInstance->pushMessage(std::to_string(x).c_str(), 0);
            // SystemMessagesScreen::RunningInstance->pushMessage(std::to_string(y).c_str(), 0);
            // SystemMessagesScreen::RunningInstance->pushMessage(CTRPluginFramework::Utils::ToHex(unknown3).c_str(), 0);
        }

        bool Unknown87() override
        {
            SystemMessagesScreen::RunningInstance->pushMessage(__func__, 0);
            return *(bool *)0x918F0A;
        }

        bool Unknown96() override
        {
            SystemMessagesScreen::RunningInstance->pushMessage(__func__, 0);
            return *(bool *)0x918F0B;
        }

        int getUseScreen() override
        {
            return UseScreen::Both;
        }

        gstd::string getName() override
        {
            return "custom_screen";
        }

        void render(int touchX, int touchY, int useScreen, float tick) override
        {
            if (useScreen & UseScreen::Top)
            {
                gstd::string str(CTRPluginFramework::Utils::ToHex((u32)this).c_str());
                int          w = mFont->getTextWidth(str, 0, 1);
                int          h = mFont->getTextHeight(str, 0, 1);
                GuiComponent::drawRect(0, 0, w + 10, h + 10, Color(0, 0, 0, 0.5f));
                mFont->drawWithShadow(2, 5, 5, str, Color(0, 1, 0), 0, -1);
            }

            if (useScreen & UseScreen::Bottom)
            {
                mBackgroundFrame->draw(Tessellator::instance, 0, 0);
                mBackground->draw(Tessellator::instance, 6, 30);
                mSprite1->render();
                Screen::render(touchX, touchY, useScreen, tick);
            }
        }

    private:
        gstd::unique_ptr<NinePatchLayer> mBackgroundFrame;
        gstd::unique_ptr<NinePatchLayer> mBackground;
        gstd::unique_ptr<Sprite>         mSprite1;
    };
}    // namespace MC3DSPluginFramework