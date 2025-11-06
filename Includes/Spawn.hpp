#ifndef SPAWN_HPP
#define SPAWN_HPP

#include "PlayerClass.hpp"

namespace MC3DSPluginFramework {
namespace Spawn {

Entity *Item(const Vec3_Float &pos, const SlotData &item);
Entity *Mob(const Vec3_Float &pos, const EntityID id);
Entity *Xp(const Vec3_Float &pos, u32 amount);
Entity *Thunder(const Vec3_Float &pos);
void Egg(const Vec3_Float &pos, const SlotData &egg);

};    // namespace Spawn
}    // namespace MC3DSPluginFramework

#endif