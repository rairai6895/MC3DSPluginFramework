#pragma once

#include <3ds.h>

namespace MC3DSPluginFramework
{
    namespace gctr
    {
        // FUN_0x1241A8
        Handle &gspGetSessionHandle()
        {
            return *(Handle *)0xA35EE4;
        }

        Result GSPGPU_ImportDisplayCaptureInfo(Handle *handle, GSPGPU_CaptureInfo *captureinfo)
        {
            return reinterpret_cast<Result (*)(Handle *, GSPGPU_CaptureInfo *)>(0x4C8ADC)(handle, captureinfo);
        }

    }    // namespace gctr
}    // namespace MC3DSPluginFramework