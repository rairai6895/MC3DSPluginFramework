#pragma once

#include "Minecraft/gstd/gstd.hpp"

namespace MC3DSPluginFramework
{
    // "C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\src\\common\\world\\level\\biome\\Biome.cpp"
    class Biome
    {
        USE_GAME_ALLOCATOR
    public:
        ~Biome();

        void setSnowAccumulation(float maxSnowLevel, float minSnowLevel)
        {
            reinterpret_cast<void (*)(Biome *, float, float)>(0x59F17C)(this, maxSnowLevel, minSnowLevel);
        }

        int getMobs(u32 unknown)
        {
            return reinterpret_cast<int (*)(Biome *, u32)>(0x59FA7C)(this, unknown);
        }

    private:
        static inline Biome **biomes = (Biome **)0xB0F8F0;

        void             *mUnk1;
        gstd::vector<u32> mUnk2;
        gstd::vector<u32> mUnk3;
        gstd::vector<u32> mUnk4;
        u32               mUnk5[3];    // vector?
        gstd::string      mName;
        u32               mUnk6;    // 0xFF700000
        u32               mUnk7;    // 0xFF700000
        u32               mUnk8;    // 0x34030002
        u32               mUnk9;    // 0x004EE031
        float             mUnk10;    // 0x3F000000
        float             mUnk11;    // 0x3F000000
        float             mUnk12;    // 0
        float             mUnk13;    // 0
        float             mUnk14;    // 0
        float             mUnk15;    // 0x3E000000
        float             mUnk16;    // 0xBF800000
        float             mUnk17;    // 0x3DCCCCCD
        float             mUnk18;    // 0x3F189899
        float             mUnk19;    // 0x3F68E8EA
        float             mUnk20;    // 0x3F800000
        float             mUnk21;    // 0
        float             mUnk22;    // 0x3CA0A0A1
        float             mUnk23;    // 0x3CA0A0A1
        float             mUnk24;    // 0x3E48C8CA
        u32               mUnk25;
        u32               mUnk26;
        u32               mUnk27;
        void             *mUnk28;
    };
}    // namespace MC3DSPluginFramework