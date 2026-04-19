#pragma once

#include "Minecraft/src-deps/Audio/FMOD/SoundSystemFMOD.hpp"
#include <cstdint>

namespace MC3DSPluginFramework
{

    /*
    enum class SoundId : unsigned int {
        drop      = 0xFEF3C533,
        gui       = 0x7E943735,
        slime     = 0xFE381B52,
        villager1 = 0xFF314F3B,
        drink     = 0xFDC887FF,
        cat1      = 0xFD07C62A,
        unk1      = 0xFC230935,    // コウモリ？
    };
    */

    class SoundEngine
    {
    public:
        virtual ~SoundEngine();
        virtual void Unknown1();
        virtual void play(u32 hashId, float volume, float pitch);

    private:
        // 0x99E740

        int             mUnk1;
        SoundSystemFMOD mSoundSystemFMOD;
    };
}    // namespace MC3DSPluginFramework