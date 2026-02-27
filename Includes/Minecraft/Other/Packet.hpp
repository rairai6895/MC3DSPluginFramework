#pragma once

#include "Minecraft/gstd/gstd.hpp"

namespace MC3DSPluginFramework
{
    // パケット系は仮想関数だけでメンバ変数は持ってないかも？

    class SendEntityMotionPacket
    {
    public:
        virtual ~SendEntityMotionPacket();

        // getId的なやつかも？
        virtual u32 Unknown1()
        {
            return 0x28;
        }

        virtual gstd::string getPacketName()
        {
            return "SetEntityMotionPacket";
        }

        // todo: パケット系の解析

        virtual void Unknown2();
        virtual void Unknown3();
        virtual void Unknown4();
        virtual void Unknown5();

    private:
    };
}    // namespace MC3DSPluginFramework