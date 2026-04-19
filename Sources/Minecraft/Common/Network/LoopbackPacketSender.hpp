#pragma once

#include "Minecraft/gstd/gstd.hpp"

namespace MC3DSPluginFramework
{
    class NetworkHandler;

    // "C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\src\\common\\network\\LoopbackPacketSender.cpp"
    class LoopbackPacketSender
    {
    public:
        virtual ~LoopbackPacketSender() = default;

        // FUN_0x3F4908
        // +0x8
        virtual void send(void *packet);

    private:
        // 0x9BEA88

        void                               *m0x4;
        gstd::vector<gstd::type_unknown<>> *m0x8;
        void                               *m0x14;
    };
}    // namespace MC3DSPluginFramework