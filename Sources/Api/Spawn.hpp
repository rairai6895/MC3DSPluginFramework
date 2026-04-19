#pragma once

#include "Minecraft/Common/World/Entity/Player/Player.hpp"
#include "Minecraft/Common/World/Item/ItemInstance.hpp"

// 削除予定

namespace MC3DSPluginFramework::Spawn
{
    Entity *Item(const Vec3<float> &pos, const ItemInstance &item);
    Entity *Mob(const Vec3<float> &pos, EntityId id);
    Entity *Xp(const Vec3<float> &pos, u32 amount);
    Entity *Thunder(const Vec3<float> &pos);
    void    Egg(const Vec3<float> &pos, const ItemInstance &egg);
}    // namespace MC3DSPluginFramework::Spawn