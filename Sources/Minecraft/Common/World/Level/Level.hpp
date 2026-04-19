#pragma once

#include "../../Util/Random.hpp"
#include "../Entity/EntityUniqueID.hpp"
#include "../Phys/HitResult.hpp"
#include "Block/BlockData.hpp"
#include "LevelListener.hpp"
#include "Minecraft/Common/Platform/AppPlatformListener.hpp"
#include "Minecraft/Helper/GameEnums.hpp"
#include "Minecraft/Helper/Structs.hpp"
#include "Minecraft/gstd/gstd.hpp"
#include "Storage/GameRules.hpp"

namespace MC3DSPluginFramework
{
    enum Weathers : u32 {
        Clear   = 1 << 0,
        Rain    = 1 << 1,
        Thunder = 1 << 2,
    };

    class WeatherState
    {
    public:
        u32  get(void) const;
        void set(u32 weather);

    private:
        u32               vtable;
        u32               unk1;
        gstd::vector<u32> unk2;
        u32               unk3;
        float             unk4;    // sky?
        float             unk5;    // sky?
        float             rain;
        float             unk6;    // sky?
        float             unk7;    // sky?
        float             thunder;
    };

    class Entity;
    class BlockSource;
    class Player;
    class Villages;

    // 0x99E5D0

    // "C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\src\\common\\world\\level\\Level.cpp"
    class Level : public BlockSourceListener, public AppPlatformListener
    {
        USE_GAME_ALLOCATOR
    public:
        struct AdventureSettings
        {
            bool mNoPvM;    // +0x0
            bool mNoMvP;    // +0x1
            bool mImmutableWorld;    // +0x2
            bool m0x3;
            bool m0x4;
            bool m0x5;
            bool m0x6;
            bool m0x7;
        };

    public:
        u32           offset(u32 offset) const { return (u32)this + offset; }
        WeatherState *weather() const;

        // FUN_0x5D0F68
        virtual ~Level();

        void                       *getLevelStorage();
        GameRules                  &getGameRules();
        int                        &seed();
        BlockPos                   &spawnCoords();
        int                         getTime();
        void                        setTime(int set);
        int                         getDifficulty() const;
        HitResult                  &getHitResult();
        Dimension                  *getDimension(int id) const;
        Dimension                  *createDimension(int id);
        Entity                     *fetchEntity(int unused, u64 ID, int p3) const;
        void                        onReleaseChunk(LevelChunk &lc);
        void                        addTerrainParticle(const BlockPos &pos, BlockData block, const Vec3<float> &velocity, int unknown);
        void                       *addParticle(int id, const Vec3<float> &pos, const Vec3<float> &velocity, int data);
        void                        playSound(int id, const Vec3<float> &pos, int p3, int p4, int p5, int p6);
        void                        queueEntityRemoval(gstd::unique_ptr<Entity> &&e, u32 unknown);
        Entity                     *addEntity(BlockSource &region, gstd::unique_ptr<Entity> &&e);
        Entity                     *addGlobalEntity(BlockSource &region, gstd::unique_ptr<Entity> &&e);
        EntityUniqueID              getNewUniqueID();
        EntityUniqueID              getNextRuntimeID();
        Random                     &getRandom();
        bool                        isClientSide();
        gstd::unique_ptr<Villages> &getVillages();
        AdventureSettings          &getAdventureSettings();

    private:
        gstd::vector<gstd::unique_ptr<Player>> mUnk1;    // +0xC
        gstd::vector<Player *>                 mUnk2;    // +0x18
        gstd::vector<gstd::type_unknown<>>     mUnk3;    // +0x24
        gstd::vector<gstd::type_unknown<>>     mUnk4;    // +0x30
        SoundEngine                           *mSoundEngine;    // +0x3C
        int                                    mUnk6;    // +0x40
        int                                    mUnk7;    // +0x44
        int                                    mUnk8;    // +0x48
        int                                    mUnk9;    // +0x4C
        int                                    mUnk10;    // +0x50
        int                                    mUnk11;    // +0x54

        gstd::map<gstd::type_unknown<>, gstd::type_unknown<>> mUnk12;    // +0x58

        gstd::vector<LevelListener *>              mListeners;    // +0x74
        gstd::unique_ptr<gstd::type_unknown<>>     mLevelStorage;    // +0x80
        gstd::unique_ptr<gstd::type_unknown<0x24>> mUnk13;    // +0x84

        AdventureSettings mAdventureSettings;    // +0x88
        GameRules         mGameRules;    // +0x90

