#pragma once

#include "Minecraft/Common/Logger.hpp"
#include <types.h>

namespace MC3DSPluginFramework
{
    // "C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\src\\common\\client\\renderer\\entity\\Palette.cpp"
    class Palette
    {
    public:
        // FUN_0x635B04
        static u8 fromByte(u8 ID)
        {
            if (!(ID >= 0 && ID <= 0xF))
                LOG("Invalid color ID", ID >= 0 && ID <= 0xF, 0);

            return ID;
        }

    private:
    };
}    // namespace MC3DSPluginFramework