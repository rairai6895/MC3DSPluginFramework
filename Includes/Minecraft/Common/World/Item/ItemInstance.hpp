#pragma once

#include "Minecraft/Common/NBT/CompoundTag.hpp"
#include "Minecraft/Common/World/Item/Item.hpp"
#include "Minecraft/Common/World/Level/Block.hpp"
#include "Minecraft/Helper/GameEnums.hpp"
#include "Minecraft/Helper/GameStructs.hpp"
#include "Minecraft/gstd/gstd.hpp"

namespace MC3DSPluginFramework
{
    struct EnchantStatus {
        EnchantId id;
        s16 level;
    };

    class Item;
    class Block;

    // "C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\src\\common\\world\\item\\ItemInstance.cpp"
    // "C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\project\\3DS\\..\\..\\src\\common\\world/item/ItemInstance.h"
    class ItemInstance
    {
    public:
        ItemInstance()
        {
            reinterpret_cast<void (*)(ItemInstance *)>(0x1D28F4)(this);
        };

        ItemInstance(ItemId id, u8 count, u16 dataValue)
        {
            reinterpret_cast<void (*)(ItemInstance *, ItemId, u8, u16)>(0x1D2894)(this, id, count, dataValue);
        }

        ItemInstance(Block *block, u8 count, u16 dataValue)
        {
            reinterpret_cast<void (*)(ItemInstance *, Block *, u8, u16)>(0x1D2704)(this, block, count, dataValue);
        }

        ItemInstance(Item *item)
        {
            reinterpret_cast<ItemInstance *(*)(ItemInstance *, Item *)>(0x1D2444)(this, item);
        }

        ItemInstance(Item *item, u8 count, u16 dataValue)
        {
            reinterpret_cast<ItemInstance *(*)(ItemInstance *, Item *, u8, u16)>(0x1D2510)(this, item, count, dataValue);
        }

        ItemInstance(const CompoundTag *item)
        {
            reinterpret_cast<void (*)(ItemInstance *, const CompoundTag *)>(0x1D1B30)(this, item);
        }

        ItemInstance(const ItemInstance &other)
        {
            reinterpret_cast<void (*)(ItemInstance *, const ItemInstance &)>(0x1D2768)(this, other);
        }

        ItemInstance(ItemInstance &&other) noexcept
        {
            memcpy(this, &other, sizeof(ItemInstance));
            memset(&other, 0, sizeof(ItemInstance));
        }

        ~ItemInstance()
        {
            reinterpret_cast<void (*)(ItemInstance *)>(0x1D295C)(this);
        }

        void *operator new(size_t s) { return gstd::malloc(s); }
        void operator delete(void *m) { gstd::free(m); }

        ItemInstance &operator=(const ItemInstance &other);
        ItemInstance &operator=(ItemInstance &&other) noexcept;

        gstd::unique_ptr<CompoundTag> toNbt(void) const
        {
            return reinterpret_cast<gstd::unique_ptr<CompoundTag> (*)(const ItemInstance *)>(0x6B27B4)(this);
        }

        void init(ItemId id, u8 count, u16 dataValue)
        {
            reinterpret_cast<void (*)(ItemInstance *, ItemId, u8, u16)>(0x1D1A10)(this, id, count, dataValue);
        }

        u8 getMaxStackSize(void) const
        {
            return reinterpret_cast<bool (*)(const ItemInstance *)>(0x6B1DA0)(this);
        }

        void setStackSize(u8 inCount)
        {
            reinterpret_cast<bool (*)(ItemInstance *, u8)>(0x1D0D34)(this, inCount);
        }

        ItemId getId(void) const
        {
            return reinterpret_cast<ItemId (*)(const ItemInstance *)>(0x6B2924)(this);
        }

        bool isEmpty(void) const
        {
            return reinterpret_cast<bool (*)(const ItemInstance *)>(0x6B2954)(this);
        }

        bool isWearableItem(void) const
        {
            return reinterpret_cast<bool (*)(const ItemInstance *)>(0x6B19FC)(this);
        }

        bool isArmor(void) const
        {
            return reinterpret_cast<bool (*)(const ItemInstance *)>(0x6B15A0)(this);
        }

        // 装着可能なアーマースロット番号を返す
        u8 getSlotForItem() const
        {
            return reinterpret_cast<u8 (*)(const ItemInstance *)>(0x666244)(this);
        }

        ItemInstance &setNull(void)
        {
            return reinterpret_cast<ItemInstance &(*)(ItemInstance *)>(0x1D20E0)(this);
        }

        bool isEnchanted(void) const;

        // FUN_0x6B25EC
        gstd::vector<EnchantStatus> getEnchants(void) const;

        // FUN_0x1D1670
        void setEnchants(const gstd::vector<EnchantStatus> &enchants);

        gstd::string getName(void) const;
        gstd::string getNoFormatedName(void) const;
        gstd::string getRawName(void) const;
        bool isNamed(void) const;
        gstd::string givenName(void) const;

        // FUN_0x1D0E28
        void reName(gstd::string name);

        size_t getRepairCost(void) const;
        void setSignTextTag(gstd::string line1, gstd::string line2, gstd::string line3, gstd::string line4);
        void setMonsterSpawnerTag(EntityId id, u16 delay, u16 minSpawnDelay, u16 maxSpawnDelay, u16 spawnCount, u16 maxNearbyEntities, u16 requiredPlayerRange, u16 spawnRange);
        void setUnbreakableTag(void);
        void removeUnbreakableTag(void);
        void setCustomColorTag(const BColor &color);
        void removeCustomColorTag(void);
        void setItemsTag(const std::vector<std::pair<u8, ItemInstance>> &items);
        void setItemsTag(std::vector<std::pair<u8, gstd::unique_ptr<CompoundTag>>> &&items);
        void setItemFrameTag(const ItemInstance &item, u8 rotation);

    public:
        u8 mCount;
        u16 mDataValue;    // auxvalue
        bool mUnk1;
        gstd::unique_ptr<CompoundTag> mNbt;
        Item *mItem;
        Block *mBlock;
        u16 mCategory;
        u16 mNumber;

    private:
        u8 mUnk3[24];
    };

    struct ArmorSlots {
        ItemInstance helmet, chestplate, leggings, boots;
    };

}    // namespace MC3DSPluginFramework