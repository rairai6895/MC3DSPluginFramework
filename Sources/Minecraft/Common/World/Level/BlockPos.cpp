#include "BlockPos.hpp"
#include "Minecraft/gstd/gstd.hpp"

namespace MC3DSPluginFramework
{
    void BlockPos::_init(int x, int y, int z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    BlockPos::BlockPos()
    {
        _init(0, 0, 0);
    }

    BlockPos::BlockPos(int x, int y, int z)
    {
        _init(x, y, z);
    }

    // FUN_0x64AAB8
    BlockPos::BlockPos(float x, float y, float z)
    {
        _init(gstd::truncf(x), gstd::truncf(y), gstd::truncf(z));
    }

    // FUN_0x64A984
    BlockPos::BlockPos(const Vec3<float> &pos)
    {
        _init(gstd::truncf(pos.x), gstd::truncf(pos.y), gstd::truncf(pos.z));
    }

    const int &BlockPos::operator[](int index) const
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

    int &BlockPos::operator[](int index)
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
}    // namespace MC3DSPluginFramework