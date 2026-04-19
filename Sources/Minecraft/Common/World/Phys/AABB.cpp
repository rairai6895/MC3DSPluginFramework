#include "AABB.hpp"

namespace MC3DSPluginFramework
{
    void AABB::_init(float minX, float minY, float minZ, float maxX, float maxY, float maxZ)
    {
        min.x = minX;
        min.y = minY;
        min.z = minZ;
        max.x = maxX;
        max.y = maxY;
        max.z = maxZ;
    }

    AABB::AABB(float minX, float minY, float minZ, float maxX, float maxY, float maxZ)
    {
        reinterpret_cast<AABB *(*)(AABB *, float, float, float, float, float, float)>(0x52E428)(this, minX, minY, minZ, maxX, maxY, maxZ);
    }

    AABB::AABB(const Vec3<float> &min, const Vec3<float> &max)
    {
        reinterpret_cast<AABB *(*)(AABB *, const Vec3<float> &, const Vec3<float> &)>(0x52E1E4)(this, min, max);
    }

    // FUN_0x71A330
    AABB::AABB(const AABB &other, const Vec3<float> &offset) :
        AABB(
            { (other.min.x + offset.x), (other.min.y + offset.y), (other.min.z + offset.z) },
            { (other.max.x + offset.x), (other.max.y + offset.y), (other.max.z + offset.z) }
        )
    {
    }

    AABB::AABB(const AABB &other)
    {
        reinterpret_cast<AABB *(*)(AABB *, const AABB &)>(0x7194D8)(this, other);
    }

    bool AABB::intersects(const AABB &other) const
    {
        return reinterpret_cast<bool (*)(const AABB *, const AABB &)>(0x71891C)(this, other);
    }

    // FUN_0x52DCA4
    AABB &AABB::set(const Vec3<float> &min, const Vec3<float> &max)
    {
        this->min.x = min.x;
        this->min.y = min.y;
        this->min.z = min.z;
        this->max.x = max.x;
        this->max.y = max.y;
        this->max.z = max.z;

        if (!(min.x <= max.x))
            LOG("min.x must always be <= max.x", min.x <= max.x, 0);
        if (!(min.y <= max.y))
            LOG("min.y must always be <= max.y", min.y <= max.y, 0);
        if (!(min.z <= max.z))
            LOG("min.z must always be <= max.z", min.z <= max.z, 0);

        Vec3<float> &u = *(Vec3<float> *)0xB1726C;
        this->flag     = min == u && max == u;

        return *this;
    }

    AABB &AABB::grow(const Vec3<float> &v)
    {
        min -= v;
        max += v;

        return *this;
    }
}    // namespace MC3DSPluginFramework