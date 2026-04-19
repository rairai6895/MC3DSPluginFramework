#pragma once

#include "../Phys/Vec3.hpp"

namespace MC3DSPluginFramework
{
    template <typename T>
    class Vec3;

    class BlockPos
    {
    public:
        int x, y, z;

    public:
        static inline BlockPos &MAX = *(BlockPos *)0xB0FDDC;

        void _init(int x, int y, int z);

        BlockPos();
        BlockPos(int x, int y, int z);
        BlockPos(float x, float y, float z);
        explicit BlockPos(const Vec3<float> &pos);

        const int &operator[](int index) const;
        int       &operator[](int index);
    };
}    // namespace MC3DSPluginFramework