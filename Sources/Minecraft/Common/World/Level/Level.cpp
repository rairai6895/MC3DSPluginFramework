#include "Minecraft/Common/World/Level/Level.hpp"

namespace MC3DSPluginFramework
{

    WeatherState *Level::weather(void) const
    {
        return (WeatherState *)*(u32 *)(*(u32 *)(*(u32 *)(*(u32 *)(offset(0x1F0)) + 0x8) + 0x14) + 0xD0);
    }

    u32 WeatherState::get(void) const
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
        if (weather & Weathers::Clear) {
            rain    = 0;
            thunder = 0;
        }

        if (weather & Weathers::Rain)
            rain = 1;

        if (weather & Weathers::Thunder)
            thunder = 1;
    }

    u32 &Level::seed(void) const
    {
        return *(u32 *)offset(0xC0);
    }

    Vec3_Int &Level::spawnCoords(void) const
    {
        return *(Vec3_Int *)offset(0xC4);
    }

    TargetType Level::getTargetType(void) const
    {
        return *(TargetType *)offset(0x248);
    }

    Vec3_Int &Level::targetBlockPos(void) const
    {
        return *(Vec3_Int *)offset(0x250);
    }

    GameRules &Level::getGameRules(void) const
    {
        return reinterpret_cast<GameRules &(*)(const Level *)>(0x67CB58)(this);
    }

    size_t Level::getDifficulty(void) const
    {
        return reinterpret_cast<size_t (*)(const Level *)>(0x73F30C)(this);
    }

    Util::Random &Level::getRandom(void) const
    {
        return *(Util::Random *)offset(0x290);
    }

    Entity *Level::getLookEntity(void) const
    {
        return *(Entity **)offset(0x268);
    }

    void *Level::getDimension(DimensionId id) const
    {
        return reinterpret_cast<void *(*)(const Level *, DimensionId)>(0x720854)(this, id);
    }

    void *Level::createDimension(DimensionId id)
    {
        return reinterpret_cast<void *(*)(Level *, DimensionId)>(0x5C84A0)(this, id);
    }

    Entity *Level::fetchEntity(const UniqueID &id) const
    {
        return reinterpret_cast<Entity *(*)(const Level *, u32, u32, u32, u32)>(0x720768)(this, 0, id.mUnk1, id.mUnk2, 0);
    }

    void Level::getNextRuntimeID(u64 *id) const
    {
        // 多分本来はu64じゃないオブジェクト
        reinterpret_cast<void (*)(u64 *, const Level *)>(0x5C8AFC)(id, this);
    }

}    // namespace MC3DSPluginFramework