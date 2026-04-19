#pragma once

#include "GuiButton.hpp"

namespace MC3DSPluginFramework
{
    // "C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\src\\common\\client\\gui\\components\\Button.cpp"
    class Button : public GuiButton
    {
        USE_GAME_ALLOCATOR
    public:
        // エンチャントテーブルの、3つのボタンのアイコン(経験値オーブと数字が書いてある)をセットする関数
        void _initIcons(int level)
        {
            reinterpret_cast<void (*)(Button *, int)>(0x5D82D0)(this, level);
        }

    private:
        char todo[0x10];
    };
}    // namespace MC3DSPluginFramework