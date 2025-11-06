#ifndef STRUCTS_HPP
#define STRUCTS_HPP

#include <cmath>

struct Vec2_Float {
    float x, y;

    inline Vec2_Float operator*(float v) const {
        return {x * v, y * v};
    }

    inline Vec2_Float operator/(float v) const {
        return {x / v, y / v};
    }

    inline float GetMagnitude(void) const {
        return sqrtf(x * x + y * y);
    }

    inline Vec2_Float Normalize(void) const {
        float mag = GetMagnitude();
        if (mag < 1e-6f || mag == 0)
            return {0, 0};
        return *this / mag;
    }
};

struct Vec3_Int;
struct Vec3_Float {
    float x, y, z;

    inline Vec3_Int ToInt(void);

    inline float GetMagnitude(void) const {
        return sqrtf(x * x + y * y + z * z);
    }

    inline Vec3_Float Normalize(void) const {
        float mag = GetMagnitude();
        if (mag < 1e-6f || mag == 0)
            return {0, 0, 0};
        return {x / mag, y / mag, z / mag};
    }
};

struct Vec3_Int {
    int32_t x, y, z;

    inline Vec3_Float ToFloat(void) {
        return Vec3_Float{(float)x, (float)y, (float)z};
    }
};

inline Vec3_Int Vec3_Float::ToInt(void) {
    return Vec3_Int{(int)x, (int)y, (int)z};
}

struct MoveDirection2D {
    Vec2_Float forward;
    Vec2_Float side;
};

struct CameraAngles {
    float pitch;
    float yaw;

    CameraAngles GetRad(void) const {
        return {(float)(-pitch * (M_PI / 180.0f)), ((float)((yaw + 90.0f) * (M_PI / 180.0f)))};
    }

    MoveDirection2D GetMove2D(void) const {
        auto yawRad = GetRad().yaw;
        return {
            cosf(yawRad), sinf(yawRad), cosf(yawRad - M_PI_2), sinf(yawRad - M_PI_2)
        };
    }

    Vec3_Float GetMove3D(void) const {
        auto rad = GetRad();
        return {
            cosf(rad.yaw) * cosf(rad.pitch),
            sinf(rad.pitch),
            sinf(rad.yaw) * cosf(rad.pitch)
        };
    }
};

#endif