#pragma once

#include "Minecraft/gstd/gstd.hpp"

namespace MC3DSPluginFramework
{
    inline gstd::thread::id gMainThread = *(gstd::thread::id *)0xA3596C;
}