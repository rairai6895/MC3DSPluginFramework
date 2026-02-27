#pragma once

#include "C_Screen.hpp"

namespace MC3DSPluginFramework
{
    class MenuGamePad
    {
    public:
        static bool _isValidStick(u32 stickId)
        {
            return (stickId >= 1) && (3 >= stickId);
        }

        void setX(u32 stickId, u32 unknown, float x)
        {
            if (!_isValidStick(stickId))
                LOG("Only set valid sticks.", _isValidStick(stickId), 0);

            *(float *)(0xAC0978 + stickId * 4 + -4) = x;
        }

        void setY(u32 stickId, u32 unknown, float y)
        {
            if (!_isValidStick(stickId))
                LOG("Only set valid sticks.", _isValidStick(stickId), 0);

            *(float *)(0xAC0984 + stickId * 4 + -4) = y;
        }

    private:
    };
}    // namespace MC3DSPluginFramework