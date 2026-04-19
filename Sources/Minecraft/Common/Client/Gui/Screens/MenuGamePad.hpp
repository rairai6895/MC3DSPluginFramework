#pragma once

#include "Screen.hpp"

namespace MC3DSPluginFramework
{
    // "C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\src\\common\\client\\gui\\screens\\MenuGamePad.cpp"
    class MenuGamePad
    {
    public:
        // FUN_0x19BE58
        static void setX(int stickId, float set)
        {
            if (!_isValidStick(stickId))
                LOG("Only set valid sticks.", _isValidStick(stickId), 0);

            *(float *)(0xAC0978 + stickId * 4 + -4) = set;
        }

        static void setY(int stickId, float set)
        {
            if (!_isValidStick(stickId))
                LOG("Only set valid sticks.", _isValidStick(stickId), 0);

            *(float *)(0xAC0984 + stickId * 4 + -4) = set;
        }

    private:
        static constexpr bool _isValidStick(int stickId)
        {
            return (stickId >= 1) && (3 >= stickId);
        }
    };
}    // namespace MC3DSPluginFramework