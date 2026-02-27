#pragma once

#include "Minecraft/Common/World/Entity/EntityClass.hpp"
#include "Minecraft/Common/World/Item/ItemInstance.hpp"
#include "Minecraft/Helper/GameEnums.hpp"
#include "Minecraft/Helper/GameStructs.hpp"
#include "Minecraft/gstd/gstd.hpp"

namespace MC3DSPluginFramework
{
    class Entity;
    class ItemInstance;

    class Item
    {
    public:
        virtual ~Item();
        virtual void Unknown1(void);
        virtual void Unknown2(void);
        virtual void setMaxStackSize(u8);
        virtual void Unknown3(u16);    //+0x2E
        virtual void Unknown4(void);    // null
        virtual void Unknown5(void);    // null
        virtual void Unknown6(void);    // +0x21
        virtual void Unknown7(void);    // null
        virtual void Unknown8(void);    // null
        virtual void setDisableCanPlace(u8);    // 多分
        virtual void Unknown10(u8);    //+0x28
        virtual void setGlint(bool);    //+0x20
        virtual void Unknown11(u8);    //+0x29
        virtual u32 Unknown12(void);    // res -1
        virtual void Unknown13(void);    // null
        virtual u32 Unknown14(void);    // res 0
        virtual u32 Unknown15(void);    // res 0
        virtual u8 Unknown16(void);    //+0x22
        virtual u16 getMaxDurability(void);    //+0x1E
        virtual u32 Unknown18(void);    // res 0
        virtual u8 Unknown19(void);    //+0x21
        virtual u32 Unknown20(void);    // res 0
        virtual void Unknown21(void);    // null
        virtual bool hasGlint(const ItemInstance &) const;
        virtual u32 Unknown22(void);    // res 0
        virtual bool canDestroyInCreative(void) const;
        virtual bool isTnt(void) const;
        virtual u32 Unknown23(void);    // res 0
        virtual u32 Unknown24(void);    // res 0
        virtual void Unknown25(void);    // null
        virtual u32 Unknown26(void);    // res 0
        virtual u16 getEnchantValue(void) const;
        virtual bool isBook(void) const;
        virtual u32 Unknown27(void);    // res 0
        virtual void Unknown28(void);    // null
        virtual u32 Unknown29(u32);    // 耐久値バー系？
        virtual u32 Unknown30(void);    // res 0
        virtual FColor getColor(void);
        virtual u32 Unknown32(void);    // res 0
        virtual ItemInstance &onItemRightClick(const ItemInstance &, Entity *);    // res param2
        virtual u32 Unknown33(void);    // res 0
        virtual void Unknown34(ItemInstance &, u32, u32);
        virtual void onStoppedUsing(ItemInstance &, Entity *, int timeLeft);
        virtual float getMiningSpeed(void);    // res 1.f
        virtual void onCritical(ItemInstance &, u32 notusing, Entity *);    // 耐久値を2減らす
        virtual u32 Unknown36(void);    // res 0
        virtual bool onBlockDestroyed(ItemInstance &, const BlockData &target);
        virtual gstd::string getTranslatedName(const ItemInstance &);
        virtual gstd::string getEnchantmentName(const ItemInstance &);    // 0x9D2C9C
        virtual void Unknown38(u32, u32);
        virtual void Unknown39(u32, u32);
        virtual u8 getMaxStackSize(void);
        virtual void Unknown40(void);
        virtual void Unknown41(void);
        virtual u32 Unknown42(void);    // res -1
        virtual u32 Unknown43(void);    // res 0
        virtual gstd::string Unknown44(Entity *, u32);
        virtual u32 Unknown45(void);    // res 0
        virtual bool isBlock(void);    // blockID != 0
        virtual void *getTexturePos(void);    // 多分
        virtual u32 Unknown48(void);    // テクスチャ系
        virtual bool Unknown49(void);    //+0x1C
        virtual bool Unknown50(Entity *, ItemInstance &, const BlockFace &, const Vec3_Int &);
        virtual bool calculatePlacement(const ItemInstance &, Entity *, const BlockFace &, const Vec3_Int &);
        virtual bool placeBlock(ItemInstance &, Entity *, const Vec3_Int &);
        virtual void Unknown51(void);    // null
        virtual void Unknown52(void);    // null

    public:
        static constexpr size_t MAX_ITEMS = 0x200;
        static inline Item **mItems       = (Item **)0xB0CEF0;

        static void registerItem(void)
        {
            reinterpret_cast<void (*)()>(0x560FF0)();
        }

        static Item *getInstance(ItemId id)
        {
            return mItems[(u16)id];
        }

        void *operator new(size_t s) { return gstd::malloc(s); }
        void operator delete(void *m) { gstd::free(m); }

        u8 mMaxStack;
        gstd::string mAtlasName;
        u32 mUnk1;
        bool mUnk2;
        ItemId mId;
        gstd::string mDescriptionId;
        gstd::string mName2;
        bool mUnk3;
        u16 mDurability;
        bool mGlint;
        bool mUnk4;
        bool mUnk5;
        bool mDisablePlacement;
        u32 mMaxDuration;
        u32 mUnk6;
        BlockId mBlockId;
        MotionId mMotionId;
        u16 mUnk7;    // Padding?
        u32 mUnk8[5];
        //...
    };
}    // namespace MC3DSPluginFramework