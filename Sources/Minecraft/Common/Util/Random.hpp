#pragma once

#include "Minecraft/Common/Logger.hpp"
#include "Minecraft/gstd/gstd.hpp"

namespace MC3DSPluginFramework
{
    // C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\project\\3DS\\..\\..\\src\\common\\util/Random.h
    class Random
    {
        USE_GAME_ALLOCATOR
    public:
        Random(u32 seed) :
            mSeed(seed)
        {
            init_genrand(seed);
        }

        // FUN_0x61E680
        int nextInt(int n)
        {
            // n < 1
            if (!(n > 0))
            {
                LOG("Can't generate a number in [0,0)", n > 0, 0);

                if (n == 0)
                    return 0;
            }

            u32 i         = genrand_int32();
            u32 quotient  = i / n;
            u32 remainder = i % n;
            return ((uint64_t)quotient << 32) | remainder;
        }

    private:
        void init_genrand(u32 seed)
        {
            mMt[0] = seed;
            for (mMti = 1; mMti < MT_N; ++mMti)
            {
                u32 prev  = mMt[mMti - 1];
                mMt[mMti] = MT_INIT_MULTIPLIER * (prev ^ prev >> 30) + mMti;
            }
            mN = MT_N;    // inline展開されてて必要か分からない
        }

        u32 genrand_int32()
        {
            return reinterpret_cast<u32 (*)(Random *)>(0x61E2A8)(this);
        }

    private:
        static constexpr int MT_N               = 624;    // 0x270
        static constexpr int MT_M               = 397;    // 0x18D
        static constexpr int MT_INIT_MULTIPLIER = 0x6C078965;

        u32 mSeed;    // 0xFFFFFFFF seed?
        u32 mMt[624];
        u32 mMti;
        u32 mUnk4;    // bool?
        u32 mUnk5;    // float?
        u32 mN;
    };
}    // namespace MC3DSPluginFramework