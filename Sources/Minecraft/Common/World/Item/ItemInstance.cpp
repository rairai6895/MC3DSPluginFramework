#include "Minecraft/Common/World/Item/ItemInstance.hpp"
#include "Asterium/AstHook/AstHook.hpp"
#include "Item.hpp"
#include "Minecraft/Common/World/Level/Block/Block.hpp"
#include <types.h>

namespace MC3DSPluginFramework
{
    // FUN_0x1D28F4
    ItemInstance::ItemInstance() :
        mCount(0),
        mDataValue(0),
        mUnk1(true),
        mItem(nullptr),
        mBlock(nullptr),
        mCategory(9),
        mNumber(0)
    {
        init(0, 0, 0);
    };

    // FUN_0x1D2894
    ItemInstance::ItemInstance(u16 id, u8 count, u16 dataValue) :
        mCount(0),
        mDataValue(0),
        mUnk1(true),
        mItem(nullptr),
        mBlock(nullptr),
        mCategory(9),
        mNumber(0)
    {
        init(id, count, dataValue);
    }

    // FUN_0x1D2444
    ItemInstance::ItemInstance(Item *item) :
        mCount(0),
        mDataValue(0),
        mUnk1(true),
        mItem(nullptr),
        mBlock(nullptr),
        mCategory(9),
        mNumber(0)
    {
        init(item->getItemId(), 1, 0);
    }

    // FUN_0x1D24AC
    ItemInstance::ItemInstance(Item *item, u8 count) :
        mCount(0),
        mDataValue(0),
        mUnk1(true),
        mItem(nullptr),
        mBlock(nullptr),
        mCategory(9),
        mNumber(0)
    {
        init(item->getItemId(), count, 0);
    }

    // FUN_0x1D2510
    ItemInstance::ItemInstance(Item *item, u8 count, u16 dataValue) :
        mCount(0),
        mDataValue(0),
        mUnk1(true),
        mItem(nullptr),
        mBlock(nullptr),
        mCategory(9),
        mNumber(0)
    {
        init(item->getItemId(), count, dataValue);
    }

    // FUN_0x1D2884
    // FUN_0x1D26F8
    // FUN_0x1D262C
    ItemInstance::ItemInstance(Block *block) :
        mCount(0),
        mDataValue(0),
        mUnk1(true),
        mItem(nullptr),
        mBlock(nullptr),
        mCategory(9),
        mNumber(0)
    {
        init(block->getId(), 1, 0);
    }

    // FUN_0x1D2694
    ItemInstance::ItemInstance(Block *block, u8 count) :
        mCount(0),
        mDataValue(0),
        mUnk1(true),
        mItem(nullptr),
        mBlock(nullptr),
        mCategory(9),
        mNumber(0)
    {
        init(block->getId(), count, 0);
    }

    // FUN_0x1D2704
    ItemInstance::ItemInstance(Block *block, u8 count, u16 dataValue) :
        mCount(0),
        mDataValue(0),
        mUnk1(true),
        mItem(nullptr),
        mBlock(nullptr),
        mCategory(9),
        mNumber(0)
    {
        init(block->getId(), count, dataValue);
    }

    ItemInstance::ItemInstance(const CompoundTag &item)
    {
        reinterpret_cast<void (*)(ItemInstance *, const CompoundTag &)>(0x1D1B30)(this, item);
    }

    ItemInstance::ItemInstance(const ItemInstance &other)
    {
        reinterpret_cast<void (*)(ItemInstance *, const ItemInstance &)>(0x1D2768)(this, other);
    }

    ItemInstance::ItemInstance(ItemInstance &&other) noexcept
    {
        memcpy(this, &other, sizeof(ItemInstance));
        memset(&other, 0, sizeof(ItemInstance));
    }

    // FUN_0x1D2C3C
    ItemInstance &ItemInstance::operator=(const ItemInstance &other)
    {
        this->mCount     = other.mCount;
        this->mDataValue = other.mDataValue;
        this->mUnk1      = other.mUnk1;
        this->mNbt       = other.mNbt ? other.mNbt->_copy() : nullptr;
        this->mItem      = other.mItem;
        this->mBlock     = other.mBlock;
        this->mCategory  = other.mCategory;
        this->mNumber    = other.mNumber;
        this->mUnk2      = other.mUnk2;
        this->mUnk3      = other.mUnk3;

        return *this;
    }

    ItemInstance &ItemInstance::operator=(ItemInstance &&other) noexcept
    {
        if (this != &other)
        {
            gstd::unique_ptr<CompoundTag> tmp(mNbt.get());
            memcpy(this, &other, sizeof(ItemInstance));
            memset(&other, 0, sizeof(ItemInstance));
        }

        return *this;
    }

    bool ItemInstance::isType(const Item *type) const
    {
        return mItem->isType(type);
    }

    u16 ItemInstance::getAuxValue()
    {
        return mDataValue;
    }

    void ItemInstance::setAuxValue(u16 set)
    {
        mDataValue = set;
    }

    gstd::unique_ptr<CompoundTag> ItemInstance::toNbt() const
    {
        return reinterpret_cast<gstd::unique_ptr<CompoundTag> (*)(const ItemInstance *)>(0x6B27B4)(this);
    }

    void ItemInstance::init(u16 id, u8 count, u16 dataValue)
    {
        reinterpret_cast<void (*)(ItemInstance *, u16, u8, u16)>(0x1D1A10)(this, id, count, dataValue);
    }

    // FUN_0x1D179C
    void ItemInstance::set(u8 inCount)
    {
        if (inCount == 0)
        {
            setNull();
            return;
        }

        if (!(inCount <= getMaxStackSize()))
        {
            LOG("itemStack too big!", inCount <= getMaxStackSize(), 0);
            inCount = getMaxStackSize();
        }

        mCount = inCount;
    }

