#pragma once

#include "Minecraft/Common/World/Entity/DamageSource.hpp"
#include "Minecraft/Common/World/Entity/EntityClass.hpp"

#include "Minecraft/Common/World/Level/Block.hpp"
#include "Minecraft/Common/World/Phys/AABB.hpp"
#include "Minecraft/Helper/Structs.hpp"

namespace MC3DSPluginFramework
{
    // vtable 9cb70c
    class _Entity
    {
    public:
        Level *getLevel()
        {
            return *(Level **)((u32)this + 0x1A0);
        }

        Dimension *getDimension()
        {
            return nullptr;
        }

        Vec3 getAttachPos(u32 unknown)
        {
            return reinterpret_cast<Vec3 (*)(_Entity *, u32)>(0x723714)(this, unknown);
        }

    public:
        virtual void Unknown1();    // +0x0 0x5F20C8
        virtual void Unknown2();    // +0x4 0x600D28 setChunkPos?
        virtual void Unknown3();    // +0x8 0x4EA100
        virtual void initializeComponents(bool unknown);    // +0xC
        virtual void Unknown5();    // +0x10 0x5ECEA4
        virtual void Unknown6();    // +0x14 0x713A24
        virtual void Unknown7() = delete;    // +0x18
        virtual void Unknown8() = delete;    // +0x1C

        virtual ~_Entity();    // +0x20
        // +0x24 deletingDestructor

        virtual void Unknown9();    // +0x28
        virtual void Unknown10();    // +0x2C
        virtual void Unknown11();    // +0x30
        virtual void Unknown12();    // +0x34
        virtual Vec3_Float &getPosition();    // +0x38
        virtual Vec3_Float &Unknown13();    // +0x3C
        virtual void Unknown14();    // +0x40
        virtual Vec3_Float &getVelocity();    // +0x44
        virtual void setCamera(const CameraAngles &angle);    // +0x48
        virtual void move(const Vec3_Float &offset);    // +0x4C
        virtual void Unknown15();    // +0x50
        virtual void Unknown16();    // +0x54
        virtual void Unknown17();    // +0x58
        virtual u32 Unknown18();    // +0x5C
        virtual void push(float x, float y, float z);    // +0x60
        virtual void teleport1(const Vec3_Float &pos);    // +0x64
        virtual bool Unknown19(const Vec3_Float &pos, u32 param_2, u32 param_3, u32 param_4, u32 param_5);    // +0x68
        virtual void Unknown20();    // +0x6C
        virtual void setVelocity(const Vec3_Float &velocity);    // +0x70
        virtual void controllCamera(const CameraAngles &offset, bool unknown);    // +0x74

        virtual void Unknown21() = delete;    // +0x78

        virtual gstd::unique_ptr<SynchedEntityData::DataItem<int>> Unknown22();    // +0x7C
        virtual void tick();    // +0x80
        virtual void Unknown23();    // +0x84
        virtual void Unknown24();    // +0x88
        virtual void Unknown25();    // +0x8C
        virtual float Unknown26();    // +0x90
        virtual bool startRiding(_Entity &ride);    // +0x94
        virtual void _startRiding(_Entity &ride);    // +0x98
        virtual void getOff(_Entity &ride);    // +0x9C
        virtual bool intersects(const Vec3 &min, const Vec3 &max);    // +0xA0

