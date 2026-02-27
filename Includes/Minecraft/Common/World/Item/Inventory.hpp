#pragma once

#include "Minecraft/Common/World/Item/ItemInstance.hpp"
#include "Minecraft/Helper/GameStructs.hpp"

namespace MC3DSPluginFramework
{
    namespace Inventory
    {

        ItemInstance *Get(size_t index);
        ItemInstance *NextEmptySlot(void);
        std::vector<ItemInstance *> EmptySlots(void);
        ItemInstance *Search(Item *itemInstance, u16 dataValue = 0, bool useDataValue = false);
        std::vector<ItemInstance *> Search_Vec(Item *itemInstance, u16 dataValue = 0, bool useDataValue = false);
        size_t Count(Item *item, u16 dataValue = 0, bool useDataValue = false);
        bool IsFull(void);
        bool IsEmpty(void);
        size_t HeldSlot(void);
        void ChangeHeldSlot(size_t index);

    };    // namespace Inventory
}    // namespace MC3DSPluginFramework