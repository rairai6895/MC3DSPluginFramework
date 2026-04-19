#pragma once

#include "../Level/Block/Block.hpp"
#include "../Phys/AABB.hpp"
#include "DamageSource.hpp"
#include "EntityUniqueID.hpp"
#include "Minecraft/Common/Util/BoxedPtr.hpp"
#include "Minecraft/Common/Util/Random.hpp"
#include "Minecraft/Common/World/Level/Block/BlockData.hpp"
#include "Minecraft/Helper/Structs.hpp"
#include "SynchedEntityData.hpp"

namespace MC3DSPluginFramework
{
    class Dimension;
    class Level;

    class Entity
    {
    public:
        Level       &getLevel();
        BlockSource &getRegion();
        Dimension   *getDimension();
        Vec3<float>  getAttachPos(int p1);
        void         setUniqueID(EntityUniqueID ID);
        bool         hasCategory(EntityCategory category);
        bool         getSharedFlag(SynchedEntityData::EntitySharedFlag flag);
        bool         isRemoved() const;
        bool         isGliding();

        bool isOnGround() const
        {
            return mOnGround;
        }

        void setOnGround(bool set)
        {
            mOnGround = set;
        }

        bool isTouchingWall()
        {
            return mHorizontalCollision;
        }

        void setTouchingWall(bool set)
        {
            mHorizontalCollision = set;
        }

        void setInWeb(bool set)
        {
            mInWeb = set;
        }

        void setStepHeight(float set)
        {
            mStepHeight = set;
        }

        void setFireResistance(bool set)
        {
            mFireResistance = set;
        }

        float getWidth()
        {
            return mWidth;
        }

        float getHeight()
        {
            return mHeight;
        }

        AABB &getAABB()
        {
            return m0x288;
        }

        Vec2<float> &getRot()
        {
            return mRot;
        }

        Entity *getRidingEntity() const
        {
            return mRideEntity;
        }

    public:
        // FUN_0x5F20C8
        // +0x0
        virtual void vFunc0x0()
        {
            return;
        }

        // FUN_0x5EC698
        // +0x4
        virtual void vFunc0x4()
        {
            return;
        }

        // FUN_0x5F21AC
        // +0x8
        virtual void vFunc0x8()
        {
            return;
        }

        // FUN_5EFEAC
        // +0xC
        virtual void initializeComponents(u8 p1);

        // FUN_0x5ECEA4
        // +0x10
        virtual void vFunc0x10();

        // FUN_0x70DD20
        // +0x14
        virtual void vFunc0x14();

        virtual void vFunc0x18() = delete;    // +0x18
        virtual void vFunc0x1C() = delete;    // +0x1C

        // FUN_0x5F9C90
        // +0x20
        virtual ~Entity();

        virtual void vFunc0x28();

        // FUN_0x5EE7B4
        // +0x2C
        virtual void vFunc0x2C();

        // FUN_0x5F6828
        // +0x30
        virtual void vFunc0x30();

        // FUN_0x5F68E0
        // +0x34
        virtual void vFunc0x34(const Vec3<float> &);

        // FUN_0x724DD0
        // +0x38
        virtual Vec3<float> &getPos()
        {
            return mPosition;
        }

        // FUN_0x7253F8
        // +0x3C
        virtual Vec3<float> &vFunc0x3C()
        {
            return m0x1CC;
        }

        // FUN_0x72469C
        // +0x40
        virtual void vFunc0x40();

        // FUN_0x723664
        // +0x44
        virtual Vec3<float> &getVelocity();

        // FUN_0x5F6A88
        // +0x48
        virtual void setRot(const Vec2<float> &rot);

        // FUN_0x5F44A4
        // +0x4C
        virtual void move(const Vec3<float> &offset);

        // FUN_0x724A68
        // +0x50
        virtual void vFunc0x50();

        // FUN_0x5EFAD8
        // +0x54
        virtual void vFunc0x54();

        // FUN_0x5EFCB4
        // +0x58
        virtual void vFunc0x58();

        // FUN_0x72471C
        // +0x5C
        virtual int vFunc0x5C()
        {
            return 0;
        }