        virtual void Unknown27() = delete;    // +0xA4
        virtual void Unknown28(const Vec3 &unknown);    // +0xA8
        virtual void Unknown29();    // +0xAC
        virtual bool isInvisible();    // +0xB0
        virtual bool isNotInvisible();    // +0xB4
        virtual bool Unknown30();    // +0xB8
        virtual bool Unknown31(bool unknown);    // +0xBC
        virtual gstd::string &referenceName();    // +0xC0
        virtual gstd::string copyName();    // +0xC4
        virtual void setName(gstd::string name);    // +0xC8
        virtual bool isInWater1();    // +0xCC
        virtual bool isInWater2();    // +0xD0
        virtual void Unknown32();    // +0xD4
        virtual void Unknown33();    // +0xD8
        virtual void Unknown34();    // +0xDC
        virtual float Unknown35();    // +0xE0
        virtual float Unknown36();    // +0xE4
        virtual void Unknown37() = delete;    // +0xE8
        virtual void Unknown38() = delete;    // +0xEC
        virtual u32 Unknown39();    // +0xF0
        virtual void Unknown40() = delete;    // +0xF4
        virtual void Unknown41();    // +0xF8
        virtual void Unknown42();    // +0xFC
        virtual void Unknown43();    // +0x100
        virtual void pushAway(_Entity *other, bool single);    // +0x104
        virtual void addVelocity(const Vec3 &add);    // +0x108
        virtual void addVelocity2(const Vec3 &add);    // +0x10C
        virtual void Unknown44();    // +0x110
        virtual bool isAdult();    // +0x114
        virtual u32 Unknown45();    // +0x118
        virtual bool Unknown46();    // +0x11C
        virtual u32 Unknown47();    // +0x120
        virtual u32 Unknown48();    // +0x124
        virtual void Unknown49() = delete;    // +0x128
        virtual u32 Unknown50();    // +0x12C
        virtual bool Unknown51();    // +0x130
        virtual bool isOnFire();    // +0x134
        virtual int Unknown52();    // +0x138
        virtual void Unknown53() = delete;    // +0x13C
        virtual bool Unknown54();    // +0x140
        virtual bool Unknown55();    // +0x144
        virtual void Unknown56();    // +0x148
        virtual void Unknown57() = delete;    // +0x14C
        virtual void Unknown58();    // +0x150
        virtual void Unknown59();    // +0x154
        virtual void Unknown60();    // +0x158
        virtual void Unknown61();    // +0x15C
        virtual void Unknown62();    // +0x160
        virtual u32 Unknown63();    // +0x164
        virtual u32 Unknown64();    // +0x168
        virtual u32 Unknown65();    // +0x16C
        virtual void Unknown66(bool unknown);    // +0x170
        virtual bool Unknown67();    // +0x174
        virtual void Unknown68(bool unknown);    // +0x178
        virtual bool Unknown69();    // +0x17C
        virtual void Unknown70();    // +0x180
        virtual void Unknown71();    // +0x184
        virtual void Unknown72();    // +0x188
        virtual void Unknown73();    // +0x18C
        virtual void Unknown74();    // +0x190
        virtual void Unknown75();    // +0x194
        virtual void Unknown76();    // +0x198

        // +0x19C
        virtual float Unknown77()
        {
            return 0.1f;
        }

        virtual void Unknown78();    // +0x1A0
        virtual void Unknown79();    // +0x1A4
        virtual void Unknown80();    // +0x1A8
        virtual void Unknown81();    // +0x1AC
        virtual void Unknown82();    // +0x1B0
        virtual void Unknown83();    // +0x1B4

        virtual void Unknown84() = delete;    // +0x1B8
        virtual void Unknown85() = delete;    // +0x1BC

        virtual void Unknown86();    // +0x1C0
        virtual void Unknown87();    // +0x1C4
        virtual void Unknown88();    // +0x1C8
        virtual void Unknown89();    // +0x1CC
        virtual void Unknown90();    // +0x1D0

        virtual void Unknown91() = 0;    // +0x1D4

        virtual void Unknown92();    // +0x1D8
        virtual void Unknown93();    // +0x1DC
        virtual void Unknown94();    // +0x1E0
        virtual void Unknown95();    // +0x1E4
        virtual void Unknown96();    // +0x1E8
        virtual void Unknown97();    // +0x1EC
        virtual void Unknown98();    // +0x1F0
        virtual void Unknown99();    // +0x1F4
        virtual void Unknown100();    // +0x1F8
        virtual void Unknown101();    // +0x1FC
        virtual void Unknown102();    // +0x200

        virtual void Unknown103() = delete;    // +0x204

        virtual void Unknown104();    // +0x208
        virtual void Unknown105();    // +0x20C
        virtual void Unknown106();    // +0x210
        virtual void Unknown107();    // +0x214
        virtual void Unknown108();    // +0x218
        virtual void Unknown109();    // +0x21C
        virtual void Unknown110();    // +0x220
        virtual void Unknown111();    // +0x224
        virtual void Unknown112();    // +0x228

