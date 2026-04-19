#include "Minecraft/Common/World/Level/Level.hpp"
#include <map>

namespace MC3DSPluginFramework
{

    WeatherState *Level::weather() const
    {
        // TODO: Dimensionの解析をしたらちゃんとした処理に変更する
        return (WeatherState *)*(u32 *)(*(u32 *)(*(u32 *)(*(u32 *)(offset(0x1F0)) + 0x8) + 0x14) + 0xD0);
    }

    u32 WeatherState::get() const
    {
        u32 res = 0;

        if (rain)
            res |= Weathers::Rain;

        if (thunder)
            res |= Weathers::Thunder;

        if (!rain && !thunder)
            res = Weathers::Clear;

        return res;
    }

    void WeatherState::set(u32 weather)
    {
        if (weather & Weathers::Clear)
        {
            rain    = 0;
            thunder = 0;
        }

        if (weather & Weathers::Rain)
            rain = 1;

        if (weather & Weathers::Thunder)
            thunder = 1;
    }

    // FUN_0x5C85D8
    void *Level::getLevelStorage()
    {
        if (!(mLevelStorage != nullptr))
            LOG("Trying to access null levelStorage, use hasLevelStorage check.", mLevelStorage != nullptr, 0);

        return mLevelStorage.get();
    }

    // FUN_0x67CB58
    GameRules &Level::getGameRules()
    {
        return mGameRules;
    }

    int &Level::seed()
    {
        return mSeed;
    }

    BlockPos &Level::spawnCoords()
    {
        return mSpawnPos;
    }

    // FUN_0x73F3B8
    int Level::getTime()
    {
        return mTime;
    }

    // FUN_0x5CE60C
    void Level::setTime(int set)
    {
        mTime = set % 192000;
    }

    // FUN_0x73F30C
    int Level::getDifficulty() const
    {
        return mDifficulty;
    }

    HitResult &Level::getHitResult()
    {
        return mHitResult;
    }

    // FUN_0x720854
    Dimension *Level::getDimension(int id) const
    {
        auto it = mDimensions.find(id);
        return (it != mDimensions.end()) ? it->second : nullptr;
    }

    Dimension *Level::createDimension(int id)
    {
        return reinterpret_cast<Dimension *(*)(Level *, int)>(0x5C84A0)(this, id);
    }

    Entity *Level::fetchEntity(int unused, u64 ID, int p3) const
    {
        return reinterpret_cast<Entity *(*)(const Level *, int, u64, int)>(0x720768)(this, unused, ID, p3);
    }

    void Level::onReleaseChunk(LevelChunk &lc)
    {
        reinterpret_cast<void (*)(Level *, LevelChunk &)>(0x5C8DCC)(this, lc);
    }

    void Level::addTerrainParticle(const BlockPos &pos, BlockData block, const Vec3<float> &velocity, int unknown)
    {
        reinterpret_cast<void (*)(Level *, const BlockPos &, BlockData, const Vec3<float> &, int)>(0x5C7BA4)(this, pos, block, velocity, unknown);
    }

    // FUN_0x5C55F4
    void *Level::addParticle(int id, const Vec3<float> &pos, const Vec3<float> &velocity, int data)
    {
        if (id == 12)
            LOG("should call addTerrainParticle instead", id != ParticleType_Terrain, 0);

        for (auto listener : mListeners)
            if (void *p = listener->addParticle(id, pos, velocity, data))
                return p;

        return nullptr;
    }

    // FUN_0x5CF324
    void Level::playSound(int id, const Vec3<float> &pos, int p3, int p4, int p5, int p6)
    {
        for (auto listener : mListeners)
            listener->playSound(id, pos, p3, p4, p5, p6);
    }

    void Level::queueEntityRemoval(gstd::unique_ptr<Entity> &&e, u32 unknown)
    {
        reinterpret_cast<void (*)(Level *, gstd::unique_ptr<Entity> &&, u32)>(0x5C9744)(this, std::move(e), unknown);
    }

    Entity *Level::addEntity(BlockSource &region, gstd::unique_ptr<Entity> &&e)
    {
        return reinterpret_cast<Entity *(*)(Level *, BlockSource &, gstd::unique_ptr<Entity> &&)>(0x5CE734)(this, region, std::move(e));
    }

    Entity *Level::addGlobalEntity(BlockSource &region, gstd::unique_ptr<Entity> &&e)
    {
        return reinterpret_cast<Entity *(*)(Level *, BlockSource &, gstd::unique_ptr<Entity> &&)>(0x5C8358)(this, region, std::move(e));
    }

    EntityUniqueID Level::getNewUniqueID()
    {
        return reinterpret_cast<EntityUniqueID (*)(Level *)>(0x5C7F00)(this);
    }

    EntityUniqueID Level::getNextRuntimeID()
    {
        return reinterpret_cast<EntityUniqueID (*)(Level *)>(0x5C8AFC)(this);
    }

    Random &Level::getRandom()
    {
        return mRandom;
    }

    // FUN_0x720908
    bool Level::isClientSide()
    {
        return mIsClientSide;
    }

    // FUN_0x5C581C
    gstd::unique_ptr<Villages> &Level::getVillages()
    {
        return mVillages;
    }

    // FUN_0x67CC00
    Level::AdventureSettings &Level::getAdventureSettings()
    {
        return mAdventureSettings;
    }

}    // namespace MC3DSPluginFramework