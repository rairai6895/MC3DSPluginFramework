#pragma once

#include "Minecraft/Common/World/Phys/Vec3.hpp"

namespace MC3DSPluginFramework
{
    class AABB
    {
    public:
        Vec3 min;
        Vec3 max;
        bool flag;

    public:
        void _init(float minX, float minY, float minZ, float maxX, float maxY, float maxZ)
        {
            min.x = minX;
            min.y = minY;
            min.z = minZ;
            max.x = maxX;
            max.y = maxY;
            max.z = maxZ;
        }

        AABB(float minX, float minY, float minZ, float maxX, float maxY, float maxZ)
        {
            reinterpret_cast<AABB *(*)(AABB *, float, float, float, float, float, float)>(0x52E428)(this, minX, minY, minZ, maxX, maxY, maxZ);
        }

        AABB(const Vec3 &min, const Vec3 &max)
        {
            reinterpret_cast<AABB *(*)(AABB *, const Vec3 &, const Vec3 &)>(0x52E1E4)(this, min, max);
        }

        // FUN_0x71A330
        AABB(const AABB &other, const Vec3 &offset) :
            AABB({ other.min.x + offset.x, other.min.y + offset.y, other.min.z + offset.z }, { other.max.x + offset.x, other.max.y + offset.y, other.max.z + offset.z }) {}

        AABB(const AABB &other)
        {
            reinterpret_cast<AABB *(*)(AABB *, const AABB &)>(0x7194D8)(this, other);
        }

        bool intersects(const AABB &other) const
        {
            return reinterpret_cast<bool (*)(const AABB *, const AABB &)>(0x71891C)(this, other);
        }
    };
}    // namespace MC3DSPluginFramework