        // FUN_0x5E9DE8
        // +0x60
        virtual void push(float x, float y, float z);

        // FUN_0x5E9208
        // +0x64
        virtual void teleportTo(const Vec3<float> &pos, int teleportationCause, int teleportationItem);

        // FUN_0x5EAB80
        // +0x68
        virtual bool vFunc0x68(const Vec3<float> &pos, u32 param_2, u32 param_3, u32 param_4, u32 param_5);

        // FUN_0x5F6524
        // +0x6C
        virtual void vFunc0x6C();

        // FUN_0x5E8830
        // +0x70
        virtual void setVelocity(const Vec3<float> &set)
        {
            mVelocity = set;
        }

        // FUN_0x5F62CC
        // +0x74
        virtual void turn(const Vec2<float> &rot, bool slow)
        {
            float scale = slow ? 0.15f : 1;

            float prevYaw   = mRot.y;
            float prevPitch = mRot.x;

            float newYaw   = prevYaw + rot.y * scale;
            float newPitch = prevPitch - rot.x * scale;

            if (newPitch < -90.f)
                newPitch = -90.f;

            if (newPitch > 90.f)
                newPitch = 90.f;

            mRot.y = newYaw;
            mRot.x = newPitch;

            mRotPrev.y += (newYaw - prevYaw);
            mRotPrev.x += (newPitch - prevPitch);
        }

        virtual void vFunc0x78() = delete;    // +0x78

        // FUN_0x5E9A2C
        // +0x7C
        virtual gstd::unique_ptr<SynchedEntityData::DataItem<int>> vFunc0x7C();

        // FUN_0x5E884C
        // +0x80
        virtual void tick();

        // FUN_0x5F6E60
        // +0x84
        virtual void vFunc0x84();

        // FUN_0x5F7784
        // +0x88
        virtual void vFunc0x88();

        // FUN_0x723F60
        // +0x8C
        virtual void vFunc0x8C();

        // FUN_0x5EBC60
        // +0x90
        virtual float vFunc0x90()
        {
            return m0x2BC;
        }

        // FUN_0x5E9680
        // +0x94
        virtual bool startRiding(Entity &ride);

        // FUN_0x5F6C58
        // +0x98
        virtual void _startRiding(Entity &ride);

        // FUN_0x5ED530
        // +0x9C
        virtual void getOff(Entity &ride);

        // FUN_0x5E87F8
        // +0xA0
        virtual bool intersects(const Vec3<float> &min, const Vec3<float> &max)
        {
            return m0x288.intersects(AABB(min.x, min.y, min.z, max.x, max.y, max.z));
        }

        virtual void vFunc0xA4() = delete;    // +0xA4

        // FUN_0x5F64A8
        // +0xA8
        virtual void vFunc0xA8(const Vec3<float> &unknown);

        // FUN_0x7252F0
        // +0xAC
        virtual void vFunc0xAC();

        // FUN_0x7236B8
        // +0xB0
        virtual bool isInvisible()
        {
            return getSharedFlag(SynchedEntityData::EntitySharedFlag::InVisible);
        }

        // FUN_0x5EB180
        // +0xB4
        virtual bool isCustomNameVisible()
        {
            return mSynchedEntityData.getFlag<int64_t>(0, 14);
        }

        // FUN_0x7245F4
        // +0xB8
        virtual bool vFunc0xB8()
        {
            return 1;
        }

        // FUN_0x5EDEDC
        // +0xBC
        virtual bool vFunc0xBC(bool unknown);

        // FUN_0x6F3000
        // +0xC0
        virtual gstd::string &getCustomName()
        {
            return mSynchedEntityData.getString(4);
        }

        // FUN_0x724730
        // +0xC4
        virtual gstd::string copyName()
        {
            return getCustomName();
        }

        // FUN_0x5E8D4C
        // +0xC8
        virtual void setName(gstd::string name);

        // FUN_0x725540
        // +0xCC
        virtual bool wasInWater()
        {
            return mWasInWater;
        }

        // FUN_0x5EBC68
        // +0xD0
        virtual bool isInWater();

        // FUN_0x5F74A4
        // +0xD4
        virtual bool isInLava();

