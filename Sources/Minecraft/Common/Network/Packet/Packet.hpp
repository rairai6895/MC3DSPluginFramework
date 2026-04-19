#pragma once

#include "Minecraft/gstd/gstd.hpp"

namespace MC3DSPluginFramework
{
    class Packet
    {
        USE_GAME_ALLOCATOR
    public:
        virtual ~Packet() = default;

        virtual u32          getId()     = 0;    // +0x8
        virtual gstd::string getName()   = 0;    // +0xC
        virtual void         write(...)  = 0;    // +0x10
        virtual void         read(...)   = 0;    // +0x14
        virtual void         vFunc0x18() = 0;
        virtual void         vFunc0x1C() = delete;

    private:
    };

    class SendEntityMotionPacket : public Packet
    {
    public:
        virtual ~SendEntityMotionPacket();

        u32 getId() override
        {
            return 0x28;
        }

        virtual gstd::string getName() override
        {
            return "SetEntityMotionPacket";
        }

    private:
    };
}    // namespace MC3DSPluginFramework