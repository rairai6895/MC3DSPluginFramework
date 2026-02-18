#pragma once

#include "Minecraft/Common/World/Level/BlockPos.hpp"
#include "Minecraft/Common/World/Level/BlockSource.hpp"

namespace MC3DSPluginFramework
{
    class BlockSource;

    class Block
    {
    public:
        static inline Block **mBlocks = (Block **)0xB10520;

        Block(gstd::string name, u8 id, u32 unknown)
        {
            reinterpret_cast<void (*)(Block *, gstd::string, u8, u32)>(0x5BDA9C)(this, name, id, unknown);
        }

        virtual ~Block();

        static Block *lookupByName(gstd::string name)
        {
            return reinterpret_cast<Block *(*)(gstd::string)>(0x5BD34C)(name);
        }

        u8 getId(void) const { return mId; }
        gstd::string getTileName(void) const { return mDescriptionId; }
        gstd::string getName(void) const { return mName; }

        // FUN_0x71F980
        bool isType(const Block *type) const
        {
            return this == type;
        }

        void scheduleTick(BlockSource *bs, const BlockPos &pos, Block *target, u32 tick)
        {
            reinterpret_cast<bool (*)(Block *, BlockSource *, const BlockPos &, Block *, u32)>(0x6953EC)(this, bs, pos, target, tick);
        }

        void scheduleNeighborTick(BlockSource *bs, const Vec3_Int &pos);

        // FUN_0x71FCEC
        bool isTransparent(void) const
        {
            bool *ptr = (bool *)0xB10020;
            return ptr[mId];
        }

        // FUN_0x71E670
        bool hasBlockEntity(void) const
        {
            return mBlockEntityType != BlockEntityType::None;
        }

    private:
        // size 0x274
        // u32 mVtable;    // +0x118 = entityInside(Block*,BlockSource*,Vec3_Int, Entity*)
        u8 mId;
        gstd::string mDescriptionId;
        gstd::string mName;
        u32 mUnk1;
        u32 mUnk2;
        BlockEntityType mBlockEntityType;
        u8 mUnk3;
        float mUnk4;
        u32 mUnk5;
        u8 mUnk6;
        u8 mUnk7;
        // ...
    };
}    // namespace MC3DSPluginFramework