        // FUN_0x723DB8
        // +0xD8
        virtual void vFunc0xD8();

        // FUN_0x5EB67C
        // +0xDC
        virtual void vFunc0xDC()
        {
            mInWeb        = true;
            mFallDistance = 0;
        }

        // FUN_0x723C5C
        // +0xE0
        virtual float vFunc0xE0()
        {
            return 0;
        }

        // FUN_0x724410
        // +0xE4
        virtual float vFunc0xE4()
        {
            return 0;
        }

        virtual void vFunc0xE8() = delete;    // +0xE8
        virtual void vFunc0xEC() = delete;    // +0xEC

        // FUN_0x5EB978
        // +0xF0
        virtual int vFunc0xF0()
        {
            return 0;
        }

        virtual void vFunc0xF4() = delete;    // +0xF4

        // FUN_0x723B48
        // +0xF8
        virtual void vFunc0xF8();

        // FUN_0x5F2274
        // +0xFC
        virtual int vFunc0xFC()
        {
            return 0;
        }

        // FUN_0x5E94CC
        // +0x100
        virtual void vFunc0x100()
        {
            return;
        }

        // FUN_0x5F5AC0
        // +0x104
        virtual void push(Entity *other, bool single);

        // FUN_0x5F5A10
        // +0x108
        virtual void push(const Vec3<float> &v)
        {
            mVelocity += v;
        }

        // FUN_0x5E94C0
        // +0x10C
        virtual void push(const Vec3<float> *v)
        {
            push(*v);
        }

        // FUN_0x723528
        // +0x110
        virtual void vFunc0x110();

        // FUN_0x5F75CC
        // +0x114
        virtual bool vFunc0x114()
        {
            return mSynchedEntityData.getFlag<int64_t>(0, 17);
        }

        // FUN_0x5E8828
        // +0x118
        virtual int vFunc0x118()
        {
            return 0;
        }

        // FUN_0x723520
        // +0x11C
        virtual bool vFunc0x11C()
        {
            return 1;
        }

        // FUN_0x723558
        // +0x120
        virtual int vFunc0x120()
        {
            return 0;
        }

        // FUN_0x724710
        // +0x124
        virtual int vFunc0x124()
        {
            return vFunc0x120();
        }

        virtual void vFunc0x128() = delete;    // +0x128

        // FUN_0x723560
        // +0x12C
        virtual bool isSneaking()
        {
            return false;
        }

        // FUN_0x724EC8
        // +0x130
        virtual bool isAlive()
        {
            return !mRemoved;
        }

        // FUN_0x725350
        // +0x134
        virtual bool isOnFire()
        {
            return (0 < mFire) || getSharedFlag(SynchedEntityData::EntitySharedFlag::Burning);
        }

        // FUN_0x725564
        // +0x138
        virtual bool isOnHotBlock()
        {
            return mOnHotBlock;
        }

        virtual void vFunc0x13C() = delete;    // +0x13C

        // FUN_0x723AB8
        // +0x140
        virtual bool vFunc0x140()
        {
            return 1;
        }

        // FUN_0x723AC0
        // +0x144
        virtual bool vFunc0x144()
        {
            return 1;
        }

        // FUN_0x5F8480
        // +0x148
        virtual void vFunc0x148();

        virtual void vFunc0x14C() = delete;    // +0x14C

        // FUN_0x5F7AD0
        // +0x150
        virtual void vFunc0x150();

        // FUN_0x5E8EF0
        // +0x154
        virtual void vFunc0x154();

        // FUN_0x5F65C4
        // +0x158
        virtual void vFunc0x158()
        {
            return;
        }

        // FUN_0x5E9E90
        // +0x15C
        virtual void vFunc0x15C()
        {
            return;
        }

        // FUN_0x5F65C0
        // +0x160
        virtual void vFunc0x160()
        {
            return;
        }

        // FUN_0x724428
        // +0x164
        virtual int vFunc0x164();

        // FUN_0x723C48
        // +0x168
        virtual int vFunc0x168();

        // FUN_0x723BD4
        // +0x16C
        virtual int vFunc0x16C();