    // FUN_0x1D1F88
    void ItemInstance::sub(u8 count)
    {
        set(mCount - count);
    }

    // FUN_0x6B1DA0
    u8 ItemInstance::getMaxStackSize() const
    {
        return mItem ? mItem->getMaxStackSize(*this) : 255;
    }

    // FUN_0x1D0D34
    void ItemInstance::setStackSize(u8 inCount)
    {
        if (!(inCount <= getMaxStackSize()))
        {
            LOG("itemStack too big!", inCount <= getMaxStackSize(), 0);
            inCount = getMaxStackSize();
        }

        mCount = inCount;
    }

    // FUN_0x6B2924
    u16 ItemInstance::getId() const
    {
        u16 res;

        if (!mUnk1)
            res = -1;
        else if (mItem)
            res = mItem->getItemId();
        else if (mBlock)
            res = mBlock->getId();

        return res;
    }

    // FUN_0x6B2954
    bool ItemInstance::isNull() const
    {
        return mUnk1 || mCount == 0 && mDataValue == 0 && !mItem && !mBlock && !mNbt && mUnk2.empty() && mUnk3.empty();
    }

    // FUN_0x6B15A0
    bool ItemInstance::isArmor() const
    {
        return mItem ? mItem->isArmor() : false;
    }

    // FUN_0x6B19FC
    bool ItemInstance::isWearableItem() const
    {
        if (mItem)
            return (mItem->isArmor() || mItem->isType(Item::mItems[(u8)ItemId::skull]));
        else if (mBlock)
            return mBlock->isType(Block::mBlocks[(u8)BlockId::pumpkin]);

        return false;
    }

    // 装着可能なアーマースロット番号を返す
    u8 ItemInstance::getSlotForItem() const
    {
        return reinterpret_cast<u8 (*)(const ItemInstance *)>(0x666244)(this);
    }

    // FUN_0x1D20E0
    ItemInstance &ItemInstance::setNull()
    {
        mCount     = 0;
        mDataValue = 0;
        mItem      = nullptr;
        mBlock     = nullptr;
        mNbt.reset();
        mUnk2.clear();
        mUnk3.clear();

        return *this;
    }

    int ItemInstance::getBaseRepairCost() const
    {
        return mNbt ? mNbt->getInt(Tag::RepairCost) : 0;
    }

    // FUN_0x6B15D0
    bool ItemInstance::isEnchanted() const
    {
        return mNbt ? mNbt->contains(Tag::ench, Tag::Type::List) : false;
    }

    // FUN_0x6B25EC

    gstd::vector<EnchantStatus> ItemInstance::getEnchants() const
    {
        gstd::vector<EnchantStatus> res;

        if (!mNbt)
            return res;

        ListTag *enchTag = mNbt->getList(Tag::ench);

        if (!enchTag)
            return res;

        gstd::vector<gstd::unique_ptr<CompoundTag>> &enchants = *(gstd::vector<gstd::unique_ptr<CompoundTag>> *)&enchTag->mList;

        for (auto &enchant : enchants)
            res.push_back({ (EnchantId)enchant->getShort(Tag::id), enchant->getShort(Tag::lvl) });

        return res;
    }

    // FUN_0x1D1670
    void ItemInstance::setEnchants(const gstd::vector<EnchantStatus> &enchants)
    {
        if (!mItem)
            return;

        bool empty = enchants.empty();

        if (!mNbt && !empty)
            mNbt = gstd::make_unique<CompoundTag>(Tag::tag);

        if (empty)
        {
            mNbt->remove(Tag::ench);
            return;
        }

        auto enchTag = gstd::make_unique<ListTag>();

        for (auto &d : enchants)
        {
            auto ench = gstd::make_unique<CompoundTag>();
            ench->putShort(Tag::id, (short)d.id);
            ench->putShort(Tag::lvl, d.level);
            enchTag->mList.push_back(std::move(ench));
        }

        mNbt->putList(Tag::ench, std::move(enchTag));
    }

    gstd::string ItemInstance::getName() const
    {
        return reinterpret_cast<gstd::string (*)(const ItemInstance *)>(0x6B1840)(this);
    }

    gstd::string ItemInstance::getNoFormatedName() const
    {
        return reinterpret_cast<gstd::string (*)(const ItemInstance *)>(0x6B2A34)(this);
    }

    gstd::string ItemInstance::getRawName() const
    {
        return mItem->getName();
    }

    bool ItemInstance::isNamed() const
    {
        if (!mItem || !mNbt)
            return false;

        auto displayTag = mNbt->getCompound(Tag::display);
        return displayTag ? displayTag->contains(Tag::Name) : false;
    }

    gstd::string ItemInstance::givenName() const
    {
        if (!mItem || !mNbt)
            return "";

        auto displayTag = mNbt->getCompound(Tag::display);
        return displayTag ? displayTag->getString(Tag::Name) : "";
    }

    // FUN_0x1D0E28
    void ItemInstance::setName(gstd::string name)
    {
        if (!mItem)
            return;

        if (!mNbt)
            mNbt = gstd::make_unique<CompoundTag>(Tag::tag);

        if (!mNbt->contains(Tag::display, Tag::Type::Compound))
            mNbt->putCompound(Tag::display, gstd::make_unique<CompoundTag>());

        auto displayTag     = mNbt->getCompound(Tag::display);
        auto copyDisplayTag = displayTag->_copy();
        copyDisplayTag->putString(Tag::Name, name);
        mNbt->putCompound(Tag::display, std::move(copyDisplayTag));
    }

}    // namespace MC3DSPluginFramework