#pragma once

#include "Minecraft/Common/World/Level/BlockEntity/BlockEntity.hpp"
#include "Minecraft/Common/World/Level/BlockEntity/ContainerBlockEntity.hpp"

namespace MC3DSPluginFramework
{
    // "C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\src\\common\\world\\level\\block\\entity\\ChestBlockEntity.cpp"
    class ChestBlockEntity : public BlockEntity, public ContainerBlockEntity
    {
        USE_GAME_ALLOCATOR
    public:
        ~ChestBlockEntity() override;

        bool canPairWith(const ChestBlockEntity *other, const BlockPos &pos)
        {
            return reinterpret_cast<bool (*)(const ChestBlockEntity *, const ChestBlockEntity *, const BlockPos &)>(0x30BC40)(this, other, pos);
        }

        void triggerEvent(bool unknown, int b1)
        {
            reinterpret_cast<void (*)(ChestBlockEntity *, bool, int)>(0x30BE94)(this, unknown, b1);
        }

        void _validatePairedChest(BlockSource *blocksource)
        {
            reinterpret_cast<void (*)(ChestBlockEntity *, BlockSource *)>(0x30C3DC)(this, blocksource);
        }

        void onPlace(BlockSource *blocksource)
        {
            reinterpret_cast<void (*)(ChestBlockEntity *, BlockSource *)>(0x30CE70)(this, blocksource);
        }

        void pairWith(ChestBlockEntity *other, u32 unknown)
        {
            reinterpret_cast<void (*)(ChestBlockEntity *, ChestBlockEntity *, u32)>(0x30D1F4)(this, other, unknown);
        }

        // single chest = 26
        // double chest = 53
        ItemInstance &getItem(int index)
        {
            return reinterpret_cast<ItemInstance &(*)(ChestBlockEntity *, int)>(0x6DC544)(this, index);
        }

    private:
        // 0x9B25A4

        gstd::vector<ItemInstance> mUnk16;
        u32                        mUnk17;
        u32                        mUnk18;
        u32                        mUnk19;
        u32                        mUnk20;
        float                      mAnimSpeed;    // 1
        bool                       mIsEnderChest;    // テクスチャ
        u8                         mUnk21;
        float                      mUnk22;    // 0.5
        float                      mAnimFrame1;
        float                      mAnimFrame2;
        bool                       mOpened;
        u32                        mUnk23;    // 開いてる時間
        u32                        mPairLead;    // bit
        u32                        mUnk24;    // 0
        u32                        mUnk25;    // 0
        BlockEntity               *mLargeChestPaired;
        BlockPos                   mPairPos;
        u32                        mUnk26;
        gstd::map<u32, u32>        mUnk27;
    };
}    // namespace MC3DSPluginFramework