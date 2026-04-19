#pragma once

#include "Minecraft/Common/World/Phys/Vec3.hpp"

namespace MC3DSPluginFramework
{
    // "C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\src\\common\\world\\phys\\AABB.cpp"
    class AABB
    {
    public:
        Vec3<float> min;
        Vec3<float> max;
        bool        flag;

    public:
        void _init(float minX, float minY, float minZ, float maxX, float maxY, float maxZ);

        AABB(float minX, float minY, float minZ, float maxX, float maxY, float maxZ);
        AABB(const Vec3<float> &min, const Vec3<float> &max);
        AABB(const AABB &other, const Vec3<float> &offset);
        AABB(const AABB &other);

        bool  intersects(const AABB &other) const;
        AABB &set(const Vec3<float> &min, const Vec3<float> &max);
        AABB &grow(const Vec3<float> &v);
    };
}    // namespace MC3DSPluginFramework