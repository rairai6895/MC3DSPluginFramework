#pragma once

#include "../Attribute/AttributeInstance.hpp"
#include "../Effect/MobEffectInstance.hpp"
#include "../Item/Item.hpp"
#include "Entity.hpp"

namespace MC3DSPluginFramework
{
    class Mob : public Entity
    {
    public:
        void createAIGoals()
        {
            reinterpret_cast<void (*)(Mob *)>(0x4E504C)(this);
        }

        // FUN_0x7142C4
        const MobEffectInstance *getEffectInstance(const Effect &effect) const
        {
            for (auto &instance : mEffects)
                if (instance.isType(effect))
                    return &instance;

            return nullptr;
        }

        // FUN_0x71435C
        bool isEffected(const Effect &effect) const
        {
            return getEffectInstance(effect);
        }

        // FUN_0x714334
        int getHealth()
        {
            return getAttributeInstance(Attribute::Health).getCurrentValue();
        }

        bool isMoving() const
        {
            return m0x10BC;
        }

        void setAirMoveSpeed(float set)
        {
            m0x1038 = set;
        }

        void setHurtCamera(int set)
        {
            mHurtCamera = set;
        }

        void setWalkAnimSpeed(float set)
        {
            mWalkAnimSpeed = set;
        }

        void setJumpCooldown(int set)
        {
            mJumpCooldown = set;
        }

        ItemInstance &getOffhandSlot()
        {
            return mOffhandItemInstance;
        }

    public:
        // FUN_0x4EA100
        void vFunc0x8() override;

        // FUN_0x4E8294
        // +0xC
        void initializeComponents(u8 unknown) override;

        // FUN_0x713A24
        void vFunc0x14() override;

        // FUN_0x4EF0DC
        // +0x20
        ~Mob() override;

        // FUN_0x714074
        void vFunc0x50() override;

        // FUN_0x3F6348
        // +0x64
        void teleportTo(const Vec3<float> &pos, int teleportationCause, int teleportationItem) override;

        // FUN_0x3F6594
        void vFunc0x6C() override;

        // FUN_0x4E302C
        // +0x80
        void tick() override;

        // FUN_0x4ED494
        void vFunc0x84() override;

        // FUN_0x4EDA28
        void vFunc0x88() override;

        // FUN_0x713AEC
        float vFunc0xE0() override
        {
            return mHeight * 0.85f;
        }

        // FUN_0x5EA920
        void vFunc0x100() override
        {
            m0xDF8 = 1;
        }

        // FUN_0x713824
        void vFunc0x110() override;

        // FUN_0x4E3008
        int vFunc0x118() override;

        // FUN_0x713880
        int vFunc0x120() override;

        // FUN_0x7138C0
        // +0x12C
        bool isSneaking() override
        {
            return getSharedFlag(SynchedEntityData::EntitySharedFlag::Sneak);
        }

        // FUN_0x714208
        // +0x130
        bool isAlive() override
        {
            return !Entity::isRemoved() || getAttributeInstance(Attribute::Health).getCurrentValue() >= 1;
        }

        // FUN_0x4EE648
        void vFunc0x148() override;

        // FUN_0x71398C
        bool vFunc0x174() override;

        // FUN_0x4E3780
        void vFunc0x184() override;

        // FUN_0x4E7C90
        void vFunc0x198() override;

        // FUN_0x4EE5D0
        void vFunc0x1E4() override;

        // FUN_0x4E6298
        void vFunc0x210() override;

        // FUN_0x7208C8
        void vFunc0x220() override;

        // FUN_0x71406C
        int vFunc0x224() override
        {
            return 1;
        }

        // FUN_0x714370
        void vFunc0x228() override;

        // FUN_0x4E376C
        void vFunc0x244() override;

        // FUN_0x713978
        float vFunc0x270() override
        {
            return m0xE7C;
        }

        // FUN_0x4E36BC
        void vFunc0x298() override;

        // FUN_0x4EBAC8
        void damage(const DamageSource &source, int value, int p3, int p4) override;

        // FUN_0x4EA39C
        void vFunc0x2A8() override;

        // FUN_0x4E9760
        void vFunc0x2AC() override;

        // FUN_0x4E5CBC
        void vFunc0x2B0() override;

        // FUN_0x4E40E8
        // +0x2D8
        void _removeRider() override;

