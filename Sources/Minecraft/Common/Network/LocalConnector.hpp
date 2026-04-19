#pragma once

#include "Minecraft/Common/Logger.hpp"

namespace MC3DSPluginFramework
{
    // "C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\src\\common\\network\\LocalConnector.cpp"
    class LocalConnector
    {
    public:
        // FUN_0x26D378
        void addHost()
        {
            if (mHostConnector)
                LOG("We currently only support a single local host connector.", !mHostConnector, 0)

            mHostConnector = this;
        }

    private:
        static inline LocalConnector *&mHostConnector = *(LocalConnector **)0xA32594;
    };
}    // namespace MC3DSPluginFramework