#pragma once

#include "BaseButton.hpp"

namespace MC3DSPluginFramework
{
    class NinePatchLayer;

    class GuiButton : public BaseButton
    {
        USE_GAME_ALLOCATOR
    public:
        GuiButton(MinecraftGame *minecraftGame, int id, int x, int y, int w, int h, const char *localizeKey, bool visualPressOnDrag, int p9);
        ~GuiButton() override;

        void         renderBackground(MinecraftGame *minecraftGame, int touchX, int touchY) override;
        virtual void buildBackground();

    private:
        // 0x9DAB70

        // 未使用？
        int mUnk1;    //+0x8C
        int mUnk2;    //+0x90
        int mUnk3;    //+0x94

        gstd::unique_ptr<NinePatchLayer> mDefaultBackground;    //+0x98
        gstd::unique_ptr<NinePatchLayer> mDownedBackground;    //+0x9C
        gstd::unique_ptr<NinePatchLayer> mInActiveBackground;    //+0xA0
    };
}    // namespace MC3DSPluginFramework