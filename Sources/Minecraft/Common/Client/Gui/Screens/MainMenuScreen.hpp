#pragma once

#include "Screen.hpp"

namespace MC3DSPluginFramework
{
    class SkinRenderer;
    class CubemapBackgroundScreen;

    class MainMenuScreen : public Screen
    {
        USE_GAME_ALLOCATOR
    public:
        MainMenuScreen(MinecraftGame *minecraftGame, ClientInstance *clientInstance, CubemapBackgroundScreen *cubemapBackgroundScreen);
        ~MainMenuScreen() override;

        void         Unknown13() override;
        bool         onBack(int p1) override;
        int          getUseScreen() override;
        gstd::string getName() override;
        void         render(int touchX, int touchY, int useScreen, float tick) override;
        void         setupComponents() override;
        void         setupPositions() override;
        void         Unknown82(int p1, int p2) override;
        void         buttonPressed(BaseButton &button) override;
        void         Unknown1(BaseButton &button) override;

    private:
        // FUN_0x5E68DC
        gstd::string getVersionString()
        {
            return "v1.1.7";
        }

    private:
        // 0x9AB390

        gstd::unique_ptr<SkinRenderer>         mSkinRenderer;    // +0x90
        CubemapBackgroundScreen               *mCubemapBackgroundScreen;    // +0x94
        gstd::unique_ptr<gstd::type_unknown<>> mUnk23;    // +0x98
        gstd::string                           mPopUp;    // +0x9C
        gstd::string                           mUnk25;    // +0xA0
        bool                                   mDrawPopUp;    // +0xA4
        bool                                   mUnk26;    // +0xA5
        int                                    mUnk27;    // +0xA8
        int                                    mUnk28;    // +0xAC
        float                                  mUnk29;    // +0xB0
        float                                  mUnk30;    // +0xB4
        float                                  mUnk31;    // +0xB8
        float                                  mUnk32;    // +0xBC
        gstd::string                           mCopyright;    // +0xC0
        float                                  mCopyrightDrawX;    // +0xC4
        gstd::string                           mVersion;    // +0xC8 v1.1.7 Optionsのフラグで描画される
        float                                  mVersionDrawX;    // +0xCC
        short                                  mUnk36;    // +0xD0
        short                                  mUnk37;    // +0xD2
    };
}    // namespace MC3DSPluginFramework