        virtual void Unknown113() = delete;    // +0x22C
        virtual void Unknown114() = delete;    // +0x230

        virtual void Unknown115();    // +0x234
        virtual void Unknown116();    // +0x238
        virtual void sendMotionPacketIfNeeded();    // +0x23C
        virtual void Unknown118();    // +0x240
        virtual void Unknown119();    // +0x244

        virtual void Unknown120() = delete;    // +0x248

        virtual void Unknown121();    // +0x24C
        virtual void Unknown122();    // +0x250

        virtual void Unknown123() = delete;    // +0x254
        virtual void Unknown124() = delete;    // +0x258
        virtual void Unknown125() = delete;    // +0x25C
        virtual void Unknown126() = delete;    // +0x260
        virtual void Unknown127() = delete;    // +0x264

        virtual void Unknown128();    // +0x268
        virtual void Unknown129();    // +0x26C
        virtual void Unknown130();    // +0x270
        virtual void Unknown131();    // +0x274
        virtual void Unknown132();    // +0x278
        virtual void Unknown133();    // +0x27C
        virtual void Unknown134();    // +0x280
        virtual void Unknown135();    // +0x284
        virtual void Unknown136();    // +0x288
        virtual void Unknown137();    // +0x28C
        virtual void Unknown138();    // +0x290

        virtual void Unknown139() = delete;    // +0x294

        virtual void Unknown140();    // +0x298
        virtual void Unknown141();    // +0x29C
        virtual void Unknown142();    // +0x2A0
        virtual void Unknown143();    // +0x2A4
        virtual void Unknown144();    // +0x2A8
        virtual void Unknown145();    // +0x2AC
        virtual void Unknown146();    // +0x2B0
        virtual void Unknown147();    // +0x2B4
        virtual void Unknown148();    // +0x2B8
        virtual void Unknown149();    // +0x2BC
        virtual void Unknown150();    // +0x2C0
        virtual void Unknown151();    // +0x2C4
        virtual void Unknown152();    // +0x2C8
        virtual void Unknown153();    // +0x2CC
        virtual void Unknown154();    // +0x2D0
        virtual void Unknown155();    // +0x2D4
        virtual void _removeRider();    // +0x2D8

        // Entity::

    private:
        // mLevel +0x1A0
    };

    class EntityBase
    {
    public:
        void (*Unknown1)(void);
        void (*Unknown2)(void);
        void (*Unknown3)(void);
        void (*Unknown4)(void);
        void (*Unknown5)(void);
        void (*Unknown6)(void);
        void (*Unknown7)(void);
        void (*Unknown8)(void);

        void (*Destructor)(void *__this);
        void (*DeletingDestructor)(void *__this);

        void (*Unknown9)(void);
        void (*Unknown10)(void);
        void (*Unknown11)(void);
        void (*SetPos)(void *__this, const Vec3_Float &pos);
        Vec3_Float &(*getPos)(void *__this);
        Vec3_Float (*GetPos2)(void *__this);
        void (*Unknown12)(void);
        Vec3_Float &(*GetVelocity)(void *__this);
        void (*SetCamera)(void *__this, const CameraAngles &camera);
        void (*Move)(void *__this, const Vec3_Float &offset);
        void (*Unknown13)(void);
        void (*CheckBlockCollisions)(void *__this, const AABB &aabb);
        Block *(*GetInsideBlock)(void *__this);
        void (*Unknown14)(void);
        void (*Push)(void *__this, float x, float y, float z);
        void (*Teleport1)(void *__this, const Vec3_Float &pos, u32 unknown1, u32 unknown2);
        void (*Teleport2)(void *__this, const Vec3_Float &pos, u32 unknown1, u32 unknown2, u32 unknown3, u32 unknown4);
        void (*Unknown15)(void);
        void (*SetVelocity)(void *__this, const Vec3_Float &velocity);
        void (*ControllCamera)(void *__this, const CameraAngles &camera, u32 unknown1);
        void (*Unknown16)(void);
        void (*Unknown17)(void **ptr, void *__this);    // 謎のポインタが返る
        void (*Unknown18)(void);
        void (*Tick1)(void *__this);
        void (*Unknown19)(void);
        void (*Unknown20)(void);
        void (*Unknown21)(void);
        void (*Ride)(void *__this, void *__target);
        void (*RideInternal)(void *__target, void *__this);    // 内部処理
        void (*GetOff)(void *__target, void *__this);    // 内部処理