        // LevelData?
        gstd::string              mLevelName;    // +0xAC
        int                       mStorageVersion;    // +0xB0
        int                       mUnk17;    // +0xB4
        int                       mUnk18;    // +0xB8
        int                       mUnk19;    // +0xBC
        int                       mSeed;    // +0xC0
        BlockPos                  mSpawnPos;    // +0xC4
        int                       mUnk20;    // +0xD0
        int                       mUnk21;    // +0xD4
        BlockPos                  mUnk22;    // +0xD8
        int                       mTime;    // +0xE4
        int                       mUnk24;    // +0xE8
        CompoundTag               mUnk25;    //+0xEC
        CompoundTag               mUnk26;    //+0x10C
        gstd::type_unknown<0x64> *mUnk27;    // +0x12C
        int                       mUnk28;    // +0x130
        int                       mUnk29;    // +0x134 0になると天気が切り替わる
        int                       mUnk30;    // +0x138
        int                       mUnk31;    // +0x13C
        int                       mUnk32;    // +0x140
        int                       mUnk33;    // +0x144
        int                       mUnk34;    // +0x148
        int                       mUnk35;    // +0x14C
        int                       mGameMode;    // +0x150
        int                       mDifficulty;    // +0x154
        int                       mUnk36;    // +0x158
        int                       mUnk37;    // +0x15C
        int                       mUnk38;    // +0x160
        int                       mUnk39;    // +0x164
        int                       mUnk40;    // +0x168
        int                       mUnk41;    // +0x16C
        int                       mUnk42;    // +0x170
        int                       mUnk43;    // +0x174
        int                       mUnk44;    // +0x178
        gstd::string              mUnk45;    // +0x17C
        int                       mUnk46;    // +0x180
        int                       mUnk47;    // +0x184
        int                       mUnk48;    // +0x188

        gstd::map<gstd::type_unknown<>, gstd::type_unknown<>> mUnk49;    // +0x18C

        int          mUnk50;    // +0x1A8
        gstd::string mUnk51;    // +0x1AC

        gstd::map<gstd::type_unknown<>, gstd::type_unknown<>> mUnk52;    // +0x1B0

        void                       *mUnk53;    // +0x1CC
        void                       *mUnk54;    // +0x1D0
        void                       *mUnk55;    // +0x1D4
        void                       *mUnk56;    // +0x1D8
        void                       *mUnk57;    // +0x1DC
        gstd::map<int, Dimension *> mDimensions;    // +0x1E0　
        void                       *mUnk58;    // +0x1FC
        gstd::vector<void *>        mUnk59;    // +0x200

        gstd::map<gstd::type_unknown<>, gstd::type_unknown<>> mUnk60;    // +0x20C
        gstd::map<gstd::type_unknown<>, gstd::type_unknown<>> mUnk61;    // +0x228

        void *mUnk62;    // +0x244 mLoopbackPacketSender?

        HitResult                          mHitResult;    // +0x248
        int                                mUnk66;    // +0x26C
        int                                mUnk67;    // +0x270
        int                                mUnk68;    // +0x274
        int                                mUnk69;    // +0x278
        int                                mUnk70;    // +0x27C
        int                                mUnk71;    // +0x280
        int                                mUnk72;    // +0x284
        int                                mUnk73;    // +0x288
        int                                mUnk74;    // +0x28C
        Random                             mRandom;    // +0x290
        Random                             mRandom2;    // +0xC64
        gstd::type_unknown<0xE8>          *mUnk75;    // +0x1638
        gstd::vector<gstd::type_unknown<>> mUnk76;    // +0x163C
        int                                mUnk77;    // +0x1648
        gstd::vector<gstd::type_unknown<>> mUnk78;    // +0x164C
        gstd::vector<gstd::type_unknown<>> mUnk79;    // +0x1658
        gstd::vector<gstd::type_unknown<>> mUnk80;    // +0x1664
        gstd::unique_ptr<Villages>         mVillages;    // +0x1670
        bool                               mIsClientSide;    // +0x1674
        bool                               mIsExporting;    // +0x1675
        int                                mUnk82;    // +0x1678
        int                                mUnk83;    // +0x167C
        int                                mUnk84;    // +0x1680
        int                                mUnk85;    // +0x1684
        int                                mUnk86;    // +0x1688
        int                                mUnk87;    // +0x168C
        int                                mUnk88;    // +0x1690
        int                                mUnk89;    // +0x1694
        int                                mUnk90;    // +0x1698
        int                                mUnk91;    // +0x169C
        int                                mUnk92;    // +0x16A0
        int                                mUnk93;    // +0x16A4
        int                                mUnk94;    // +0x16A8
        int                                mUnk95;    // +0x16AC
        gstd::string                       mSaveDataFolder;    // +0x16B0
        gstd::vector<gstd::type_unknown<>> mUnk96;    // +0x16B4
        int                                mUnk97;    // +0x16C0

        gstd::map<gstd::type_unknown<>, gstd::type_unknown<>> mUnk98;    // +0x16C4
        gstd::map<gstd::type_unknown<>, gstd::type_unknown<>> mUnk99;    // +0x16E0

        u8    mUnk100;    // +0x16FC
        void *mUnk101;    // +0x1700
        void *mUnk102;    // +0x1704
        int   mUnk103;    // +0x1708
        int   mUnk104;    // +0x170C
        int   mUnk105;    // +0x1710
        u8    mUnk106;    // +0x1714
        int   mUnk107;    // +0x1718
        int   mUnk108;    // +0x171C
        int   mUnk109;    // +0x1720
        int   mUnk110;    // +0x1724
        int   mUnk111;    // +0x1728
        int   mUnk112;    // +0x172C
        int   mUnk113;    // +0x1730
        int   mUnk114;    // +0x1734
        int   mUnk115;    // +0x1738
        int   mUnk116;    // +0x173C

        // ResourceLoader型で扱ってるかも？
        void                     *mUnk117;    // +0x1740
        ResourcePackManager      *mResourcePackManager;    // +0x1744
        gstd::type_unknown<0x24> *mUnk118;    // +0x1748

        gstd::map<gstd::string, gstd::type_unknown<0x10> *> mUnk119;    // +0x174C
    };
}    // namespace MC3DSPluginFramework