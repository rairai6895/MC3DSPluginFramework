#pragma once

#include "Minecraft/Common/Client/Locale/Language.hpp"
#include "Screen.hpp"

namespace MC3DSPluginFramework
{
    class NinePatchLayer;

    class PauseScreen : public Screen, public GuiElement_UnknownClass1
    {
        USE_GAME_ALLOCATOR
    private:
        void buildBackground();

    public:
        PauseScreen(MinecraftGame *minecraftGame, ClientInstance *clientInstance);
        ~PauseScreen() override;
        bool         onBack(int p1) override;
        bool         Unknown40() override;
        int          getUseScreen() override;
        gstd::string getName() override;
        void         render(int touchX, int touchY, int useScreen, float tick) override;
        void         setupComponents() override;
        void         buttonPressed(BaseButton &button) override;
        virtual void renderBottom();
        virtual void renderTop();

    private:
        // 0x99D898

        gstd::unique_ptr<NinePatchLayer> mBackgroundFrame;    // +0x94
        gstd::unique_ptr<NinePatchLayer> mBackground;    // +0x98
        gstd::unique_ptr<Sprite>         mSprite1;    // +0x9C
        gstd::unique_ptr<Sprite>         mSprite2;    // +0xA0
        bool                             mClosed;    // +0xA4
    };
}    // namespace MC3DSPluginFramework