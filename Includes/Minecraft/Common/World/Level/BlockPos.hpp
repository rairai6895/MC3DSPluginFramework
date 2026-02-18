#pragma once

#include "Minecraft/Common/World/Phys/Vec3.hpp"
#include "Minecraft/Helper/GameStructs.hpp"

namespace MC3DSPluginFramework
{
    class Vec3;

    class BlockPos
    {
    public:
        int x, y, z;

    public:
        void _init(int x, int y, int z)
        {
            this->x = x;
            this->y = y;
            this->z = z;
        }

        BlockPos()
        {
            _init(0, 0, 0);
        }

        BlockPos(int x, int y, int z)
        {
            _init(x, y, z);
        }

        // FUN_0x64AAB8
        BlockPos(float x, float y, float z)
        {
            _init(gstd::truncf(x), gstd::truncf(y), gstd::truncf(z));
        }

        explicit BlockPos(const Vec3 &pos);

        const int &operator[](int index) const
        {
            if (index == 0)
                return x;

            if (index == 1)
                return y;

            if (index == 2)
                return z;

            LOG("Invalid index for BlockPos, valid is [0,2]", false, 0);

            return x;
        }

        int &operator[](int index)
        {
            if (index == 0)
                return x;

            if (index == 1)
                return y;

            if (index == 2)
                return z;

            LOG("Invalid index for BlockPos, valid is [0,2]", false, 0);

            return x;
        }
    };
}    // namespace MC3DSPluginFramework