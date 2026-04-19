#pragma once

#include "Abilities.hpp"
#include "Minecraft/Common/Client/Gui/Components/SkinRenderer.hpp"
#include "Minecraft/Common/Client/Renderer/Entity/EntityRenderDispatcher.hpp"
#include "Minecraft/Common/Events/MinecraftEventing.hpp"
#include "Minecraft/Common/World/Entity/Mob.hpp"
#include "PlayerInventoryProxy.hpp"

namespace MC3DSPluginFramework
{

    namespace PlayerGameMode
    {
        enum {
            Survival,
            Creative,
            Adventure,
            Spectator_S,
            Spectator_C,
        };
    }    // namespace PlayerGameMode

    class LoopbackPacketSender;
    class ChunkSource;

    class Player : public Mob
    {
    public:
        // FUN_0x726090
        PlayerInventoryProxy &getSupplies() const
        {
            return *mPlayerInventoryProxy;
        }

        // FUN_0x735690
        u8 getPermissionsLevel() const
        {
            return mAbilities.getPermissionsLevel();
        }

        Abilities &getAbilities()
        {
            return mAbilities;
        }

        u8 getPlayerGameMode()
        {
            return mPlayerGameMode;
        }

        void attack(Mob &target)
        {
            reinterpret_cast<void (*)(Player *, Mob &)>(0x606020)(this, target);
        }

        Entity *getFishingHookEntity() const
        {
            return mFishingHookEntity;
        }

    public:
        // FUN_0x600D28
        void vFunc0x4() override;

        // FUN_0x602F3C
        // +0xC
        void initializeComponents(u8 p1) override;

        // FUN_0x6082F4
        // +0x20
        ~Player() override;

        // FUN_0x6065E8
        void vFunc0x30() override;

        // FUN_0x5FF364
        // +0x64
        void teleportTo(const Vec3<float> &pos, int teleportationCause, int teleportationItem) override
        {
            Mob::teleportTo(pos, 0, 1);
            m0x192A = 2;
            MinecraftEventing::fireEventPlayerTeleported(this, Vec3<float>(mPosition - pos).length(), teleportationCause, teleportationItem);
        }

        // FUN_0x5FF9A0
        // +0x7C
        gstd::unique_ptr<SynchedEntityData::DataItem<int>> vFunc0x7C() override;

        // FUN_0x5FEEDC
        // +0x80
        void tick() override;

        // FUN_0x60729C
        void vFunc0x88() override;

        // FUN_0x600CD8
        float vFunc0x90() override
        {
            return m0x2BC - 0.4f;
        }

        // FUN_0x72472C
        // +0xC4
        gstd::string copyName() override
        {
            return Entity::copyName();
        }

        // FUN_0x7261DC
        // +0xE0
        float vFunc0xE0() override
        {
            return isGliding() ? -1.1f : 0.12f;
        }

        // FUN_0x726B80
        // +0xE4
        float vFunc0xE4() override
        {
            return isGliding() ? -1.1f : 0;
        }

        // FUN_0x725F0C
        void vFunc0x110() override;

        // FUN_0x725F40
        // +0x120
        int vFunc0x120() override
        {
            return 0;
        }

        // FUN_0x7275FC
        // +0x124
        int vFunc0x124() override
        {
            return 1;
        }

        // FUN_0x7272B4
        void vFunc0x180() override;

        // FUN_0x600CEC
        // +0x190
        void vFunc0x190() override;

        // FUN_0x605B58
        // +0x194
        void vFunc0x194() override;

        // FUN_0x601868
        // +0x198
        void vFunc0x198() override;

        // FUN_0x600D58
        void vFunc0x1C0(int slot, const ItemInstance &set) override
        {
            m0xF40[slot] = set;
        }

        // +0x1D4
        int getEntityTypeId() override
        {
            return 0x13F;
        }

        // FUN_0x72741C
        // +0x1F0
        void vFunc0x1F0() override;

        // FUN_0x727424
        // +0x1F4
        void vFunc0x1F4() override;

        // FUN_0x602824
        void vFunc0x21C(int p1) override
        {
            Entity::vFunc0x21C(p1);
        }

        // FUN_0x72798C
        int vFunc0x224() override;

        // FUN_0x605430
        // +0x23C
        void sendMotionPacketIfNeeded() override;

        // FUN_0x727A2C
        void vFunc0x250(ItemInstance &item) override
        {
            if (!mAbilities.getBool(Abilities::INSTABUILD))
                item.sub(1);
        }

