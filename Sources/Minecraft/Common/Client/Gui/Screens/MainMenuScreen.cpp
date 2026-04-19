#include "Minecraft/Common/Client/Gui/Screens/MainMenuScreen.hpp"
#include "../Components/IconButton.hpp"
#include "Minecraft/Common/Client/Game/MinecraftGame.hpp"
#include "Minecraft/Common/Client/Gui/Components/SkinRenderer.hpp"
#include "Minecraft/Common/Client/Gui/Gui/Font.hpp"
#include "Minecraft/Common/Client/Input/ClientInputHandler.hpp"
#include "Minecraft/Common/Client/Player/SkinRepository.hpp"

namespace MC3DSPluginFramework
{
    // FUN_0x26F8F4
    MainMenuScreen::MainMenuScreen(MinecraftGame *minecraftGame, ClientInstance *clientInstance, CubemapBackgroundScreen *cubemapBackgroundScreen) :
        Screen(minecraftGame, clientInstance),
        mCubemapBackgroundScreen(cubemapBackgroundScreen),
        mDrawPopUp(false),
        mUnk26(0),
        mUnk27(0),
        mUnk28(0),
        mUnk29(0),
        mUnk30(0),
        mUnk31(0),
        mUnk32(0),
        mCopyrightDrawX(0),
        mVersion(getVersionString()),
        mVersionDrawX(0)
    {
        ClientInputHandler &ctrl = minecraftGame->getClientInputHandler();
        mUnk36                   = ctrl.FUN_0012d628("button.menu_ok");
        mUnk37                   = ctrl.FUN_0012d628("button.menu_cancel");
    }

    // FUN_0x26FA34
    // +0x0
    MainMenuScreen::~MainMenuScreen()
    {
        *(bool *)0xA35877 = false;
    }

    // FUN_0x26F894
    // +0x38
    void MainMenuScreen::Unknown13()
    {
        if (!mSkinRenderer)
            return;

        Skin *curSkin = mMinecraftGame->getSkinRepository().getCurrentSkin();

        if (mSkinRenderer->getSkin() != curSkin)
            mSkinRenderer->setSkin(curSkin);

        mSkinRenderer->tick();
    }

    // FUN_0x26E9A8
    // +0x78
    bool MainMenuScreen::onBack(int p1)
    {
        return true;
    }

    // FUN_0x6CD1A8
    // +0xF0
    int MainMenuScreen::getUseScreen()
    {
        return UseScreen::Both;
    }

    // FUN_0x6CD188
    // +0xF4
    gstd::string MainMenuScreen::getName()
    {
        return "main_menu";
    }

    // FUN_0x26E628
    // +0x110
    void MainMenuScreen::render(int touchX, int touchY, int useScreen, float tick)
    {
        reinterpret_cast<void (*)(MainMenuScreen *, int, int, int, float)>(0x26E628)(this, touchX, touchY, useScreen, tick);
    }

    // FUN_0x26EDA4
    // +0x114
    void MainMenuScreen::setupComponents()
    {
        IntRectangle uv1(64, 144, 8, 8);
        IntRectangle uv2(56, 144, 8, 8);

        ResourceLocation &location = *(ResourceLocation *)0xABFD74;
        constexpr int     x = 110, w = 200, h = 28, iconW = 16, iconH = 16;
        int               y = 15;

        BoxedPtr::Shared<IconButton> playButton(gstd::make_unique<IconButton>(mMinecraftGame, 0, x, y, w, h, "menu.play", false));
        playButton->setTexture(location, 224, 128, iconW, iconH, 0, uv1, uv2, 2, 2, 0);
        mButtons.push_back(std::move(playButton));
        y += 30;

        BoxedPtr::Shared<IconButton> multiPlayerButton(gstd::make_unique<IconButton>(mMinecraftGame, 5, x, y, w, h, "menu.multiplayer", false));
        multiPlayerButton->setTexture(location, 224, 128, iconW, iconH, 0, uv1, uv2, 2, 2, 0);
        mButtons.push_back(std::move(multiPlayerButton));
        y += 30;

        BoxedPtr::Shared<IconButton> optionsButton(gstd::make_unique<IconButton>(mMinecraftGame, 1, x, y, w, h, "menu.options", false));
        optionsButton->setTexture(location, 224, 144, iconW, iconH, 0, uv1, uv2, 2, 2, 0);
        mButtons.push_back(std::move(optionsButton));
        y += 30;

        BoxedPtr::Shared<IconButton> skinsButton(gstd::make_unique<IconButton>(mMinecraftGame, 2, x, y, w, h, "menu.skins", false));
        skinsButton->setTexture(location, 224, 176, iconW, iconH, 0, uv1, uv2, 2, 2, 0);
        mButtons.push_back(std::move(skinsButton));
        y += 30;

        BoxedPtr::Shared<IconButton> guiAchievementsButton(gstd::make_unique<IconButton>(mMinecraftGame, 3, x, y, w, h, "gui.achievements", false));
        guiAchievementsButton->setTexture(location, 224, 160, iconW, iconH, 0, uv1, uv2, 2, 2, 0);
        mButtons.push_back(std::move(guiAchievementsButton));
        y += 30;

        BoxedPtr::Shared<IconButton> manualButton(gstd::make_unique<IconButton>(mMinecraftGame, 4, x, y, w, h, "menu.manual", false));
        manualButton->setTexture(location, 240, 128, iconW, iconH, 0, uv1, uv2, 2, 2, 0);
        mButtons.push_back(std::move(manualButton));
        y += 30;

        BoxedPtr::Shared<IconButton> storeButton(gstd::make_unique<IconButton>(mMinecraftGame, 6, x, y, w, h, "menu.store", false));
        storeButton->setTexture(location, 240, 144, iconW, iconH, 0, uv1, uv2, 2, 2, 0);
        mButtons.push_back(std::move(storeButton));

        mSkinRenderer = gstd::make_unique<SkinRenderer>(mMinecraftGame, 50, 80, 5.f, SkinRenderer::Mode::ControlHead, 1, 5.f);

        // todo: ポップアップ系の処理

        mTabButtons = mButtons;
    }

    // +0x118
    void MainMenuScreen::setupPositions()
    {
        mCopyrightDrawX = 0.f;
        mVersionDrawX   = 320 - mFont->getTextWidth(mVersion, false, 1.f);
    }

    // +0x148
    void MainMenuScreen::Unknown82(int p1, int p2)
    {
        reinterpret_cast<void (*)(MainMenuScreen *, int, int)>(0x26E9B0)(this, p1, p2);
    }

    // +0x164
    void MainMenuScreen::buttonPressed(BaseButton &button)
    {
        reinterpret_cast<void (*)(MainMenuScreen *, BaseButton &)>(0x26E840)(this, button);
    }

    // FUN_0x26E838
    // Screen_UnknownClass2の仮想関数のオーバーライド
    void MainMenuScreen::Unknown1(BaseButton &button)
    {
        MainMenuScreen::buttonPressed(button);
    }

}    // namespace MC3DSPluginFramework