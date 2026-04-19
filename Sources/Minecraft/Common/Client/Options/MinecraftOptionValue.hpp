#pragma once

#include "Minecraft/gstd/gstd.hpp"

namespace MC3DSPluginFramework
{
    class MinecraftGame;

    // "C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\src\\common\\client\\options\\MinecraftOptionValue.cpp"
    class MinecraftOptionValue
    {
        USE_GAME_ALLOCATOR
    public:
        MinecraftOptionValue(MinecraftGame *minecraftGame) :
            mMinecraftGame(minecraftGame) {}

        virtual ~MinecraftOptionValue() = default;

        virtual void Unknown1()
        {
            reinterpret_cast<void (*)(MinecraftOptionValue *)>(0x7031C4)(this);
        }

        virtual void Unknown2()
        {
            reinterpret_cast<void (*)(MinecraftOptionValue *)>(0x703400)(this);
        }

        virtual void Unknown3() = delete;

        virtual void setMSAAValue(int msaaValue)
        {
            reinterpret_cast<void (*)(MinecraftOptionValue *, int)>(0x7030A4)(this, msaaValue);
        }

        virtual void Unknown4(u32 unknown)
        {
            reinterpret_cast<void (*)(MinecraftOptionValue *, u32)>(0x703090)(this, unknown);
        }

    private:
        // 0x9BEFD4

        MinecraftGame *mMinecraftGame;
    };
}    // namespace MC3DSPluginFramework