        // FUN_0x4EE4D0
        virtual void vFunc0x2DC();

        // FUN_0x4EB720
        virtual void vFunc0x2E0();

        // FUN_0x4E752C
        virtual void vFunc0x2E4();

        // FUN_0x714134
        virtual void vFunc0x2E8();

        // FUN_0x4EE680
        virtual void vFunc0x2EC()
        {
            return;
        }

        // FUN_0x7138B8
        virtual u8 vFunc0x2F0();

        // FUN_0x4E3E18
        virtual void vFunc0x2F4();

        // FUN_0x713984
        virtual void vFunc0x2F8();

        // FUN_0x4E4C84
        virtual void vFunc0x2FC();

        virtual void vFunc0x300() = delete;

        // FUN_0x4E7414
        virtual void vFunc0x304();

        // FUN_0x4EB710
        virtual int vFunc0x308()
        {
            return 0xA0;
        }

        // FUN_0x6B29C4
        virtual void vFunc0x30C();

        // FUN_0x714264
        virtual void vFunc0x310();

        // FUN_0x4EDA68
        virtual void vFunc0x314(float p1)
        {
            m0x10B4 = m0x1088 = p1;
        }

        // FUN_0x7139D0
        virtual void vFunc0x318();

        // FUN_0x4EB9C0
        virtual void vFunc0x31C();

        // FUN_0x4E41C4
        virtual void vFunc0x320();

        // FUN_0x4E37AC
        virtual void vFunc0x324();

        // FUN_0x4EB5D4
        virtual void vFunc0x328();

        // FUN_0x4EA328
        virtual void vFunc0x32C();

        // FUN_0x4E425C
        virtual void vFunc0x330();

        // FUN_0x71404C
        virtual void vFunc0x334();

        // FUN_0x4EC674
        virtual void vFunc0x338();

        // FUN_0x4E7EB0
        virtual void vFunc0x33C();

        // FUN_0x4E608C
        virtual void vFunc0x340();

        // FUN_0x4EBDF4
        virtual void vFunc0x344();

        // FUN_0x4E4948
        virtual void vFunc0x348();

        // FUN_0x4EC4A8
        virtual void vFunc0x34C();

        virtual void vFunc0x350() = delete;

        // FUN_0x4E657C
        virtual void vFunc0x354();

        // FUN_0x714000
        virtual void vFunc0x358();

        // FUN_0x713DEC
        virtual bool vFunc0x35C()
        {
            return m0xDF8 == 0;
        }

        // FUN_0x4E576C
        virtual void vFunc0x360();

        // FUN_0x4E8174
        virtual void vFunc0x364()
        {
            return;
        }

        // FUN_0x713E38
        // +0x368
        virtual ItemInstance &getMainhandItem()
        {
            return mMainhandItemInstance;
        }

        // FUN_0x4E5FFC
        // +0x36C
        virtual void setMainhandItem(const ItemInstance &set)
        {
            mMainhandItemInstance = set;
        }

        // FUN_0x4E7ECC
        virtual int vFunc0x370()
        {
            return 0;
        }

        // FUN_0x4EB5BC
        virtual float vFunc0x374()
        {
            return 0;
        }

        // FUN_0x4EB704
        virtual float vFunc0x378()
        {
            return 0;
        }

        // FUN_0x4EBD28
        // +0x37C
        virtual void swing();

        // FUN_0x4E7C80
        virtual int vFunc0x380()
        {
            return m0x1028;
        }

        // FUN_0x4EB718
        virtual void vFunc0x384()
        {
            return;
        }

        // FUN_0x4E5DC0
        virtual float vFunc0x388()
        {
            return 40;
        }

        // FUN_0x4E73C0
        virtual void vFunc0x38C();

        // FUN_0x4E783C
        virtual void vFunc0x390();

        // FUN_0x4E8118
        virtual void vFunc0x394();

        // FUN_0x4E8178
        virtual void vFunc0x398();

        // FUN_0x4E5D5C
        virtual void vFunc0x39C();

        // FUN_0x4E6014
        virtual void vFunc0x3A0();

        // FUN_0x4EE1AC
        virtual void vFunc0x3A4();

        // FUN_0x4E3000
        virtual void vFunc0x3A8();

        // FUN_0x4E45B0
        virtual void vFunc0x3AC();

        virtual void vFunc0x3B0() = delete;

        // FUN_0x4E47DC
        virtual void vFunc0x3B4();

