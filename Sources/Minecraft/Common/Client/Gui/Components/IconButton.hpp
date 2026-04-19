#pragma once

#include "../IntRectangle.hpp"
#include "GuiButton.hpp"
#include "Minecraft/Common/Resources/ResourceLocation.hpp"
#include "Sprite.hpp"
#include <limits.h>

namespace MC3DSPluginFramework
{
    class Icon
    {
    public:
    private:
    };

    class IconButton : public GuiButton
    {
        USE_GAME_ALLOCATOR
    public:
        // FUN_0x5D6B58
        IconButton(MinecraftGame *minecraftGame, int id, int x, int y, int w, int h, const char *localizeKey, bool bigIcon) :
            GuiButton(minecraftGame, id, x, y, w, h, localizeKey, false, INT_MAX),
            mIcon(nullptr),
            mIconDraw(0, 0, 1, 1)
        {
            mIconScale = bigIcon ? 2 : 1;
            mUnk2      = 0;
            mUnk3      = false;
        }

        ~IconButton() override = default;

        // +0xA4
        void drawLabel(int touchX, int touchY) override
        {
            reinterpret_cast<void (*)(IconButton *, int, int)>(0x5D67D4)(this, touchX, touchY);
        }

        // 設定が悪いのか、テクスチャがバグったり、適用されなかったりする(呼ぶタイミングが悪いのかもしれない)
        void setTexture(const ResourceLocation &resourceLocation, int u, int v, int w, int h, int p6, const IntRectangle &p7, const IntRectangle &p8, int p9, int p10, bool p11)
        {
            using sig = void (*)(IconButton *, const ResourceLocation &, int, int, int, int, int, const IntRectangle &, const IntRectangle &, int, int, bool);
            sig(0x5D6A50)(this, resourceLocation, u, v, w, h, p6, p7, p8, p9, p10, p11);
        }

    private:
        // 0x9D9F68

        gstd::unique_ptr<Sprite> mIcon;    // +0xA4
        IntRectangle             mIconDraw;    // +0xA8
        int                      mIconScale;    // +0xB8
        int                      mUnk2;    // +0xBC ラベルの表示の仕方のフラグ？
        bool                     mUnk3;    // +0xC0
    };
}    // namespace MC3DSPluginFramework