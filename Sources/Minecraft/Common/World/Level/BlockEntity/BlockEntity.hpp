#pragma once

#include "Minecraft/Common/World/Item/ItemInstance.hpp"
#include "Minecraft/Common/World/Phys/AABB.hpp"
#include "Minecraft/gstd/gstd.hpp"

namespace MC3DSPluginFramework
{
    class Block;

    // "C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\src\\common\\world\\level\\block\\entity\\BlockEntity.cpp"
    class BlockEntity
    {
        USE_GAME_ALLOCATOR
    public:
        // createBlockEntity 0x38AC4C

        BlockEntity(BlockEntityType type, const BlockPos &pos);
        virtual ~BlockEntity();

        virtual void vfunc0x8(const CompoundTag &tag)
        {
            if (tag.contains("isMovable"))
                mMovable = tag.getBool("isMovable");

            if (tag.contains("CustomName"))
                mName = tag.getString("CustomName");
        }

        virtual void save(CompoundTag &out)
        {
            auto &blockEntityNameMap = *(gstd::map<BlockEntityType, gstd::string> *)0xB11264;
            auto  it                 = blockEntityNameMap.lower_bound(mType);
            if (it != blockEntityNameMap.end())
            {
            }
        }

        BlockEntityType getType() const
        {
            return mType;
        }

        // FUN_0x173EF0
        void setPos(const BlockPos &pos)
        {
            mPos = pos;
        }

        // FUN_0x173EC8
        bool isType(BlockEntityType type) const
        {
            return mType == type;
        }

    private:
        // 0x9999FC

        int             mRuntime;    // +0x4
        Block          *mBlock;    // +0x8
        float           m0xC;
        float           m0x10;
        float           m0x14;
        float           m0x18;
        float           m0x1C;
        BlockPos        mPos;    // +0x20
        AABB            mAABB;    // +0x2C
        int             m0x48;
        BlockEntityType mType;    // +0x4C
        int             mRunningId;    // +0x50
        u8              m0x54;
        u8              mMovable;
        u8              m0x56;
        u8              m0x57;
        gstd::string    mName;    // +0x58
        bool            mNamed;    // +0x5C
        u8              m0x5D;    // +0x5D
    };
}    // namespace MC3DSPluginFramework