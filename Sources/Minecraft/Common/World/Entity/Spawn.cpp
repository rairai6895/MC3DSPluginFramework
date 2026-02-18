#include "Minecraft/Common/World/Entity/Spawn.hpp"

namespace MC3DSPluginFramework
{
    namespace Spawn
    {

        Entity *Item(const Vec3_Float &pos, const ItemInstance &item)
        {
            if (Entity *player = Player::GetInstance())
                return reinterpret_cast<Entity *(*)(u32, BlockSource *, const ItemInstance &, Entity *, const Vec3_Float &, u32)>(0x645218)(*(u32 *)player->GetLevel()->offset(0x1D0), player->GetBlockSource(), item, player, pos, 0);

            return nullptr;
        }

        Entity *Mob(const Vec3_Float &pos, const EntityId id)
        {
            if (Entity *player = Player::GetInstance()) {
                u32 data1    = reinterpret_cast<u32 (*)(EntityId, u32)>(0x14C484)(id, 0);
                u32 data2[3] = {};
                u32 unk      = 0;
                reinterpret_cast<void (*)(u32 *, u32, u32 *, u32 *)>(0x48B3A4)(data2, 0x98A38C, &data1, &unk);
                return reinterpret_cast<Entity *(*)(u32, BlockSource *, u32 *, u32, const Vec3_Float &)>(0x6450A0)(*(u32 *)player->GetLevel()->offset(0x1D0), player->GetBlockSource(), data2, 0, pos);
            }
            return nullptr;
        }

        Entity *Xp(const Vec3_Float &pos, u32 amount)
        {
            if (Entity *player = Player::GetInstance()) {
                u32 data1[2];
                reinterpret_cast<void (*)(u32 *, EntityId)>(0x48AF00)(data1, EntityId::XPOrb);
                gstd::unique_ptr<Entity> e = reinterpret_cast<gstd::unique_ptr<Entity> (*)(u32 *, u32, const Vec3_Float &, u32, u32)>(0x213254)(data1, 0, pos, 0xA35268, 0);
                if (e) {
                    reinterpret_cast<void (*)(Entity *, u32)>(0x214A18)(e.get(), amount);
                    return player->GetLevel()->addEntity(player->GetBlockSource(), std::move(e));
                }
            }
            return nullptr;
        }

        Entity *Thunder(const Vec3_Float &pos)
        {
            if (Entity *player = Player::GetInstance()) {
                u32 data1[2];
                reinterpret_cast<void (*)(u32 *, EntityId)>(0x48AF00)(data1, EntityId::Thunder);
                gstd::unique_ptr<Entity> e = reinterpret_cast<gstd::unique_ptr<Entity> (*)(u32 *, u32, const Vec3_Float &, u32, u32)>(0x213254)(data1, 0, pos, 0xA35268, 0);

                if (e)
                    return player->GetLevel()->addGlobalEntity(player->GetBlockSource(), std::move(e));
            }
            return nullptr;
        }

        void Egg(const Vec3_Float &pos, const ItemInstance &egg)
        {
            if (Entity *player = Player::GetInstance())
                reinterpret_cast<void (*)(BlockSource *, u32, const Vec3_Float &, u32, const ItemInstance &)>(0x36BB18)(player->GetBlockSource(), 0, pos, 0, egg);
        }

    }    // namespace Spawn
}    // namespace MC3DSPluginFramework