        // FUN_0x5CA4C4
        virtual void vFunc0x3B8();

        // FUN_0x713E50
        virtual void vFunc0x3BC();

        // FUN_0x713E24
        virtual void vFunc0x3C0();

        // FUN_0x2E9564
        // +0x3C4
        virtual AttributeInstance *tryGetAttributeInstance(const Attribute &key);

        // FUN_0x6DAB5C
        // +0x3C8
        virtual AttributeInstance &getAttributeInstance(const Attribute &key);

        // FUN_0x713F60
        virtual void vFunc0x3CC();

        // FUN_0x4E5728
        virtual void vFunc0x3D0();

        // FUN_0x7140F0
        virtual void vFunc0x3D4();

        // FUN_0x4EE440
        virtual void vFunc0x3D8();

        // FUN_0x4EDA54
        // +0x3DC
        virtual void setArmorSlot(int index, const ItemInstance &set)
        {
            m0xF40[index] = set;
        }

        // FUN_0x714254
        // +0x3E0
        virtual ItemInstance &getArmorSlot(int index)
        {
            return m0xF40[index];
        }

        // FUN_0x4E6EDC
        virtual void vFunc0x3E4();

        // FUN_0x4E6D74
        virtual void vFunc0x3E8();

        virtual void vFunc0x3EC() = delete;

        // FUN_0x7138C8
        virtual void vFunc0x3F0();

        // FUN_0x7137A4
        virtual void vFunc0x3F4();

        // FUN_0x713E7C
        virtual void vFunc0x3F8();

        // FUN_0x4E72DC
        virtual void vFunc0x3FC();

        // FUN_0x713B00
        virtual void vFunc0x400();

        // FUN_0x4E4FC4
        virtual void vFunc0x404();

        // FUN_0x4E8288
        virtual void vFunc0x408();

        // FUN_0x4EB4F8
        virtual void vFunc0x40C();

        // FUN_0x4EC660
        virtual void vFunc0x410()
        {
            return;
        }

        // FUN_0x4EC664
        virtual void vFunc0x414()
        {
            return;
        }

        // FUN_0x4E3D08
        virtual void vFunc0x418();

        // FUN_0x713F54
        virtual float vFunc0x41C()
        {
            return 0.8f;
        }

        // FUN_0x4E6054
        // +0x420
        virtual void setOffhandItem(const ItemInstance &set)
        {
            set.isNull() ? mOffhandItemInstance.setNull() : mOffhandItemInstance = set;
        }

        // FUN_0x4E7348
        virtual ItemInstance &vFunc0x424()
        {
            ItemInstance &offhand = mOffhandItemInstance;

            if (!offhand.isNull() && offhand.isType(Item::totem))
                return offhand;

            ItemInstance &mainhand = mMainhandItemInstance;

            if (!mainhand.isNull() && mainhand.isType(Item::totem))
                return mainhand;

            return ItemInstance::EMPTY_ITEM;
        }

        // FUN_0x4E44F4
        // +0x428
        virtual bool consumeTotem()
        {
            if (!mOffhandItemInstance.isNull() && mOffhandItemInstance.isType(Item::totem))
            {
                mOffhandItemInstance.setNull();
                return true;
            }

            ItemInstance &mainhand = getMainhandItem();

            if (!mainhand.isNull() && mainhand.isType(Item::totem))
            {
                setMainhandItem(ItemInstance());
                return true;
            }

            return false;
        }

        // FUN_0x4E61E4
        virtual void vFunc0x42C();

        // FUN_0x4E57A4
        virtual int vFunc0x430()
        {
            return 0x14;
        }

        // FUN_0x4E80C8
        virtual float vFunc0x434()
        {
            return 0;
        }

        // FUN_0x7140D8
        virtual bool vFunc0x438()
        {
            return m0x1144 == 2;
        }

        // FUN_0x4E7E98
        virtual void vFunc0x43C()
        {
            m0xDF8 == 0;
        }

        // FUN_0x4E5DE4
        virtual void vFunc0x440();

        // FUN_0x4EDA88
        virtual void vFunc0x444();

        // FUN_0x4E6684
        virtual void vFunc0x448();

        // FUN_0x4E6ED8
        virtual void vFunc0x44C()
        {
            return;
        }

        // FUN_0x4EB408
        virtual void vFunc0x450();