        // FUN_0x5E9528
        // +0x170
        virtual void vFunc0x170(bool p1);

        // FUN_0x7236F0
        // +0x174
        virtual bool vFunc0x174();

        // FUN_0x5ECC64
        // +0x178
        virtual void vFunc0x178(bool p1);

        // FUN_0x723AC8
        // +0x17C
        virtual bool vFunc0x17C()
        {
            return !isInvisible();
        }

        // FUN_0x7244F4
        // +0x180
        virtual void vFunc0x180();

        // FUN_0x5E9384
        // +0x184
        virtual void vFunc0x184();

        // FUN_0x5E850C
        // +0x188
        virtual void vFunc0x188();

        // FUN_0x5EB694
        // +0x18C
        virtual void vFunc0x18C();

        // FUN_0x5EC234
        // +0x190
        virtual void vFunc0x190()
        {
            return;
        }

        // FUN_0x5F326C
        // +0x194
        virtual void vFunc0x194();

        // FUN_0x5ED570
        // +0x198
        virtual void vFunc0x198();

        // FUN_0x5EA2BC
        // +0x19C
        virtual float vFunc0x19C()
        {
            return 0.1f;
        }

        // FUN_0x5ECE08
        // +0x1A0
        virtual void spawnAtLocation(u16 id, u8 amount)
        {
            spawnAtLocation(id, amount, 0);
        }

        // FUN_0x5ECE1C
        // +0x1A4
        virtual void spawnAtLocation(u16 id, u8 amount, float y)
        {
            spawnAtLocation(ItemInstance(id, amount, 0), y);
        }

        // FUN_0x5ECC90
        // +0x1A8
        virtual void spawnAtLocation(BlockData blockData)
        {
            spawnAtLocation(blockData, 0);
        }

        // FUN_0x5ECCC4
        // +0x1AC
        virtual void spawnAtLocation(BlockData blockData, float y);

        // FUN_0x5ECD50
        // +0x1B0
        virtual void spawnAtLocation(const ItemInstance &item, float y);

        // FUN_0x5F6520
        // +0x1B4
        virtual void vFunc0x1B4()
        {
            return;
        }

        virtual void vFunc0x1B8() = delete;    // +0x1B8
        virtual void vFunc0x1BC() = delete;    // +0x1BC

        // FUN_0x5ECC70
        // +0x1C0
        virtual void vFunc0x1C0(int slot, const ItemInstance &set)
        {
            return;
        }

        // FUN_0x5F5CAC
        // +0x1C4
        virtual void vFunc0x1C4();

        // FUN_0x5EA2C8
        // +0x1C8
        virtual void vFunc0x1C8();

        // FUN_0x5F33D0
        // +0x1CC
        virtual void vFunc0x1CC();

        // FUN_0x5F80C0
        // +0x1D0
        virtual void vFunc0x1D0();

        virtual int getEntityTypeId() = 0;    // +0x1D4

        // FUN_0x5F2C40
        // +0x1D8
        virtual int vFunc0x1D8()
        {
            return 0;
        }

        // FUN_0x5EF8BC
        // +0x1DC
        virtual int vFunc0x1DC()
        {
            return 0;
        }

        // FUN_0x7245D8
        // +0x1E0
        virtual void vFunc0x1E0();

        // FUN_0x5F83F8
        // +0x1E4
        virtual void vFunc0x1E4();

        // FUN_0x7245FC
        // +0x1E8
        virtual void vFunc0x1E8();

        // FUN_0x5EE85C
        // +0x1EC
        virtual void vFunc0x1EC();

        // FUN_0x7245A0
        // +0x1F0
        virtual void vFunc0x1F0();

        // FUN_0x7245A8
        // +0x1F4
        virtual void vFunc0x1F4();

        // FUN_0x7241B8
        // +0x1F8
        virtual int getLastDimensionId()
        {
            return mLastDimensionId;
        }

        // FUN_0x724724
        // +0x1FC
        virtual int vFunc0x1FC()
        {
            return 1;
        }

        // FUN_0x5EB9C4
        // +0x200
        virtual void vFunc0x200();

        virtual void vFunc0x204() = delete;    // +0x204

