#pragma once

#include "Minecraft/Common/Logger.hpp"
#include "Minecraft/Common/World/Level/BlockPos.hpp"
#include "Minecraft/Common/World/Phys/Vec3.hpp"
#include <types.h>

namespace MC3DSPluginFramework
{
    class BlockPos;

    class Vec3
    {
    public:
        float x, y, z;

    public:
        void _init(float x, float y, float z)
        {
            this->x = x;
            this->y = y;
            this->z = z;
        }

        Vec3() = default;

        Vec3(float x, float y, float z)
        {
            _init(x, y, z);
        }

        explicit Vec3(const BlockPos &pos);

        // LOG呼び出しでlineが違うのがあるのでほぼ確定でconstと非constのoperator[]が定義されている

        const float &operator[](int index) const
        {
            if (index == 0)
                return x;

            if (index == 1)
                return y;

            if (index == 2)
                return z;

            LOG("Invalid index for Vec3, valid is [0,2]", false, 0);

            return x;
        }

        float &operator[](int index)
        {
            if (index == 0)
                return x;

            if (index == 1)
                return y;

            if (index == 2)
                return z;

            LOG("Invalid index for Vec3, valid is [0,2]", false, 0);

            return x;
        }

        // FUN_0x71DCD4
        Vec3 operator+(const Vec3 &other)
        {
            return { this->x + other.x, this->y + other.y, this->z + other.z };
        }
    };
}    // namespace MC3DSPluginFramework