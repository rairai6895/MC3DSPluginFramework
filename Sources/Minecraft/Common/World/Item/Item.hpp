#pragma once

#include "ItemInstance.hpp"
#include "Minecraft/Common/Client/Locale/Language.hpp"
#include "Minecraft/Common/World/Level/Block/BlockData.hpp"
#include "Minecraft/Common/World/Level/BlockPos.hpp"
#include "Minecraft/Common/World/Phys/HitResult.hpp"
#include "Minecraft/Helper/GameEnums.hpp"
#include "Minecraft/gstd/gstd.hpp"
#include "Minecraft/src-deps/Core/Math/Color.hpp"

namespace MC3DSPluginFramework
{
    class Entity;
    class ItemInstance;

    class Item
    {
        USE_GAME_ALLOCATOR
    public:
        static constexpr size_t MAX_ITEMS = 0x200;
        static inline Item    **mItems    = (Item **)0xB0CEF0;
        // 0xA33F44 ブロックを除いたアイテム一覧？

        static void registerItem()
        {
            reinterpret_cast<void (*)()>(0x560FF0)();
        }

        static Item *getInstance(ItemId id)
        {
            return mItems[(u16)id];
        }

        bool isType(const Item *type) const
        {
            return this == type;
        }

        u16 getItemId()
        {
            return mItemId;
        }

        int getMaxDuration()
        {
            return mMaxDuration;
        }

        void *getFood()
        {
            return mFood;
        }

        gstd::string &getDescriptionId()
        {
            return mDescriptionId;
        }

    public:
        virtual ~Item();

        virtual void setIcon();
        virtual void Unknown2();
        virtual void setMaxStackSize(u8 set);
        virtual void setMotion(u16 set);
        virtual void Unknown4() = delete;    // +0x18
        virtual void Unknown5() = delete;    // +0x1C
        virtual void Unknown6();
        virtual void Unknown7() = delete;    // +0x24
        virtual void Unknown8() = delete;    // +0x28
        virtual void setCantPlace(u8 set);
        virtual void Unknown10(u8 set);
        virtual void setGlint(bool set);
        virtual void Unknown11(u8 set);
        virtual int  Unknown12();
        virtual void Unknown13() = delete;    // +0x40
        virtual int  Unknown14();
        virtual int  Unknown15();
        virtual u8   Unknown16();
        virtual u16  getMaxDurability();
        virtual int  Unknown18();
        virtual bool Unknown19();
        virtual bool isArmor();
        virtual void Unknown21() = delete;    // +0x60
        virtual bool hasGlint(const ItemInstance &itemInstance) const;
        virtual int  Unknown22();
        virtual bool canDestroyInCreative() const;
        virtual bool isTnt() const;
        virtual int  Unknown23();
        virtual int  Unknown24();
        virtual void Unknown25() = delete;    // +0x7C
        virtual int  Unknown26();
        virtual u16  getEnchantValue() const;
        virtual bool isBook() const;
        virtual int  Unknown27();
        virtual void Unknown28() = delete;    // +0x90

        // FUN_0x71B5F0
        // +0x94
        virtual int Unknown29(int);    // 耐久値バー系？

        virtual int   Unknown30();
        virtual Color getColor();
        virtual int   Unknown32();

        // FUN_0x71BCCC
        // +0xA4
        virtual ItemInstance &use(const ItemInstance &itemInstance, Entity *e);

        virtual int Unknown33();

        // +0xAC
        virtual void Unknown34(ItemInstance &, u32, u32);

        // +0xB0
        virtual void releaseUsing(ItemInstance &itemInstance, Entity *user, int durationLeft);

        virtual float getDestroySpeed();

        // FUN_0x71C104
        // +0xB8
        virtual void onCritical(ItemInstance &, int unused, Entity *);    // 耐久値を2減らす

        virtual int Unknown36();

        // FUN_0x71C11C
        // +0xC0
        virtual bool onBlockDestroyed(ItemInstance &, const BlockData &target);

        virtual gstd::string getName();

        // FUN_0x71B858
        // +0xC8
        virtual gstd::string getEnchantmentName(const ItemInstance &);    // 0x9D2C9C

        // FUN_0x71B13C
        // +0xCC
        virtual void Unknown38(u32, u32);

        // FUN_0x71B49C
        // +0xD0
        virtual void Unknown39(u32, u32);

        virtual u8   getMaxStackSize(const ItemInstance &itemInstance) const;
        virtual void Unknown40();
        virtual void Unknown41();
        virtual int  Unknown42();
        virtual int  Unknown43();

        // +0xE8
        virtual gstd::string Unknown44(Entity *);

        virtual int  getAnimationFrameFor();
        virtual bool isBlock();

        // FUN_0x71BFF8
        // +0xF4
        virtual void *getIcon(int p1);

        virtual int Unknown48();

        virtual bool Unknown49();

        // FUN_0x71B80C
        // +0x100
        virtual bool Unknown50(Entity *e, ItemInstance &itemInstance, const HitResult::BlockFace &face, const BlockPos &pos);

        virtual bool calculatePlacement(const ItemInstance &, Entity *, const HitResult::BlockFace &face, const BlockPos &);

        // FUN_0x71BEF8
        // +0x108
        virtual bool placeBlock(ItemInstance &, Entity *, const BlockPos &);

        virtual void Unknown51() = delete;    // +0x10C
        virtual void Unknown52() = delete;    // +0x110

        u8           mMaxStackSize;    // +0x4
        gstd::string mAtlasName;    // +0x8
        int          m0xC;    // +0xC
        u8           m0x10;    // +0x10
        u16          mItemId;    // +0x12
        gstd::string mDescriptionId;    // +0x14
        gstd::string m0x18;    // +0x18
        u8           m0x1C;    // +0x1C
        u16          mMaxDurability;    // +0x1E
        bool         mGlint;    // +0x20
        bool         m0x21;    // +0x21
        bool         m0x22;    // +0x22
        bool         mCantPlace;    // +0x23
        int          mMaxDuration;    // +0x24
        u8           m0x28;    // +0x28
        u8           m0x29;    // +0x29
        u8           m0x2A;    // +0x2A
        u8           m0x2B;    // +0x2B
        u8           mBlockId;    // +0x2C
        u16          mMotionId;    // +0x2E
        int          m0x30;    // +0x30
        int          m0x34;    // +0x34
        int          mIconTexture;    // +0x38
        int          m0x3C;    // +0x3C
        int          m0x40;    // +0x40
        int          m0x44;    // +0x44
        int          m0x48;    // +0x48
        int          m0x4C;    // +0x4C
        int          m0x50;    // +0x50
        int          m0x54;    // +0x54
        int          m0x58;    // +0x58
        int          m0x5C;    // +0x5C
        int          m0x60;    // +0x60
        int          m0x64;    // +0x64
        int          m0x68;    // +0x68
        int          m0x6C;    // +0x6C
        int          m0x70;    // +0x70
        int          m0x74;    // +0x74
        int          m0x78;    // +0x78
        int          m0x7C;    // +0x7C
        int          m0x80;    // +0x80
        Vec3<float>  m0x84;    // +0x84
        Vec3<float>  m0x90;    // +0x90
        float        m0x9C;    // +0x9C
        void        *mFood;    // +0xA0
        int          m0xA4;    // +0xA4
        int          m0xA8;    // +0xA8

    public:
        static inline const Item *
            totem = *(Item **)0xA3421C;
    };
}    // namespace MC3DSPluginFramework