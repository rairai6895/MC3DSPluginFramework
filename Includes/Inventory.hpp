#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include "GameStructs.hpp"
#include "ItemSlot.hpp"

namespace MC3DSPluginFramework {
namespace Inventory {

ItemSlot *Get(size_t index);
ItemSlot *NextEmptySlot(void);
std::vector<ItemSlot *> EmptySlots(void);
ItemSlot *Search(Item *itemInstance, u16 dataValue = 0, bool useDataValue = false);
std::vector<ItemSlot *> Search_Vec(Item *itemInstance, u16 dataValue = 0, bool useDataValue = false);
size_t Count(Item *itemInstance, u16 dataValue = 0, bool useDataValue = false);
bool IsFull(void);
bool IsEmpty(void);
size_t HeldSlot(void);
void ChangeHeldSlot(size_t index);

};    // namespace Inventory
}    // namespace MC3DSPluginFramework

#endif