#pragma once

#include "Minecraft/Common/World/Entity/Player/Player.hpp"
#include "Minecraft/Common/World/Item/ItemInstance.hpp"

namespace MC3DSPluginFramework
{
    namespace Spawn
    {

        Entity *Item(const Vec3_Float &pos, const ItemInstance &item);
        Entity *Mob(const Vec3_Float &pos, EntityId id);
        Entity *Xp(const Vec3_Float &pos, u32 amount);
        Entity *Thunder(const Vec3_Float &pos);
        void Egg(const Vec3_Float &pos, const ItemInstance &egg);

    };    // namespace Spawn
}    // namespace MC3DSPluginFramework