        void (*Unknown22)(void);
        void (*Unknown23)(void);
        void (*Unknown24)(void);
        void (*Unknown25)(void);    // 0x99C3C8
        bool (*IsInvisible)(void *__this);
        bool (*Unknown26)(void *__this);
        void (*Unknown27)(void);
        void (*Unknown28)(void);
        gstd::string &(*ReferenceName)(void *__this);    // 0x99C3DC
        gstd::string (*CopyName)(void *__this);
        void (*SetName)(void *__this, gstd::string name);
        bool (*IsInWater)(void *__this);
        bool (*IsInWater2)(void *__this);    // 別の処理もしてる
        bool (*IsInLava)(void *__this);
        void (*Unknown29)(void *__this);    // ブロックの硬さ系？
        void (*SetInCobweb)(void *__this);
        bool (*IsElytraFlying1)(void *__this);
        bool (*IsElytraFlying2)(void *__this);
        void (*Unknown30)(void);
        void (*Unknown31)(void);
        void (*Unknown32)(void);    // 0x99C40C
        void (*Unknown33)(void);
        float &(*GetShaderLevel)(void *__this);    // 多分足元の影レベル取得
        void (*Unknown34)(void);
        void (*Unknown35)(void);
        void (*PushAway)(void *__this, void *__other, bool single);
        void (*AddVelocity1)(void *__this, const Vec3_Float &offset);
        void (*AddVelocity2)(void *__this, const Vec3_Float &offset);    // -> AddVelocity1
        void (*Unknown36)(void);    // 0x99C42C
        bool (*IsChild)(void *__this);
        bool (*IsDespawning)(void *__this);
        void (*Unknown37)(void);
        void (*Unknown38)(void);
        void (*Unknown39)(void);
        void (*Unknown40)(void);
        bool (*IsSneaking)(void *__this);
        bool (*IsAlive)(void *__this);    // hp > 0
        bool (*IsOnFire)(void *__this);
        bool (*IsPanic)(void *__this);    // 動物が暴れるときのフラグ
        void (*Unknown41)(void);    // 0x99C458
        void (*Unknown42)(void);
        void (*Unknown43)(void);
        void (*Unknown44)(void);
        void (*Unknown45)(void);
        void (*Unknown46)(void);    // 0x99C46C
        void (*Unknown47)(void);
        void (*Unknown48)(void);
        void (*Unknown49)(void);
        void (*Unknown50)(void);
        int (*Unknown51)(void);
        int (*Unknown52)(void);
        int (*Unknown53)(void);
        void (*Unknown54)(void);
        void (*Unknown55)(void);
        void (*Unknown56)(void *__this, u32 unknown1);
        void (*Unknown57)(void *__this);    // 0x99C498
        void (*Unknown58)(void *__this, void *unknown1);    // ダメージ系
        void (*DamageMotion)(void *__this);
        bool (*FireDamage)(void *__this, u32 damage);
        size_t (*TryOnFire)(void *__this);    // res = 残りの燃える時間
        void (*Unknown59)(void *__this);
        void (*SpawnEatEffect)(void *__this, u32 id);    // 食べるエフェクトを出す　(level->FUN_0x3F4908) 0x99C4B0
        void (*PlayAction)(void *__this, u32 id, u32 unknown1);    // idが3なら死ぬ
        float (*Unknown60)(void);
        void *(*PopItem2)(void *__this, ItemId id, u8 count);    // ->PopItem1
        void (*PopItem1)(void *__this, ItemId id, u8 count);    // 頭上からアイテムをスポーンさせる
        void (*PopItem3)(void *__this, const BlockData &data, u32 unknown1, u32 unknown2);
        void (*PopItem4)(void *__this, const BlockData &data);
        void *(*PopItemEngine)(void *__this, const ItemInstance &item);    // res = スポーンしたアイテムエンティティ
        void (*Unknown61)(void);
        void (*Unknown62)(void);
        void (*Unknown63)(void);
        void (*SetArmorSlot)(void *__this, size_t index, const ItemInstance &item);
        void (*GetNBT1)(void *__this, CompoundTag *out);    // エンティティのデータをNBTに格納する 0x99C4E0
        void (*GetNBT2)(void *__this, CompoundTag *out);    // こっちの方が保存されるデータが少ない
        void (*SetNBT)(void *__this, CompoundTag *set);    // データをリストアする
        void (*Unknown64)(void *__this, CompoundTag *unknown1, void *unknown2);
        int (*getEntityTypeId)(void *__this);
        u32 (*Unknown65)(void);    // res 0
        u32 (*Unknown66)(void);    // 0x99C4F8 res 0

