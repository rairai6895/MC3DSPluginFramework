#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include "GameStructs.hpp"

namespace MC3DSPluginFramework {
namespace Inventory {

SlotData *Get(size_t index);
SlotData *NextEmptySlot(void);
std::vector<SlotData *> EmptySlots(void);
SlotData *Search(ItemData *itemdata, u16 dataValue = 0, bool useDataValue = false);
std::vector<SlotData *> Search_Vec(ItemData *itemdata, u16 dataValue = 0, bool useDataValue = false);
size_t Count(ItemData *itemdata, u16 dataValue = 0, bool useDataValue = false);
bool IsFull(void);
bool IsEmpty(void);
size_t HeldSlot(void);
void ChangeHeldSlot(size_t index);

};    // namespace Inventory
}    // namespace MC3DSPluginFramework

#endif