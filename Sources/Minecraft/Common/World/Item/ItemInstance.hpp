#pragma once

#include "Minecraft/Common/NBT/CompoundTag.hpp"
#include "Minecraft/Helper/GameEnums.hpp"

namespace MC3DSPluginFramework
{
    struct EnchantStatus
    {
        EnchantId id;
        s16       level;
    };

    class Item;
    class Block;

    // "C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\src\\common\\world\\item\\ItemInstance.cpp"
    // "C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\project\\3DS\\..\\..\\src\\common\\world/item/ItemInstance.h"
    class ItemInstance
    {
        USE_GAME_ALLOCATOR
    public:
        static inline ItemInstance &EMPTY_ITEM = *(ItemInstance *)0xB0E21C;

        ItemInstance();
        ItemInstance(u16 id, u8 count, u16 dataValue);
        ItemInstance(Item *item);
        ItemInstance(Item *item, u8 count);
        ItemInstance(Item *item, u8 count, u16 dataValue);
        ItemInstance(Block *block);
        ItemInstance(Block *block, u8 count);
        ItemInstance(Block *block, u8 count, u16 dataValue);

        ItemInstance(const CompoundTag &item);
        ItemInstance(const ItemInstance &other);
        ItemInstance(ItemInstance &&other) noexcept;
        ~ItemInstance() = default;    // FUN_0x1D295C

        ItemInstance &operator=(const ItemInstance &other);
        ItemInstance &operator=(ItemInstance &&other) noexcept;

        bool                          isType(const Item *type) const;
        u16                           getAuxValue();
        void                          setAuxValue(u16 set);
        gstd::unique_ptr<CompoundTag> toNbt() const;
        void                          init(u16 id, u8 count, u16 dataValue);
        void                          set(u8 inCount);
        void                          sub(u8 count);
        u8                            getMaxStackSize() const;
        void                          setStackSize(u8 inCount);
        u16                           getId() const;
        bool                          isNull() const;
        bool                          isArmor() const;
        bool                          isWearableItem() const;
        u8                            getSlotForItem() const;
        ItemInstance                 &setNull();
        int                           getBaseRepairCost() const;
        bool                          isEnchanted() const;
        gstd::vector<EnchantStatus>   getEnchants() const;
        void                          setEnchants(const gstd::vector<EnchantStatus> &enchants);
        gstd::string                  getName() const;
        gstd::string                  getNoFormatedName() const;
        gstd::string                  getRawName() const;
        bool                          isNamed() const;
        gstd::string                  givenName() const;
        void                          setName(gstd::string name);

    public:
        u8                            mCount;    // +0x0
        u16                           mDataValue;    // +0x2 auxvalue
        bool                          mUnk1;    // +0x4
        gstd::unique_ptr<CompoundTag> mNbt;    // +0x8
        Item                         *mItem;    // +0xC
        Block                        *mBlock;    // +0x10
        u16                           mCategory;    // +0x14
        u16                           mNumber;    // +0x16
        gstd::vector<Block *>         mUnk2;    // +0x18
        gstd::vector<Block *>         mUnk3;    // +0x24
    };

    struct ArmorSlots
    {
        ItemInstance helmet, chestplate, leggings, boots;
    };

}    // namespace MC3DSPluginFramework