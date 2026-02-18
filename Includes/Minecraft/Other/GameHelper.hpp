#pragma once

#include "Minecraft/Common/World/Entity/EntityClass.hpp"
#include "Minecraft/Common/World/Item/ItemInstance.hpp"
#include "Minecraft/Helper/GameEnums.hpp"
#include "Minecraft/Helper/GameStructs.hpp"
#include "Minecraft/Helper/Structs.hpp"
#include "Minecraft/gstd/gstd.hpp"
#include <cstring>

namespace MC3DSPluginFramework
{
    namespace GameHelper
    {

        void ShotArrow(u32 charge);
        bool IsMultiPlayer(void);
        void Equip(Entity *entity, ItemInstance &item);
        bool IsWearableItem(const ItemInstance &item);
        bool IsEquiped(Entity *entity, const ItemInstance &item);
        gstd::vector<Entity *> *GetEntityList(void);
        bool ChangeCoordsText(const gstd::string &str);
        gstd::string GetEntityName(EntityId id);
        size_t GetChorusFruitCooldown(void);
        bool SetChorusFruitCooldown(size_t cooldown);
        size_t GetEnderpearlCooldown(void);
        bool SetEnderpearlCooldown(size_t cooldown);

        inline size_t GetEnchantingTableCount(void)
        {
            // 0x736A98
            // "systemMessage.tooManyEnchantingTables"
            return reinterpret_cast<size_t (*)()>(0x40EA00)();
        }

    };    // namespace GameHelper
}    // namespace MC3DSPluginFramework