        void (*Unknown67)(void);
        void (*SetFire)(void *__this, size_t index);
        void (*GetAdjustedAABB)(AABB &aabb, void *__this);
        void (*SetNetherGateEffect)(void *__this);
        int (*Unknown68)(void);
        int (*Unknown69)(void);
        size_t (*GetDimention)(void *__this);
        int (*Unknown70)(void);
        void (*SetDimention)(void *__this, size_t dimentionId);
        void (*Unknown71)(void);
        void (*Unknown72)(void *unknown, void *__this);
        void (*UpdateFallState)(void *__this, bool onGround);    // 0x99C528
        void (*Landing)(void *__this);    // 着地時に呼ばれる
        void (*Unknown73)(void);
        void (*PlaySound)(void *__this, int id, const Vec3_Float &pos, u32 data1, u32 data2);
        void (*Unknown74)(void);
        void (*CanRide)(void *__target, void *__this);
        int (*Unknown75)(void);
        int (*Unknown76)(void *__this);    // 0x99C544
        void (*Unknown77)(void);
        void (*Unknown78)(void);
        void (*Unknown79)(void);
        void (*Unknown80)(void);
        void (*Unknown81)(void);
        int (*Unknown82)(void);
        int (*RideExit)(void *__this, bool dismountYOffset, bool dismountOffsetDisable);    // 降りたら0、失敗なら-1が返る
        void (*Unknown83)(void);    // 0x99C564
        void (*Unknown84)(void);
        void (*SubItem)(void *__this, const ItemInstance &item);
        void (*Unknown85)(void);
        void (*Unknown86)(void);
        void (*Unknown87)(void);
        void (*Unknown88)(void);
        void (*Unknown89)(void);
        float (*Unknown90)(void *__this);
        void (*Unknown91)(void);
        void (*Unknown92)(void);
        bool (*IsEnabledWorldBuilder)(void *__this);
        bool (*IsCreativeMode)(void *__this);
        bool (*IsAdventureMode)(void *__this);
        void (*GetItem)(void *__this, ItemInstance &item);
        void (*DropItem)(void *__this, const ItemInstance &item, bool diffusion);
        int (*Unknown93)(void);
        void (*Unknown94)(void);
        void (*Unknown95)(void *__this);
        void (*Unknown96)(void);
        void (*Unknown97)(void *__this);
        bool (*Damage)(void *__this, const DamageSource *source, size_t damage, u32 unknown1, u32 unknown2);    // 0x99C5B8
        void (*Unknown98)(void *__this);
        void (*MagmaDamage)(void *__this);
        void (*Unknown99)(void *__this, CompoundTag *compound);
        void (*Unknown100)(void *__this, CompoundTag *compound);
        void (*Unknown101)(void *__this, u32, u32);
        void (*Unknown102)(void *__this);    // 0x99C5D0
        void (*Unknown103)(void *__this, Vec3_Float *);    // 0x99C5D4
        void (*Unknown104)(void *__this);    // 0x99C5D8
        void (*Unknown105)(void *__this);    // 0x99C5DC
        void (*Unknown106)(void *__this);    // 0x99C5E0
        u32 (*Unknown107)(void *__this);    // 0x99C5E4
        void (*Unknown108)(void);    // 0x99C5E8
        u32 (*Unknown109)(void *__this);    // 0x99C5EC
        u32 (*Unknown110)(void);    // 0x99C5F0 res0
    };
}    // namespace MC3DSPluginFramework