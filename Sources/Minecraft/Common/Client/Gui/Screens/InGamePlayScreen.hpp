#pragma once

#include "Screen.hpp"

namespace MC3DSPluginFramework
{
    // "C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\src\\common\\client\\gui\\screens\\InGamePlayScreen.cpp"
    class InGamePlayScreen : public Screen
    {
    public:
        ~InGamePlayScreen() override;

        void _init(int width, int height) override
        {
            reinterpret_cast<void (*)(InGamePlayScreen *, int, int)>(0x31ED44)(this, width, height);
        }

        gstd::string getName() override
        {
            return "in_game_play_screen";
        }

    private:
    };
}    // namespace MC3DSPluginFramework