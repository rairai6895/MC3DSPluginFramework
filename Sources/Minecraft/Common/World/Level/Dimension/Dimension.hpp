#pragma once

#include "Minecraft/Common/NBT/CompoundTag.hpp"
#include "Minecraft/Common/Network/Packet/Packet.hpp"
#include "Minecraft/Common/World/Level/Level.hpp"
#include "Minecraft/Helper/GameEnums.hpp"

namespace MC3DSPluginFramework
{
    namespace DimensionId
    {
        enum {
            Overworld,
            Nether,
            TheEnd,
        };
    }    // namespace DimensionId

    class Level;

    class Dimension_UnknownClass
    {
    public:
        virtual ~Dimension_UnknownClass();

        virtual void restore(CompoundTag *data);
        virtual void Unknown1(void);

    private:
        // 9D6CE0
    };

    class Dimension
    {
    public:
        Dimension(Level *level, u32 unknown1, u32 unknown2)
        {
            reinterpret_cast<Dimension *(*)(Dimension *, Level *, u32, u32)>(0x66E550)(this, level, unknown1, unknown2);
        }

        Level *getLevel()
        {
            return mLevel;
        }

        void sendPacketForEntity(Entity *e, const SendEntityMotionPacket &packet, u32 unknown1)
        {
            // パケットの型は親クラスのかもしれない
            reinterpret_cast<void (*)(Dimension *, Entity *, const SendEntityMotionPacket &, u32)>(0x60D090)(this, e, packet, unknown1);
        }

    public:
        virtual ~Dimension() = 0;
        virtual void       Unknown1(void);
        virtual void       Unknown2(void);
        virtual void       Unknown3(void);
        virtual void       Unknown4(u32 unknown1, u32 unknown2, u32 unknown3, u32 unknown4, u32 unknown5, u32 unknown6);
        virtual void       Unknown5(void);    // this
        virtual void       Unknown6(void);
        virtual void       Unknown7(void);
        virtual void       Unknown8(u32 unknown1, u32 unknown2, u32 unknown3, u32 unknown4);
        virtual void       Unknown9(u32 unknown1, u32 unknown2, u32 unknown3, u32 unknown4, u32 unknown5, u32 unknown6, u32 unknown7, u32 unknown8);
        virtual void       Unknown10(void) = 0;
        virtual void       Unknown11(void) = 0;
        virtual void       Unknown12(void);
        virtual void       Unknown13(void) = 0;
        virtual void       Unknown14(void);
        virtual void       Unknown15(void);
        virtual void       Unknown16(u32 unknown1, u32 unknown2, u32 unknown3);
        virtual void       Unknown17(void);
        virtual void       Unknown18(void);
        virtual void       Unknown19(void);
        virtual void       Unknown20(void);
        virtual void       Unknown21(void);
        virtual void       Unknown22(void);
        virtual void       Unknown23(void);
        virtual void       Unknown24(void);
        virtual void       Unknown25(void) = 0;
        virtual void       Unknown26(void);    // 0x9B0810
        virtual void       Unknown27(void);    // this
        virtual void       Unknown28(u32 unknown1, u32 unknown2, u32 unknown3, u32 unknown4);
        virtual void       Unknown29(void);    // TickCounter?
        virtual void       Unknown30(void);    // this
        virtual int        Unknown31(void);
        virtual void       Unknown32(void) = 0;
        virtual Vec3_Float Unknown33(void);
        virtual float      Unknown34(void);
        virtual void       Unknown35(void) = 0;
        virtual void       Unknown36(void) = 0;
        virtual int        Unknown37(void);
        virtual int        Unknown38(void);
        virtual void       Unknown39(void) = 0;
        virtual void       Unknown40(u32 unknown1);
        virtual int        Unknown41(void);
        virtual void       Unknown42(void) = 0;
        virtual float      Unknown43(void);
        virtual void       Unknown44(void) = 0;
        virtual int        Unknown45(void);
        virtual bool       Unknown46(void);    // this
        virtual int        convertXZToInt(const Vec3_Float &pos, bool isOverWorld);    // Z座標しか返ってこない(シグネチャが違うかもだけど分からん)
        virtual void       loadLimboEntities(CompoundTag *limboEntities);
        virtual void       saveLimboEntities(CompoundTag *out);
        virtual void       sendBroadcast(u32 unknown1, u32 unknown2);
        virtual void       Unknown51(u32 unknown1, u32 unknown2);

    private:
        // 0x9A5A8C
        // 0x9D6CE0

        // 0x9D38A4

        int          mId;
        gstd::string mName;
        Level       *mLevel;
        u32          mUnk1;
        u32          mUnk2;    // Level**?
        u32          mUnk3;    // 3
        void (*mUnk4)();
        void (*mUnk5)();
        gstd::map<u32, u32> mUnk6;
        u32                 mUnk7;
        u32                 mUnk8;
        u32                 mUnk9;
        u32                 mUnk10;
        float               mUnk11;
        float               mUnk12;
        float               mUnk13;
        u32                 mUnk14;    // float?
        u32                 mUnk15;    // float?
        u32                 mUnk16;    // float?
        float               mUnk17;
        u32                 mUnk18;    // float?
        u32                 mUnk19;    // float?
        float               mUnk20;
        u32                 mUnk21;    // float?
        u32                 mUnk22;    // float?
        u32                 mUnk23;    // bools?
        u32                 mUnk24;
        float               mUnk25;
        float               mUnk26;
        float               mUnk27;
        float               mUnk28;
        float               mUnk29;
        float               mUnk30;
        float               mUnk31;
        float               mUnk32;
        float               mUnk33;
        float               mUnk34;
        float               mUnk35;
        float               mUnk36;
        float               mUnk37;
        float               mUnk38;
        float               mUnk39;
        float               mUnk40;
        float               mUnk41;
        void               *mUnk42;
        void               *mUnk43;    // Weather?
        void               *mUnk44;
        void               *mUnk45;
        u32                 mUnk46;    // 2
        u32                 mUnk47;    // 2
        gstd::map<u32, u32> mUnk48;
        gstd::map<u32, u32> mUnk49;
        gstd::map<u32, u32> mUnk50;
        u32                 mUnk51;
        u32                 mUnk52;
    };

    class OverWorld
    {
    public:
        OverWorld(Level *level)
        {
            reinterpret_cast<void (*)(OverWorld *, Level *)>(0x2D4308)(this, level);
        }

    private:
        // 0x9B07A0
        // 0x9B087C
    };

    class Nether
    {
    };

    class TheEnd
    {
    };

}    // namespace MC3DSPluginFramework