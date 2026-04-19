#include "Item.hpp"

namespace MC3DSPluginFramework
{
    // FUN_0x578FC8
    // +0x8
    void Item::setIcon() {}

    // FUN_0x578FAC
    // +0xC
    void Item::Unknown2() {}

    // FUN_0x56E320
    // +0x10
    void Item::setMaxStackSize(u8 set)
    {
        mMaxStackSize = set;
    }

    // FUN_0x560B74
    // +0x14
    void Item::setMotion(u16 set)
    {
        mMotionId = set;
    }

    // FUN_0x56E314
    // +0x20
    void Item::Unknown6()
    {
        m0x21 = true;
    }

    // FUN_0x578EE8
    // +0x2C
    void Item::setCantPlace(u8 set)
    {
        mCantPlace = set;
    }

    // FUN_0x56C348
    // +0x30
    void Item::Unknown10(u8 set)
    {
        m0x28 = set;
    }

    // FUN_0x560B6C
    // +0x34
    void Item::setGlint(bool set)
    {
        mGlint = set;
    }

    // FUN_0x56E448
    // +0x38
    void Item::Unknown11(u8 set)
    {
        m0x29 = set;
    }

    // FUN_0x71B478
    // +0x3C
    int Item::Unknown12()
    {
        return -1;
    }

    // FUN_0x71B700
    // +0x44
    int Item::Unknown14()
    {
        return 0;
    }

    // FUN_0x71B850
    // +0x48
    int Item::Unknown15()
    {
        return 0;
    }

    // FUN_0x71B68C
    // +0x4C
    u8 Item::Unknown16()
    {
        return m0x22;
    }

    // FUN_0x71B134
    // +0x50
    u16 Item::getMaxDurability()
    {
        return mMaxDurability;
    }

    // FUN_0x71B5D8
    // +0x54
    int Item::Unknown18()
    {
        return 0;
    }

    // FUN_0x71B5D0
    // +0x58
    bool Item::Unknown19()
    {
        return m0x21;
    }

    // FUN_0x71C0C4
    // +0x5C
    bool Item::isArmor()
    {
        return false;
    }

    // FUN_0x71C0CC
    // +0x64
    bool Item::hasGlint(const ItemInstance &itemInstance) const
    {
        return itemInstance.isEnchanted() || mGlint;
    }

    // FUN_0x71B128
    // +0x68
    int Item::Unknown22()
    {
        return 0;
    }

    // FUN_0x71B7FC
    // +0x6C
    bool Item::canDestroyInCreative() const
    {
        return true;
    }

    // FUN_0x71B48C
    // +0x70
    bool Item::isTnt() const
    {
        return false;
    }

    // FUN_0x71B6F0
    // +0x74
    int Item::Unknown23()
    {
        return 0;
    }

    // FUN_0x71B6F8
    // +0x78
    int Item::Unknown24()
    {
        return 0;
    }

    // FUN_0x71B784
    // +0x80
    int Item::Unknown26()
    {
        return 0;
    }

    // FUN_0x71B58C
    // +0x84
    u16 Item::getEnchantValue() const
    {
        bool isBook = ((mItemId == getInstance(ItemId::book)->mItemId) || (mItemId == getInstance(ItemId::enchanted_book)->mItemId));
        return isBook ? 32767 : 0;
    }

    // FUN_0x71B610
    // +0x88
    bool Item::isBook() const
    {
        return mItemId == getInstance(ItemId::book)->mItemId;
    }

    // FUN_0x71C114
    // +0x8C
    int Item::Unknown27()
    {
        return 0;
    }

    // FUN_0x71B694
    // +0x98
    int Item::Unknown30()
    {
        return 0;
    }

    // FUN_0x71C0F4
    // +0x9C
    Color Item::getColor()
    {
        return Color::WHITE;
    }

    // FUN_0x71B120
    // +0xA0
    int Item::Unknown32()
    {
        return 0;
    }

    //  FUN_0x71C0EC
    // +0xA8
    int Item::Unknown33()
    {
        return 0;
    }

    // FUN_0x71B604
    // +0xB4
    float Item::getDestroySpeed()
    {
        return 1;
    }

    // FUN_0x71B480
    // +0xBC
    int Item::Unknown36()
    {
        return 0;
    }

    // FUN_0x71B798
    // +0xC4
    gstd::string Item::getName()
    {
        return Localization::get(getDescriptionId() + ".name");
    }

    // FUN_0x71B684
    // +0xD4
    u8 Item::getMaxStackSize(const ItemInstance &itemInstance) const
    {
        return mMaxStackSize;
    }

    // FUN_0x71B488
    // +0xD8
    void Item::Unknown40()
    {
        return;
    }

    // FUN_0x71B130
    // +0xDC
    void Item::Unknown41()
    {
        return;
    }

    // FUN_0x71B5E8
    // +0xE0
    int Item::Unknown42()
    {
        return -1;
    }

    // FUN_0x71B5E0
    // +0xE4
    int Item::Unknown43()
    {
        return 0;
    }

    // FUN_0x71B804
    // +0xEC
    int Item::getAnimationFrameFor()
    {
        return 0;
    }

    // FUN_0x71B118
    // +0xF0
    bool Item::isBlock()
    {
        return false;
    }

    // FUN_0x71B5C8
    // +0xF8
    int Item::Unknown48()
    {
        return 0;
    }

    // FUN_0x71B494
    // +0xFC
    bool Item::Unknown49()
    {
        return m0x1C;
    }

    // FUN_0x71B78C
    // +0x104
    bool Item::calculatePlacement(const ItemInstance &, Entity *, const HitResult::BlockFace &, const BlockPos &)
    {
        return false;
    }

}    // namespace MC3DSPluginFramework