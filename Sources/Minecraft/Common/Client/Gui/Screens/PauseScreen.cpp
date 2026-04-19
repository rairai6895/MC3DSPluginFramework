#include "PauseScreen.hpp"
#include "../Components/NinePatch.hpp"
#include "Minecraft/Common/Client/Game/MinecraftGame.hpp"
#include "Minecraft/Common/Platform/AppPlatform.hpp"

namespace MC3DSPluginFramework
{
    // FUN_0x1A16E8
    void PauseScreen::buildBackground()
    {
        NinePatchFactory factory(mMinecraftGame->getTextures(), *(ResourceLocation *)0xABFD74);

        mBackgroundFrame = factory.createSymmetrical(IntRectangle(56, 160, 8, 8), 2, 2, AppPlatform::BOTTOM_SCREEN_WIDTH, AppPlatform::BOTTOM_SCREEN_HEIGHT);
        mBackground      = factory.createSymmetrical(IntRectangle(80, 176, 8, 8), 3, 3, 308, 204);
    }

    // FUN_0x1A19A8
    PauseScreen::PauseScreen(MinecraftGame *minecraftGame, ClientInstance *clientInstance) :
        Screen(minecraftGame, clientInstance),
        mClosed(false)
    {
    }

    PauseScreen::~PauseScreen() = default;    // FUN_0x1A1A08

    // FUN_0x1A1698
    // +0x78
    bool PauseScreen::onBack(int p1)
    {
        mMinecraftGame->playSound(Util::hashCode("random.click"), 1, 1);

        if (!mClosed)
        {
            mClosed = 1;
            mMinecraftGame->schedulePopScreen(1);
        }

        return true;
    }

    // FUN_0x6A82E0
    // +0xA0
    bool PauseScreen::Unknown40()
    {
        return true;
    }

    // FUN_0x6A82E8
    // +0xF0
    int PauseScreen::getUseScreen()
    {
        return UseScreen::Both;
    }

    // FUN_0x6A82BC
    // +0xF4
    gstd::string PauseScreen::getName()
    {
        return "pause_screen";
    }

    // FUN_0x1A1920
    // +0x110
    void PauseScreen::render(int touchX, int touchY, int useScreen, float tick)
    {
        if (useScreen & UseScreen::Bottom)
        {
            renderBottom();
            Screen::render(touchX, touchY, useScreen, tick);
        }

        if (useScreen & UseScreen::Top)
        {
            renderTop();
        }
    }

    // FUN_0x1A182C
    // +0x114
    void PauseScreen::setupComponents()
    {
        buildBackground();
        // setupButtons();
        reinterpret_cast<void (*)(PauseScreen *)>(0x1A12CC)(this);    // todo
        ResourceLocation &loc = *(ResourceLocation *)0xABFD74;
        mSprite1              = gstd::make_unique<Sprite>(mMinecraftGame, 7, 7, 16, 16, loc, 200, 25, 8, 8);
        mSprite2              = gstd::make_unique<Sprite>(mMinecraftGame, 184, 70, 32, 32, loc, 208, 25, 8, 8);
        Screen::FUN_0061f300(0);
        updateComponentSelections();
    }

    // FUN_0x1A11AC
    // +0x164
    void PauseScreen::buttonPressed(BaseButton &button)
    {
        reinterpret_cast<void (*)(PauseScreen *, BaseButton &)>(0x1A11AC)(this, button);
    }

    // FUN_0x1A0C5C
    // +0x1A0
    void PauseScreen::renderBottom()
    {
        mBackgroundFrame->draw(Tessellator::instance, 0, 0);
        mBackground->draw(Tessellator::instance, 6, 30);
        mSprite1->render();
        GuiComponent::drawCenteredString(mFont, Localization::get("pauseScreen.upper"), AppPlatform::BOTTOM_SCREEN_WIDTH / 2, 7, Color::BLACK, false);
    }

    // FUN_0x1A0D68
    // +0x1A4
    void PauseScreen::renderTop()
    {
        GuiComponent::fill(0, 0, AppPlatform::TOP_SCREEN_WIDTH, AppPlatform::TOP_SCREEN_HEIGHT, Color(0, 0, 0, 0.6275));
        GuiComponent::drawCenteredString(mFont, Localization::get("pauseScreen.header"), AppPlatform::TOP_SCREEN_WIDTH / 2, 177, Color::WHITE, false);
        mSprite2->render();
        renderButtonTips(true, true);
    }
}    // namespace MC3DSPluginFramework