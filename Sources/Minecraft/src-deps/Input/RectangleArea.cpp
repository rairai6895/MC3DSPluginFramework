#include "RectangleArea.hpp"

namespace MC3DSPluginFramework
{
    // FUN_0x23AAA0
    RectangleArea::RectangleArea() :
        x0(0), y0(0), x1(0), y1(0) {}

    // FUN_0x23A9D4
    RectangleArea::RectangleArea(float x0, float y0, float x1, float y1, bool checkForValidity) :
        x0(x0), y0(y0), x1(x1), y1(y1)
    {
        if (!((x0 <= x1 && y0 <= y1) || (checkForValidity == false)))
            LOG("Invalid rectangle area", (x0 <= x1 && y0 <= y1) || (checkForValidity == false), 0);
    }
}    // namespace MC3DSPluginFramework