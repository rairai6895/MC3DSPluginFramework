#include "Minecraft/Common/World/Phys/Vec3.hpp"
#include "Minecraft/Common/World/Level/BlockPos.hpp"
#include <cmath>

namespace MC3DSPluginFramework
{
    void Vec3<float>::init(float x, float y, float z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    Vec3<float>::Vec3(float x, float y, float z)
    {
        init(x, y, z);
    }

    // FUN_0x582C7C
    Vec3<float>::Vec3(const BlockPos &pos)
    {
        init(pos.x, pos.y, pos.z);
    }

    const float &Vec3<float>::operator[](int index) const
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

    float &Vec3<float>::operator[](int index)
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

    Vec3<float> &Vec3<float>::operator+=(const Vec3<float> &other)
    {
        this->x += other.x;
        this->y += other.y;
        this->z += other.z;

        return *this;
    }

    Vec3<float> &Vec3<float>::operator+=(float v)
    {
        this->x += v;
        this->y += v;
        this->z += v;

        return *this;
    }

    Vec3<float> &Vec3<float>::operator-=(const Vec3 &other)
    {
        this->x -= other.x;
        this->y -= other.y;
        this->z -= other.z;

        return *this;
    }

    Vec3<float> &Vec3<float>::operator-=(float v)
    {
        this->x -= v;
        this->y -= v;
        this->z -= v;

        return *this;
    }

    // FUN_0x71DCD4
    Vec3<float> Vec3<float>::operator+(const Vec3<float> &other)
    {
        return { this->x + other.x, this->y + other.y, this->z + other.z };
    }

    Vec3<float> Vec3<float>::operator+(float v)
    {
        return { this->x + v, this->y + v, this->z + v };
    }

    Vec3<float> Vec3<float>::operator-(const Vec3<float> &other)
    {
        return { this->x - other.x, this->y - other.y, this->z - other.z };
    }

    Vec3<float> Vec3<float>::operator-(float v)
    {
        return { this->x - v, this->y - v, this->z - v };
    }

    bool Vec3<float>::operator==(const Vec3<float> &other) const
    {
        return (this->x == other.x) && (this->y == other.y) && (this->z == other.z);
    }

    float Vec3<float>::length() const
    {
        return sqrt(x * x + y * y + z * z);
    }

}    // namespace MC3DSPluginFramework