        // FUN_0x724A50
        // +0x208
        virtual void vFunc0x208();

        // FUN_0x5EBA38
        // +0x20C
        virtual void vFunc0x20C();

        // FUN_0x5EB980
        // +0x210
        virtual void vFunc0x210();

        // FUN_0x5F2D9C
        // +0x214
        virtual void vFunc0x214()
        {
            return;
        }

        // FUN_0x5F20CC
        // +0x218
        virtual void vFunc0x218();

        // FUN_0x5EF510
        // +0x21C
        virtual void vFunc0x21C(int p1);

        // FUN_0x723580
        // +0x220
        virtual void vFunc0x220();

        // FUN_0x724A60
        // +0x224
        virtual int vFunc0x224();

        // FUN_0x7254EC
        // +0x228
        virtual void vFunc0x228();

        virtual void vFunc0x22C() = delete;    // +0x22C
        virtual void vFunc0x230() = delete;    // +0x230

        // FUN_0x5F8678
        // +0x234
        virtual void vFunc0x234();

        // FUN_0x72397C
        // +0x238
        virtual float vFunc0x238()
        {
            return mHeight * 0.85f;
        }

        // FUN_0x5F24C0
        // +0x23C
        virtual void sendMotionPacketIfNeeded();

        // FUN_0x724A78
        // +0x240
        virtual int vFunc0x240()
        {
            return 1;
        }

        // FUN_0x5E8FB4
        // +0x244
        virtual void vFunc0x244();

        virtual void vFunc0x248() = delete;    // +0x248

        // FUN_0x5F227C
        // +0x24C
        virtual void vFunc0x24C();

        // FUN_0x724F30
        // +0x250
        virtual void vFunc0x250(ItemInstance &item)
        {
            item.sub(1);
        }

        virtual void vFunc0x254() = delete;    // +0x254
        virtual void vFunc0x258() = delete;    // +0x258
        virtual void vFunc0x25C() = delete;    // +0x25C
        virtual void vFunc0x260() = delete;    // +0x260
        virtual void vFunc0x264() = delete;    // +0x264

        // FUN_0x5F24B0
        // +0x268
        virtual void vFunc0x268();

        // FUN_0x5F2D88
        // +0x26C
        virtual void vFunc0x26C();

        // FUN_0x72366C
        // +0x270
        virtual float vFunc0x270();

        // FUN_0x5EB674
        // +0x274
        virtual bool isWorldBuilder();

        // FUN_0x723518
        // +0x278
        virtual bool isCreative()
        {
            return false;
        }

        // FUN_0x7236B0
        // +0x27C
        virtual bool isAdventure()
        {
            return false;
        }

        // FUN_0x5F2E24
        // +0x280
        virtual void vFunc0x280();

        // FUN_0x5F2F38
        // +0x284
        virtual void drop(ItemInstance &item, bool randomly);

        // FUN_0x724408
        // +0x288
        virtual void vFunc0x288();

        // FUN_0x5E9518
        // +0x28C
        virtual void vFunc0x28C();

        // FUN_0x5F6B6C
        // +0x290
        virtual void vFunc0x290();

        virtual void vFunc0x294() = delete;    // +0x294

        // FUN_0x5E8CBC
        // +0x298
        virtual void vFunc0x298();

        // FUN_0x5F6364
        // +0x29C
        virtual void damage(const DamageSource &source, int value, int p3, int p4);

        // FUN_0x5F769C
        // +0x2A0
        virtual void vFunc0x2A0()
        {
            m0x2F5 = 1;
        }

        // FUN_0x5F75E4
        // +0x2A4
        virtual void vFunc0x2A4();

        // FUN_0x5F2290
        // +0x2A8
        virtual void vFunc0x2A8();

        // FUN_0x5F1CE0
        // +0x2AC
        virtual void vFunc0x2AC();

        // FUN_0x5EB0D8
        // +0x2B0
        virtual void vFunc0x2B0();

        // FUN_0x5ED340
        // +0x2B4
        virtual void vFunc0x2B4();

        // FUN_0x5EC238
        // +0x2B8
        virtual void vFunc0x2B8();

