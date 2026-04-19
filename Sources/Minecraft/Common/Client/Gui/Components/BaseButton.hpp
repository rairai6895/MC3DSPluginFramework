#pragma once

#include "GuiElement.hpp"

namespace MC3DSPluginFramework
{
    class Screen_UnknownClass2;

    class BaseButton : public GuiElement
    {
        USE_GAME_ALLOCATOR
    public:
        friend class Hooks;    // バグ修正用

        int getId()
        {
            return mId;
        }

        // ゲーム内関数呼び出ししかしてないコンストラクタ用のデフォルトコンストラクタ
        BaseButton() = default;

        BaseButton(MinecraftGame *minecraftGame, int id, int x, int y, int w, int h, gstd::string localizeKey, bool visualPressOnDrag);
        BaseButton(MinecraftGame *minecraftGame, int id, gstd::string localizeKey, bool visualPressOnDrag);
        BaseButton(MinecraftGame *minecraftGame, int id, int x, int y, gstd::string localizeKey);
        ~BaseButton() override = default;

        void         render(MinecraftGame *minecraftGame, int touchX, int touchY) override;
        bool         onTouchDown(MinecraftGame *minecraftGame, int touchX, int touchY) override;
        bool         onTouchRelease(MinecraftGame *minecraftGame, int touchX, int touchY) override;
        void         Unknown22(int p1) override;
        virtual bool isHovered(int touchX, int touchY);
        virtual void stopDragging();
        virtual void toggleDragging();
        virtual void setDragging(bool set);
        virtual void Unknown29() = delete;    // +0x90
        virtual void Unknown30() = delete;    // +0x94
        virtual void setLabel();
        virtual u8   Unknown31(int p1);
        virtual void renderBackground(MinecraftGame *minecraftGame, int touchX, int touchY);
        virtual void drawLabel(int touchX, int touchY);

    protected:
        void init(MinecraftGame *minecraftGame, int id, bool p3, const gstd::string &localizeKey);

        bool FUN_005e6338(int touchX, int touchY)
        {
            if (!mDragging)
                return false;

            return (GuiElement::isInside(touchX, touchY) || mVisualPressOnDrag);
        }

    public:
        // 0x9CB60C

        char                  mUnk1;    // +0x38
        Color                 mLabelColor;    // +0x3C
        Color                 mPressedLabelColor;    // +0x4C
        Color                 mUnk4;    // +0x5C
        gstd::string          mLocalizeKey;    // +0x6C
        gstd::string          mLabel;    // +0x70
        MinecraftGame        *mMinecraftGame;    // +0x74
        int                   mId;    // +0x78
        bool                  mVisualPressOnDrag;    // +0x7C
        bool                  mDragging;    // +0x7D
        bool                  mUnk8;    // +0x7E
        int                   mUnk9;    // +0x80 ラベル表示のモードフラグ
        Screen_UnknownClass2 *mScreen_UnknownClass2;    // +0x84 押したときの処理を実行するためのもの？(親Screenのポインタ)
        int                   mLabelWidth;    // +0x88
    };
}    // namespace MC3DSPluginFramework