        // FUN_0x713940
        void vFunc0x268() override;

        // FUN_0x6004A4
        // +0x274
        bool isWorldBuilder() override
        {
            return mAbilities.getBool(Abilities::WORLDBUILDER);
        }

        // FUN_0x725EF0
        // +0x278
        bool isCreative() override
        {
            return mPlayerGameMode == 1 || mPlayerGameMode == 4;
        }

        // FUN_0x7260A0
        // +0x27C
        bool isAdventure() override
        {
            return mPlayerGameMode == 2;
        }

        // FUN_0x3F948C
        void vFunc0x280() override;

        // FUN_0x605D20
        // +0x29C
        void damage(const DamageSource &source, int value, int p3, int p4) override;

        // FUN_0x606E80
        // +0x2A4
        void vFunc0x2A4() override;

        // FUN_0x604360
        // +0x2A8
        void vFunc0x2A8() override;

        // FUN_0x603754
        // +0x2AC
        void vFunc0x2AC() override;

        // FUN_0x605648
        void vFunc0x2E0() override;

        // FUN_0x725F48
        u8 vFunc0x2F0() override
        {
            return m0x1959;
        }

        // FUN_0x727B2C
        void vFunc0x310() override;

        // FUN_0x607374
        void vFunc0x314(float p1) override
        {
            m0x1088 = p1;
        }

        // FUN_0x5FF804
        void vFunc0x330() override;

        // FUN_0x606608
        void vFunc0x338() override;

        // FUN_0x602900
        void vFunc0x344() override;

        // FUN_0x3F9044
        // +0x368
        ItemInstance &getMainhandItem() override;

        // FUN_0x3F90CC
        // +0x36C
        void setMainhandItem(const ItemInstance &set) override;

        // FUN_0x602038
        int vFunc0x370() override;

        // FUN_0x6054DC
        float vFunc0x374() override;

        // FUN_0x60555C
        float vFunc0x378() override;

        // FUN_0x725D68
        void vFunc0x3F4() override;

        // FUN_0x7269C0
        void vFunc0x3F8() override;

        // FUN_0x726210
        void vFunc0x400() override;

        // FUN_0x601570
        ItemInstance &vFunc0x424() override;

        // FUN_0x5FF8E8
        bool consumeTotem() override;

        // FUN_0x727994
        bool vFunc0x438() override;

        // FUN_0x6004B8
        void vFunc0x440() override;

        // FUN_0x4E791C
        void vFunc0x444() override;

        // FUN_0x727644
        int vFunc0x454() override;

        // FUN_005FFEFC
        void vFunc0x458() override;

        // FUN_0x727B98
        int vFunc0x464() override
        {
            return 0;
        }

        // FUN_0x600044
        // +0x47C
        virtual void prepareRegion(ChunkSource &cs);

        // FUN_0x5FFDE0
        virtual void vFunc0x480();

        // FUN_0x600488
        virtual void vFunc0x484();

        // FUN_0x6052AC
        virtual void vFunc0x488();

        // FUN_0x603714
        virtual void vFunc0x48C();

        // FUN_0x605558
        virtual void vFunc0x490()
        {
            return;
        }

        // FUN_0x607444
        virtual void vFunc0x494();

        // FUN_0x606FDC
        virtual void vFunc0x498();

        // FUN_0x606C74
        virtual void vFunc0x49C();

        // FUN_0x602034
        virtual void vFunc0x4A0()
        {
            return;
        }

        // FUN_0x0
        virtual void vFunc0x4A4() = 0;

        // FUN_0x6069B4
        virtual void vFunc0x4A8();

        // FUN_0x0
        virtual void vFunc0x4AC() = 0;

        // FUN_0x607088
        virtual void vFunc0x4B0();

        // FUN_0x0
        virtual void vFunc0x4B4() = 0;

        // FUN_0x3F8FC0
        virtual void vFunc0x4B8();

        // FUN_0x6016D0
        virtual void vFunc0x4BC();

        // FUN_0x665F38
        virtual void setPermissionsLevel(u8 set);

        // FUN_0x600340
        virtual void vFunc0x4C4()
        {
            return;
        }

        // FUN_0x601D1C
        virtual void vFunc0x4C8()
        {
            return;
        }

        // FUN_0x600D7C
        virtual void vFunc0x4CC()
        {
            m0x1968 = 1;
        }