        // FUN_0x5ECFA8
        // +0x2BC
        virtual void vFunc0x2BC();

        // FUN_0x5EF13C
        // +0x2C0
        virtual void vFunc0x2C0();

        // FUN_0x5EE1F0
        // +0x2C4
        virtual void vFunc0x2C4();

        // FUN_0x5EE318
        // +0x2C8
        virtual void vFunc0x2C8();

        // FUN_0x5ECE9C
        // +0x2CC
        virtual void vFunc0x2CC()
        {
            return;
        }

        // FUN_0x5E9D04
        // +0x2D0
        virtual void vFunc0x2D0();

        // FUN_0x5EF4B4
        // +0x2D4
        virtual int vFunc0x2D4()
        {
            return 0;
        }

        // FUN_0x5E9784
        // +0x2D8
        virtual void _removeRider();

    protected:
        // 0x9CB70C

        u8                                     m0x4;    // +0x4
        gstd::type_unknown<0x188>              m0x8;    // +0x8 多分ゴミデータ
        void                                  *m0x190;    // +0x190
        void                                  *m0x194;    // +0x194
        int                                    mLastDimensionId;    // +0x198
        u8                                     m0x19C;    // +0x19C
        Level                                 *mLevel;    // +0x1A0
        void                                  *m0x1A4;    // +0x1A4
        gstd::unique_ptr<gstd::type_unknown<>> m0x1A8;    // +0x1A8
        int                                    m0x1AC;    // +0x1AC
        EntityUniqueID                         mUniqueID;    // +0x1B0
        BoxedPtr::Shared<gstd::type_unknown<>> m0x1BC;    // +0x1BC
        Vec3<float>                            mPosition;    // +0x1C4
        Vec3<float>                            m0x1CC;    // +0x1CC
        Vec3<float>                            m0x1D8;    // +0x1D8
        Vec3<float>                            mVelocity;    // +0x1E4
        Vec2<float>                            mRot;    // +0x1F0
        Vec2<float>                            mRotPrev;    // +0x1F8
        float                                  m0x200;    // +0x200
        float                                  m0x204;    // +0x204
        int                                    m0x208;    // +0x208
        int                                    m0x20C;    // +0x20C
        BlockSource                           *mRegion;    // +0x210
        Vec3<float>                            m0x214;    // +0x214
        Vec3<float>                            m0x220;    // +0x220
        int                                    m0x22C;    // +0x22C
        SynchedEntityData                      mSynchedEntityData;    // +0x230
        gstd::unique_ptr<gstd::type_unknown<>> m0x240;    // +0x240
        Vec3<float>                            m0x244;    // +0x244
        float                                  m0x250;    // +0x250
        float                                  m0x254;    // +0x254
        bool                                   m0x258;    // +0x258
        bool                                   m0x259;    // +0x259

    public:
        bool    mOnGround;    // +0x25A
        bool    mWasOnGround;    // +0x25B
        bool    mHorizontalCollision;    // +0x25C
        bool    mVerticalCollision;    // +0x25D
        bool    mCollision;    // +0x25E
        BlockId mInsideBlockId;    // +0x25F
        float   mFallDistance;    // +0x260

