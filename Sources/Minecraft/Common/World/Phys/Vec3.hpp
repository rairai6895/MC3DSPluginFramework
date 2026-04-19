#pragma once

#include "Minecraft/Common/Logger.hpp"
#include "Minecraft/Common/World/Level/BlockPos.hpp"
#include <types.h>

namespace MC3DSPluginFramework
{
    // "C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\project\\3DS\\..\\..\\src\\common\\world/phys/Vec3.h"
    template <typename T>
    class Vec3
    {
    public:
        T x, y, z;

    public:
        void init(T x, T y, T z)
        {
            this->x = x;
            this->y = y;
            this->z = z;
        }

        Vec3() = default;

        Vec3(T x, T y, T z)
        {
            init(x, y, z);
        }

        const T &operator[](int index) const
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

        T &operator[](int index)
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

        Vec3 &operator+=(const Vec3 &other)
        {
            this->x += other.x;
            this->y += other.y;
            this->z += other.z;

            return *this;
        }

        Vec3 &operator+=(T v)
        {
            this->x += v;
            this->y += v;
            this->z += v;

            return *this;
        }

        Vec3 &operator-=(const Vec3 &other)
        {
            this->x -= other.x;
            this->y -= other.y;
            this->z -= other.z;

            return *this;
        }

        Vec3 &operator-=(T v)
        {
            this->x -= v;
            this->y -= v;
            this->z -= v;

            return *this;
        }

        Vec3 operator+(const Vec3 &other)
        {
            return { this->x + other.x, this->y + other.y, this->z + other.z };
        }

        Vec3 operator+(T v)
        {
            return { this->x + v, this->y + v, this->z + v };
        }

        Vec3 operator-(const Vec3 &other)
        {
            return { this->x - other.x, this->y - other.y, this->z - other.z };
        }

        Vec3 operator-(T v)
        {
            return { this->x - v, this->y - v, this->z - v };
        }

        bool operator==(const Vec3 &other) const
        {
            return (this->x == other.x) && (this->y == other.y) && (this->z == other.z);
        }
    };

    class BlockPos;

    template <>
    class Vec3<float>
    {
    public:
        float x, y, z;

    public:
        void init(float x, float y, float z);
        Vec3() = default;
        Vec3(float x, float y, float z);
        explicit Vec3(const BlockPos &pos);
        const float &operator[](int index) const;
        float       &operator[](int index);
        Vec3<float> &operator+=(const Vec3 &other);
        Vec3<float> &operator+=(float v);
        Vec3<float> &operator-=(const Vec3 &other);
        Vec3<float> &operator-=(float v);
        Vec3<float>  operator+(const Vec3<float> &other);
        Vec3<float>  operator+(float v);
        Vec3         operator-(const Vec3<float> &other);
        Vec3         operator-(float v);
        bool         operator==(const Vec3<float> &other) const;
        float        length() const;
    };

}    // namespace MC3DSPluginFramework