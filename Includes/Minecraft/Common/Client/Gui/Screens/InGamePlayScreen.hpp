#pragma once

#include "Minecraft/Common/Client/Gui/Screens/BaseScreen.hpp"

namespace MC3DSPluginFramework
{
    // "C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\src\\common\\client\\gui\\screens\\InGamePlayScreen.cpp"
    class InGamePlayScreen : public BaseScreen
    {
    public:
        ~InGamePlayScreen() override;

        void _init(void)
        {
            reinterpret_cast<void (*)(InGamePlayScreen *)>(0x31ED44)(this);
        }

    private:
    };
}    // namespace MC3DSPluginFramework