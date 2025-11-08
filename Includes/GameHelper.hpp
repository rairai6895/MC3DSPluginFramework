#ifndef GAME_HPP
#define GAME_HPP

#include "EntityClass.hpp"
#include "GameEnums.hpp"
#include "GameStructs.hpp"
#include "ItemSlot.hpp"
#include "Structs.hpp"
#include "gstd.hpp"
#include <cstring>

namespace MC3DSPluginFramework {
namespace GameHelper {

bool Eat(int speed);
bool UseBow(bool fullCharge);
void ShotArrow(u32 charge);
bool IsMultiPlayer(void);
void Equip(Entity *entity, ItemSlot &item);
bool IsWearableItem(const ItemSlot &item);
bool IsEquiped(Entity *entity, const ItemSlot &item);
gstd::vector<Entity *> *GetEntityList(void);
bool ChangeCoordsText(const gstd::string &str);
gstd::string GetEntityName(EntityID id);
size_t GetChorusFruitCooldown(void);
bool SetChorusFruitCooldown(size_t cooldown);
size_t GetEnderpearlCooldown(void);
bool SetEnderpearlCooldown(size_t cooldown);

};    // namespace GameHelper
}    // namespace MC3DSPluginFramework

#endif