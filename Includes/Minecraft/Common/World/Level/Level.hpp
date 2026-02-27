#pragma once

#include "Minecraft/Common/Util/Random.hpp"
#include "Minecraft/Common/World//Level/Storage/GameRules.hpp"
#include "Minecraft/Common/World/Entity/EntityClass.hpp"
#include "Minecraft/Helper/GameEnums.hpp"
#include "Minecraft/Helper/GameStructs.hpp"
#include "Minecraft/Helper/Structs.hpp"
#include "Minecraft/gstd/gstd.hpp"
#include <random>

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
        u32 get(void) const;
        void set(u32 weather);

    private:
        u32 vtable;
        u32 unk1;
        gstd::vector<u32> unk2;
        u32 unk3;
        float unk4;    // sky?
        float unk5;    // sky?
        float rain;
        float unk6;    // sky?
        float unk7;    // sky?
        float thunder;
    };

    class Entity;
    class BlockSource;

    // "C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\src\\common\\world\\level\\Level.cpp"
    class Level
    {
    public:
        // FUN_0x5C85D8
        void *getLevelStorage(void)
        {
            void *mLevelStorage = *(void **)offset(0x80);

            if (!(mLevelStorage != nullptr))
                LOG("Trying to access null levelStorage, use hasLevelStorage check.", mLevelStorage != nullptr, 0);

            return mLevelStorage;
        }

    public:
        // FUN_5D0F68
        ~Level();

        u32 offset(u32 offset) const { return (u32)this + offset; }

        int &getTick(void) const { return *(int *)offset(0xE4); }

        WeatherState *weather(void) const;
        u32 &seed(void) const;
        Vec3_Int &spawnCoords(void) const;
        TargetType getTargetType(void) const;
        BlockPos &targetBlockPos(void) const;
        GameRules &getGameRules(void) const;

        void addTerrainParticle(const Vec3_Int &pos, const BlockData &block, const Vec3_Float &velocity, int unknown)
        {
            reinterpret_cast<void (*)(Level *, const Vec3_Int &, const BlockData &, const Vec3_Float &, int)>(0x5C7BA4)(this, pos, block, velocity, unknown);
        }

        void *addParticle(ParticleId id, const Vec3_Float &pos, const Vec3_Float &velocity, u32 data)
        {
            return reinterpret_cast<void *(*)(Level *, ParticleId, const Vec3_Float &, const Vec3_Float &, u32)>(0x5C55F4)(this, id, pos, velocity, data);
        }

        size_t getDifficulty(void) const;
        Util::Random &getRandom(void) const;
        Entity *getLookEntity(void) const;
        void *getDimension(DimensionId id) const;
        void *createDimension(DimensionId id);
        Entity *fetchEntity(const UniqueID &id) const;
        void getNextRuntimeID(u64 *id) const;

        void queueEntityRemoval(gstd::unique_ptr<Entity> &&e, u32 unknown)
        {
            reinterpret_cast<void (*)(Level *, gstd::unique_ptr<Entity> &&, u32)>(0x5C9744)(this, std::move(e), unknown);
        }

        Entity *addEntity(BlockSource *bs, gstd::unique_ptr<Entity> &&e)
        {
            return reinterpret_cast<Entity *(*)(Level *, BlockSource *, gstd::unique_ptr<Entity> &&)>(0x5CE734)(this, bs, std::move(e));
        }

        Entity *addGlobalEntity(BlockSource *bs, gstd::unique_ptr<Entity> &&e)
        {
            return reinterpret_cast<Entity *(*)(Level *, BlockSource *, gstd::unique_ptr<Entity> &&)>(0x5C8358)(this, bs, std::move(e));
        }

        UniqueID getNewUniqueID(void)
        {
            return reinterpret_cast<UniqueID (*)(Level *)>(0x5C7F00)(this);
        }

    private:
    };
}    // namespace MC3DSPluginFramework