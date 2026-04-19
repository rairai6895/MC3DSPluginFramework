#pragma once

#include <types.h>

namespace MC3DSPluginFramework::Util
{
    //"C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\project\\3DS\\..\\..\\src\\common\\util/Math.h"
    namespace Math
    {
        inline void memcpy_strided(u32 unk1, u32 unk2, void *unused, u32 unk3)
        {
            reinterpret_cast<void (*)(u32, u32, void *, u32)>(0x157A88)(unk1, unk2, unused, unk3);
        }

    };    // namespace Math
}    // namespace MC3DSPluginFramework::Util