        // FUN_0x600808
        virtual void vFunc0x4D0()
        {
            m0x1968 = 0;
        }

        // FUN_0x600034
        virtual void vFunc0x4D4()
        {
            return;
        }

        // FUN_0x600030
        virtual void vFunc0x4D8()
        {
            return;
        }

        // FUN_0x5FF7B8
        virtual void vFunc0x4DC()
        {
            return;
        }

        // FUN_0x60003C
        virtual void vFunc0x4E0()
        {
            return;
        }

        // FUN_0x607440
        virtual void vFunc0x4E4()
        {
            return;
        }

        // FUN_0x601684
        virtual void vFunc0x4E8()
        {
            return;
        }

        // FUN_0x5FF360
        virtual void vFunc0x4EC()
        {
            return;
        }

        // FUN_0x5FF35C
        virtual void vFunc0x4F0()
        {
            return;
        }

        // FUN_0x600038
        virtual void vFunc0x4F4()
        {
            return;
        }

        // FUN_0x5FF358
        virtual void vFunc0x4F8()
        {
            return;
        }

        // FUN_0x0
        virtual void vFunc0x4FC() = 0;

        // FUN_0x601688
        virtual void vFunc0x500()
        {
            return;
        }

        // FUN_0x60542C
        virtual void vFunc0x504()
        {
            return;
        }

        // FUN_0x60204C
        virtual void vFunc0x508()
        {
            return;
        }

        // FUN_0x5FF7BC
        virtual void vFunc0x50C()
        {
            return;
        }

        // FUN_0x604134
        virtual void vFunc0x510();

        // FUN_0x0
        virtual void vFunc0x514() = 0;

        // FUN_0x603F90
        virtual void vFunc0x518()
        {
            return;
        }

        // FUN_0x600040
        virtual void vFunc0x51C()
        {
            return;
        }

        // FUN_0x602828
        virtual void vFunc0x520()
        {
            return;
        }

        // FUN_0x0
        virtual void vFunc0x524() = 0;

        // FUN_0x0
        virtual void vFunc0x528() = 0;

        // FUN_0x605434
        virtual void vFunc0x52C()
        {
            return;
        }

        // FUN_0x0
        virtual void vFunc0x530() = 0;

        // FUN_0x600D8C
        virtual void vFunc0x534();

        // FUN_0x600818
        virtual void vFunc0x538();

        // FUN_0x601FA8
        virtual void vFunc0x53C();

        // FUN_0x7261FC
        virtual void vFunc0x540();

        // FUN_0x607080
        virtual void vFunc0x544()
        {
            return;
        }

        // FUN_0x726208
        virtual int vFunc0x548()
        {
            return 0;
        }

        // FUN_0x0
        virtual void vFunc0x54C() = 0;

        // FUN_0x60282C
        virtual void vFunc0x550();

        // FUN_0x603FB0
        virtual void vFunc0x554();

        // FUN_0x601900
        virtual void setPlayerGameType(u8 type);

        // FUN_0x605C8C
        virtual void vFunc0x55C();

        // FUN_0x725F8C
        virtual int vFunc0x560()
        {
            return 0;
        }

        // FUN_0x726D6C
        virtual void sendEventPacket();

        // FUN_0x5FFB80
        virtual void vFunc0x568();

        // FUN_0x6073AC
        virtual void vFunc0x56C();

        // FUN_0x0
        virtual void vFunc0x570() = 0;

        // FUN_0x0
        virtual void vFunc0x574() = 0;

        // FUN_0x0
        virtual void vFunc0x578() = 0;

        // FUN_0x604170
        virtual void vFunc0x57C();

        // FUN_0x605168
        virtual void vFunc0x580();

        // FUN_0x602044
        virtual int vFunc0x584()
        {
            return 0;
        }

        // FUN_0x601668
        virtual int vFunc0x588()
        {
            return 0;
        }

        // FUN_0x0
        virtual void vFunc0x58C() = 0;

        // FUN_0x5FFB18
        virtual void vFunc0x590()
        {
            return;
        }

        // FUN_0x6002DC
        virtual void vFunc0x594();

        // FUN_0x727698
        virtual void vFunc0x598();

        // FUN_0x7273FC
        virtual void vFunc0x59C();

        // FUN_0x60251C
        virtual void vFunc0x5A0()
        {
            return;
        }

        // FUN_0x6053A4
        virtual void vFunc0x5A4();