        // FUN_0x713F94
        virtual int vFunc0x454()
        {
            return 0;
        }

        // FUN_0x4E52D8
        virtual void vFunc0x458();

        // FUN_0x4ED970
        virtual void vFunc0x45C();

        // FUN_0x4E51E0
        virtual void vFunc0x460();

        // FUN_0x7142BC
        virtual int vFunc0x464()
        {
            return 1;
        }

        // FUN_0x4EE684
        virtual void vFunc0x468();

        // FUN_0x4E5898
        virtual void vFunc0x46C();

        // FUN_0x4E6928
        virtual void vFunc0x470();

        // FUN_0x4E67D4
        virtual void vFunc0x474();

        // FUN_0x4ED46C
        virtual void vFunc0x478();

    protected:
        // 0x9C6E24

        float                           m0xE74;
        float                           m0xE78;
        float                           m0xE7C;
        float                           m0xE80;
        int                             m0xE84;
        int                             m0xE88;
        int                             mHurtCamera;    // +0xE8C
        float                           m0xE90;
        int                             m0xE94;
        int                             m0xE98;
        int                             m0xE9C;
        int                             m0xEA0;
        int                             m0xEA4;
        int                             m0xEA8;
        float                           m0xEAC;
        u8                              m0xEB0;
        u8                              m0xEB1;
        int                             m0xEB4;
        float                           m0xEB8;
        float                           m0xEBC;
        float                           m0xEC0;
        int                             m0xEC4;
        int                             m0xEC8;
        float                           m0xECC;
        float                           m0xED0;
        float                           m0xED4;
        ItemInstance                    mMainhandItemInstance;    // +0xED8
        ItemInstance                    mOffhandItemInstance;    // +0xF08
        float                           m0xF38;
        float                           m0xF3C;
        ItemInstance                    m0xF40[4];
        float                           m0x1000;
        float                           m0x1004;
        float                           m0x1008;
        float                           m0x100C;
        void                           *mAttributes;
        gstd::vector<MobEffectInstance> mEffects;    // +0x1014
        float                           mWalkAnimSpeed;    // +0x1020
        u8                              m0x1024;
        int                             m0x1028;
        int                             m0x102C;
        float                           m0x1030;
        float                           m0x1034;
        float                           m0x1038;
        void                           *m0x103C;
        float                           m0x1040;
        float                           m0x1044;
        float                           m0x1048;
        float                           m0x104C;
        float                           m0x1050;
        float                           m0x1054;
        int                             m0x1058;
        int                             m0x105C;
        int                             m0x1060;
        int                             m0x1064;
        int                             m0x1068;
        int                             m0x106C;
        int                             m0x1070;
        int                             m0x1074;
        u8                              m0x1078;
        u8                              m0x1079;
        int                             mJumpCooldown;    // +0x107C
        float                           m0x1080;
        u8                              m0x1084;
        float                           m0x1088;
        void                           *m0x108C;
        void                           *m0x1090;
        void                           *m0x1094;
        int                             m0x1098;
        int                             m0x109C;
        int                             m0x10A0;
        int                             m0x10A4;
        int                             m0x10A8;
        int                             m0x10AC;
        float                           m0x10B0;
        float                           m0x10B4;
        float                           m0x10B8;
        u8                              m0x10BC;
        u8                              m0x10BD;
        u8                              m0x10BE;
        int                             m0x10C0;
        int                             m0x10C4;
        int                             m0x10C8;
        int                             m0x10CC;
        int                             m0x10D0;
        int                             m0x10D4;
        int                             m0x10D8;
        int                             m0x10DC;
        int                             m0x10E0;
        int                             m0x10E4;
        int                             m0x10E8;
        int                             m0x10EC;
        int                             m0x10F0;
        int                             m0x10F4;
        int                             m0x10F8;
        int                             m0x10FC;
        int                             m0x1100;
        int                             m0x1104;
        int                             m0x1108;
        int                             m0x110C;
        float                           m0x1110;
        float                           m0x1114;
        int                             m0x1118;
        int                             m0x111C;
        int                             m0x1120;
        int                             m0x1124;
        int                             m0x1128;
        int                             m0x112C;
        int                             m0x1130;
        int                             m0x1134;
        int                             m0x1138;
        int                             m0x113C;
        int                             m0x1140;
        int                             m0x1144;
    };
}    // namespace MC3DSPluginFramework