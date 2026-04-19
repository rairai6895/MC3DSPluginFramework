#include "Spawn.hpp"
#include "Facade.hpp"
#include "Minecraft/Common/World/Level/Level.hpp"

namespace MC3DSPluginFramework::Spawn
{

    Entity *Item(const Vec3<float> &pos, const ItemInstance &item)
    {
        if (Entity *player = Facade::getLocalPlayer())
            return reinterpret_cast<Entity *(*)(u32, BlockSource &, const ItemInstance &, Entity *, const Vec3<float> &, u32)>(0x645218)(*(u32 *)player->getLevel().offset(0x1D0), player->getRegion(), item, player, pos, 0);

        return nullptr;
    }

    Entity *Mob(const Vec3<float> &pos, const EntityId id)
    {
        if (Entity *player = Facade::getLocalPlayer())
        {
            u32 data1    = reinterpret_cast<u32 (*)(EntityId, u32)>(0x14C484)(id, 0);
            u32 data2[3] = {};
            u32 unk      = 0;
            reinterpret_cast<void (*)(u32 *, u32, u32 *, u32 *)>(0x48B3A4)(data2, 0x98A38C, &data1, &unk);
            return reinterpret_cast<Entity *(*)(u32, BlockSource &, u32 *, u32, const Vec3<float> &)>(0x6450A0)(*(u32 *)player->getLevel().offset(0x1D0), player->getRegion(), data2, 0, pos);
        }
        return nullptr;
    }

    Entity *Xp(const Vec3<float> &pos, u32 amount)
    {
        if (Entity *player = Facade::getLocalPlayer())
        {
            u32 data1[2];
            reinterpret_cast<void (*)(u32 *, EntityId)>(0x48AF00)(data1, EntityId::XPOrb);
            gstd::unique_ptr<Entity> e = reinterpret_cast<gstd::unique_ptr<Entity> (*)(u32 *, u32, const Vec3<float> &, u32, u32)>(0x213254)(data1, 0, pos, 0xA35268, 0);
            if (e)
            {
                reinterpret_cast<void (*)(Entity *, u32)>(0x214A18)(e.get(), amount);
                return player->getLevel().addEntity(player->getRegion(), std::move(e));
            }
        }
        return nullptr;
    }

    Entity *Thunder(const Vec3<float> &pos)
    {
        if (Entity *player = Facade::getLocalPlayer())
        {
            u32 data1[2];
            reinterpret_cast<void (*)(u32 *, EntityId)>(0x48AF00)(data1, EntityId::Thunder);
            gstd::unique_ptr<Entity> e = reinterpret_cast<gstd::unique_ptr<Entity> (*)(u32 *, u32, const Vec3<float> &, u32, u32)>(0x213254)(data1, 0, pos, 0xA35268, 0);

            if (e)
                return player->getLevel().addGlobalEntity(player->getRegion(), std::move(e));
        }
        return nullptr;
    }

    void Egg(const Vec3<float> &pos, const ItemInstance &egg)
    {
        if (Entity *player = Facade::getLocalPlayer())
            reinterpret_cast<void (*)(BlockSource &, u32, const Vec3<float> &, u32, const ItemInstance &)>(0x36BB18)(player->getRegion(), 0, pos, 0, egg);
    }

}    // namespace MC3DSPluginFramework::Spawn