    protected:
        // 0x9CBF88

        u8                                     m0x1148;
        u8                                     m0x1149;
        u8                                     m0x114A;
        int                                    mScore;    // +0x114C
        float                                  m0x1150;
        float                                  m0x1154;
        u8                                     m0x1158;
        gstd::string                           m0x115C;
        Abilities                              mAbilities;    // +0x1160
        int                                    m0x1180;
        int                                    m0x1184;
        int                                    m0x1188;
        int                                    m0x118C;
        int                                    m0x1190;
        int                                    m0x1194;
        int                                    m0x1198;
        int                                    m0x119C;
        gstd::string                           m0x11A0;
        int                                    m0x11A4;
        int                                    m0x11A8;
        int                                    m0x11AC;
        int                                    m0x11B0;
        int                                    m0x11B4;
        int                                    m0x11B8;
        int                                    m0x11BC;
        int                                    m0x11C0;
        int                                    m0x11C4;
        int                                    m0x11C8;
        int                                    m0x11CC;
        int                                    m0x11D0;
        int                                    m0x11D4;
        int                                    m0x11D8;
        int                                    m0x11DC;
        int                                    m0x11E0;
        int                                    m0x11E4;
        void                                  *m0x11E8;
        int                                    m0x11EC;
        BlockPos                               mBedPosition;    // +0x11F0
        float                                  m0x11FC;
        float                                  m0x1200;
        float                                  m0x1204;
        Vec3<float>                            m0x1208;
        int                                    m0x1214;
        int                                    m0x1218;
        int                                    m0x121C;
        int                                    m0x1220;
        int                                    m0x1224;
        float                                  m0x1228;
        float                                  m0x122C;
        float                                  m0x1230;
        float                                  m0x1234;
        float                                  m0x1238;
        float                                  m0x123C;
        float                                  m0x1240;
        float                                  m0x1244;
        float                                  m0x1248;
        float                                  m0x124C;
        float                                  m0x1250;
        float                                  m0x1254;
        float                                  m0x1258;
        BoxedPtr::Shared<gstd::type_unknown<>> m0x125C;
        gstd::unique_ptr<PlayerInventoryProxy> mPlayerInventoryProxy;    // +0x1264
        ItemInstance                           mMaps[32];    // +0x1268
        SkinRenderer_UnknownClass              m0x1868;
        u8                                     m0x18A8;
        u8                                     m0x18A9;
        u8                                     m0x18AA;
        int                                    m0x18AC;
        u8                                     m0x18B0;
        u8                                     m0x18B1;
        ItemInstance                           m0x18B4;
        int                                    m0x18E4;
        u16                                    mSleepTimer;    // +0x18E8
        LoopbackPacketSender                  *mLoopbackPacketSender;    // +0x18EC
        int                                    m0x18F0;
        int                                    m0x18F4;
        int                                    m0x18F8;
        u8                                     m0x18FC;
        u8                                     m0x18FD;
        float                                  m0x1900;
        int                                    m0x1904;
        BoxedPtr::Shared<gstd::type_unknown<>> m0x1908;
        gstd::unique_ptr<FillingContainer>     m0x1910;
        int                                    m0x1914;
        int                                    m0x1918;
        int                                    m0x191C;
        int                                    m0x1920;
        int                                    m0x1924;
        u8                                     m0x1928;
        u8                                     m0x1929;
        u8                                     m0x192A;
        int                                    m0x192C;
        int                                    m0x1930;
        gstd::vector<gstd::type_unknown<>>     m0x1934;
        int                                    m0x1940;
        int                                    m0x1944;
        int                                    m0x1948;
        BlockPos                               mSpawnPosition;    // +0x194C
        u8                                     mSpawnForced;    // +0x1958
        u8                                     m0x1959;
        u8                                     m0x195A;
        float                                  m0x195C;
        float                                  m0x1960;
        float                                  m0x1964;
        u8                                     m0x1968;
        u8                                     mPlayerGameMode;    // +0x196C
        int                                    mEnchantmentSeed;    // +0x1970
        u8                                     mChunkRadius;    // +0x1974
        int                                    mMapIndex;    // +0x1978
        int                                    m0x197C;
        int                                    m0x1980;
        int                                    m0x1984;
        gstd::vector<gstd::type_unknown<>>     m0x1988;
        int                                    m0x1994;
        int                                    m0x1998;
        int                                    m0x199C;
    };
}    // namespace MC3DSPluginFramework