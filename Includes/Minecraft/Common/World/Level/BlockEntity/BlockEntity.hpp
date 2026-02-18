#pragma once

#include "Minecraft/Common/World/Item/ItemInstance.hpp"
#include "Minecraft/Common/World/Phys/AABB.hpp"
#include "Minecraft/Helper/GameStructs.hpp"
#include "Minecraft/Helper/Structs.hpp"
#include "Minecraft/gstd/gstd.hpp"

namespace MC3DSPluginFramework
{
    // "C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\src\\common\\world\\level\\block\\entity\\BlockEntity.cpp"
    class BlockEntity
    {
    public:
        // createBlockEntity 0x38AC4C

        virtual ~BlockEntity();
        void operator delete(void *);

        BlockEntityType getType(void) const { return mType; }

        // FUN_0x173EF0
        void setPos(const Vec3_Int &pos) { mPos = pos; }

        // FUN_0x173EC8
        bool isType(BlockEntityType type) const { return mType == type; }

    private:
        u32 mRuntime;
        void *mUnk1;
        u32 mUnk2;
        u32 mUnk3;
        u32 mUnk4;
        u32 mUnk5;
        u32 mUnk6;
        Vec3_Int mPos;
        AABB mAABB;
        u32 mUnk7;    // 0xFFFFFFFF
        BlockEntityType mType;
        u32 mUnk8;    // 6
        u32 mUnk9;    // 0x01010100 bools?
        gstd::string mName;
        bool mIsNamed;
        u8 mUnk10;
    };
}    // namespace MC3DSPluginFramework