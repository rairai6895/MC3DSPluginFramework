#pragma once

#include "Minecraft/common/Logger.hpp"

namespace MC3DSPluginFramework::Util
{
    // C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\project\\3DS\\..\\..\\src\\common\\util/range.h
    template <typename T>
    inline bool Range(T beginIDX, T endIDX, int STEP)
    {
        bool res = ((STEP > 0 && beginIDX <= endIDX) || (STEP < 0 && beginIDX >= endIDX));

        if (!res) {
            LOG("Malformed iterator", (STEP > 0 && beginIDX <= endIDX) || (STEP < 0 && beginIDX >= endIDX), 0);
        }

        return res;
    }

}    // namespace MC3DSPluginFramework::Util