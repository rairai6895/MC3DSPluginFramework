#pragma once

#include "Minecraft/Common/Logger.hpp"

namespace MC3DSPluginFramework
{
    // "C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\src-deps\\Input\\RectangleArea.cpp"
    class RectangleArea
    {
    public:
        RectangleArea();
        RectangleArea(float x0, float y0, float x1, float y1, bool checkForValidity);

    private:
        float x0, y0, x1, y1;
    };
}    // namespace MC3DSPluginFramework