    protected:
        int                                m0x264;    // +0x264
        float                              m0x268;    // +0x268
        float                              m0x26C;    // +0x26C
        float                              m0x270;    // +0x270
        float                              m0x274;    // +0x274
        int                                mRendererId;    // +0x278
        float                              m0x27C;    // +0x27C
        float                              m0x280;    // +0x280
        void                              *m0x284;    // +0x284
        AABB                               m0x288;    // +0x288
        gstd::vector<gstd::type_unknown<>> m0x2A4;    // +0x2A4
        float                              mWidth;    // +0x2B0
        float                              mHeight;    // +0x2B4
        float                              m0x2B8;    // +0x2B8
        float                              m0x2BC;    // +0x2BC
        float                              m0x2C0;    // +0x2C0
        float                              mStepHeight;    // +0x2C4
        float                              m0x2C8;    // +0x2C8
        float                              m0x2CC;    // +0x2CC
        float                              m0x2D0;    // +0x2D0
        float                              m0x2D4;    // +0x2D4
        int                                m0x2D8;    // +0x2D8
        bool                               mInWeb;    // +0x2DC
        u8                                 m0x2DD;    // +0x2DD
        bool                               mWasInWater;    // +0x2DE
        int                                m0x2E0;    // +0x2E0
        int                                m0x2E4;    // +0x2E4
        int                                m0x2E8;    // +0x2E8
        int                                m0x2EC;    // +0x2EC
        int                                mHurtTime;    // +0x2F0
        u8                                 m0x2F4;    // +0x2F4
        u8                                 m0x2F5;    // +0x2F5
        u8                                 mInvulnerable;    // +0x2F6
        bool                               mFireResistance;    // +0x2F7
        u8                                 m0x2F8;    // +0x2F8
        int                                mFire;    // +0x2FC
        bool                               mOnHotBlock;    // +0x300
        int                                m0x304;    // +0x304
        u8                                 m0x308;    // +0x308
        u8                                 m0x309;    // +0x309

    public:
        int      mPortalCooldown;    // +0x30C
        BlockPos mPortalBlockPos;    // +0x310
        int      mPortalEntranceAxis;    // +0x31C
        int      mInsidePortalTime;    // +0x320

