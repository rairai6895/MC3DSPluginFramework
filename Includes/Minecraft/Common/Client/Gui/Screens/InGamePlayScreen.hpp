#pragma once

#include "C_Screen.hpp"

namespace MC3DSPluginFramework
{
    // "C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\src\\common\\client\\gui\\screens\\InGamePlayScreen.cpp"
    class InGamePlayScreen : public C_Screen
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