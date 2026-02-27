#pragma once

#include "C_Screen.hpp"

namespace MC3DSPluginFramework
{
    class PauseScreen : public C_Screen
    {
    public:
        gstd::string getScreenName() override
        {
            return "pause_screen";
        }

    private:
    };
}    // namespace MC3DSPluginFramework