    protected:
        gstd::vector<gstd::type_unknown<>>     m0x324;    // +0x324
        gstd::vector<gstd::type_unknown<>>     m0x330;    // +0x330
        gstd::vector<gstd::type_unknown<>>     m0x33C;    // +0x33C
        Entity                                *mRideEntity;    // +0x348
        int                                    m0x34C;    // +0x34C
        int                                    m0x350;    // +0x350
        int                                    m0x354;    // +0x354
        u8                                     m0x358;    // +0x358
        u8                                     m0x359;    // +0x359
        Entity                                *mFishingHookEntity;    // +0x35C
        u8                                     m0x360;    // +0x360
        u8                                     m0x361;    // +0x361
        u8                                     m0x362;    // +0x362
        u8                                     m0x363;    // +0x363
        u8                                     m0x364;    // +0x364
        float                                  m0x368;    // +0x368
        Random                                 m0x36C;    // +0x36C
        int                                    m0xD40;    // +0xD40
        int                                    m0xD44;    // +0xD44
        u8                                     m0xD48;    // +0xD48
        bool                                   m0xD49;    // +0xD49
        u8                                     m0xD4A;    // +0xD4A
        bool                                   mRemoved;    // +0xD4B
        u8                                     mGlobal;    // +0xD4C
        u8                                     mAutonomous;    // +0xD4D
        void                                  *m0xD50;    // +0xD50
        gstd::unique_ptr<gstd::type_unknown<>> m0xD54;    // +0xD54
        gstd::unique_ptr<gstd::type_unknown<>> m0xD58;    // +0xD58
        gstd::unique_ptr<gstd::type_unknown<>> m0xD5C;    // +0xD5C
        gstd::unique_ptr<gstd::type_unknown<>> m0xD60;    // +0xD60
        gstd::unique_ptr<gstd::type_unknown<>> m0xD64;    // +0xD64
        gstd::unique_ptr<gstd::type_unknown<>> m0xD68;    // +0xD68
        gstd::unique_ptr<gstd::type_unknown<>> m0xD6C;    // +0xD6C
        gstd::unique_ptr<gstd::type_unknown<>> m0xD70;    // +0xD70
        gstd::unique_ptr<gstd::type_unknown<>> m0xD74;    // +0xD74
        gstd::unique_ptr<gstd::type_unknown<>> m0xD78;    // +0xD78
        gstd::unique_ptr<gstd::type_unknown<>> m0xD7C;    // +0xD7C
        gstd::unique_ptr<gstd::type_unknown<>> m0xD80;    // +0xD80
        gstd::unique_ptr<gstd::type_unknown<>> m0xD84;    // +0xD84
        gstd::unique_ptr<gstd::type_unknown<>> m0xD88;    // +0xD88
        gstd::unique_ptr<gstd::type_unknown<>> m0xD8C;    // +0xD8C
        gstd::unique_ptr<gstd::type_unknown<>> m0xD90;    // +0xD90
        gstd::unique_ptr<gstd::type_unknown<>> m0xD94;    // +0xD94
        gstd::unique_ptr<gstd::type_unknown<>> m0xD98;    // +0xD98
        gstd::unique_ptr<gstd::type_unknown<>> m0xD9C;    // +0xD9C
        gstd::unique_ptr<gstd::type_unknown<>> m0xDA0;    // +0xDA0
        gstd::unique_ptr<gstd::type_unknown<>> m0xDA4;    // +0xDA4
        gstd::unique_ptr<gstd::type_unknown<>> m0xDA8;    // +0xDA8
        gstd::unique_ptr<gstd::type_unknown<>> m0xDAC;    // +0xDAC
        gstd::unique_ptr<gstd::type_unknown<>> m0xDB0;    // +0xDB0
        gstd::unique_ptr<gstd::type_unknown<>> m0xDB4;    // +0xDB4
        gstd::unique_ptr<gstd::type_unknown<>> m0xDB8;    // +0xDB8
        gstd::unique_ptr<gstd::type_unknown<>> m0xDBC;    // +0xDBC
        gstd::unique_ptr<gstd::type_unknown<>> m0xDC0;    // +0xDC0
        gstd::unique_ptr<gstd::type_unknown<>> m0xDC4;    // +0xDC4
        gstd::unique_ptr<gstd::type_unknown<>> m0xDC8;    // +0xDC8
        gstd::unique_ptr<gstd::type_unknown<>> m0xDCC;    // +0xDCC
        gstd::unique_ptr<gstd::type_unknown<>> m0xDD0;    // +0xDD0
        gstd::unique_ptr<gstd::type_unknown<>> m0xDD4;    // +0xDD4
        gstd::unique_ptr<gstd::type_unknown<>> m0xDD8;    // +0xDD8
        gstd::unique_ptr<gstd::type_unknown<>> m0xDDC;    // +0xDDC
        gstd::unique_ptr<gstd::type_unknown<>> m0xDE0;    // +0xDE0
        gstd::unique_ptr<gstd::type_unknown<>> m0xDE4;    // +0xDE4
        gstd::unique_ptr<gstd::type_unknown<>> m0xDE8;    // +0xDE8
        gstd::unique_ptr<gstd::type_unknown<>> m0xDEC;    // +0xDEC
        int                                    m0xDF0;    // +0xDF0
        int                                    m0xDF4;    // +0xDF4
        u8                                     m0xDF8;    // +0xDF8
        float                                  m0xDFC;    // +0xDFC
        int                                    m0xE00;    // +0xE00
        int                                    m0xE04;    // +0xE04
        int                                    m0xE08;    // +0xE08
        int                                    m0xE0C;    // +0xE0C
        int                                    m0xE10;    // +0xE10
        int                                    m0xE14;    // +0xE14
        int                                    mRuntimeID[2];    // +0xE18
        float                                  m0xE20;    // +0xE20
        float                                  m0xE24;    // +0xE24
        float                                  m0xE28;    // +0xE28
        float                                  m0xE2C;    // +0xE2C
        u8                                     m0xE30;    // +0xE30
        int                                    m0xE34;    // +0xE34
        int                                    m0xE38;    // +0xE38
        int                                    m0xE3C;    // +0xE3C
        int                                    m0xE40;    // +0xE40
        gstd::unique_ptr<gstd::type_unknown<>> m0xE44;    // +0xE44
        int                                    m0xE48;    // +0xE48
        int                                    m0xE4C;    // +0xE4C
        int                                    m0xE50;    // +0xE50
        int                                    m0xE54;    // +0xE54
        int                                    m0xE58;    // +0xE58
        int                                    m0xE5C;    // +0xE5C
        int                                    m0xE60;    // +0xE60
        int                                    m0xE64;    // +0xE64
        int                                    m0xE68;    // +0xE68
        int                                    m0xE6C;    // +0xE6C
        gstd::unique_ptr<gstd::type_unknown<>> m0xE70;    // +0xE70
    };
}    // namespace MC3DSPluginFramework