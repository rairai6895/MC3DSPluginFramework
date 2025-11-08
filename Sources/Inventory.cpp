#include "Inventory.hpp"
#include "Dropper.hpp"
#include "Function.hpp"
#include "GameSound.hpp"
#include "PlayerClass.hpp"

namespace MC3DSPluginFramework {
namespace Inventory {

ItemSlot *Get(size_t index) {
    if (u8 i = 9 + index; i <= 44)    // 9 ~ 44
        if (Entity *player = Player::GetInstance()) {
            u32 param = Function<u32>(0x726090)(player);
            return Function<ItemSlot *>(0x703998)(param, i);
        }

    return nullptr;
}

ItemSlot *NextEmptySlot(void) {
    if (ItemSlot *inv = Get(0))
        for (size_t i = 0; i < 36; ++i)
            if (!inv[i].itemInstance)
                return &inv[i];

    return nullptr;
}

std::vector<ItemSlot *> EmptySlots(void) {
    std::vector<ItemSlot *> res{};
    if (ItemSlot *inv = Get(0))
        for (size_t i = 0; i < 36; ++i)
            if (!inv[i].itemInstance)
                res.push_back(&inv[i]);

    return res;
}

ItemSlot *Search(Item *itemInstance, u16 dataValue, bool useDataValue) {
    if (ItemSlot *inv = Get(0))
        for (size_t i = 0; i < 36; ++i) {
            ItemSlot &target = inv[i];
            if (target.itemInstance == itemInstance)
                if (useDataValue ? target.dataValue == dataValue : true)
                    return &target;
        }

    return nullptr;
}

std::vector<ItemSlot *> Search_Vec(Item *itemInstance, u16 dataValue, bool useDataValue) {
    std::vector<ItemSlot *> res{};
    if (ItemSlot *inv = Get(0))
        for (size_t i = 0; i < 36; ++i) {
            ItemSlot &target = inv[i];
            if (target.itemInstance == itemInstance)
                if (useDataValue ? target.dataValue == dataValue : true)
                    res.push_back(&target);
        }

    return res;
}

size_t Count(Item *itemInstance, u16 dataValue, bool useDataValue) {
    std::vector<ItemSlot *> find = Search_Vec(itemInstance, dataValue, useDataValue);
    size_t res                   = 0;
    for (auto slot : find)
        res += slot->count;

    return res;
}

bool IsFull(void) {
    return !NextEmptySlot();
}

bool IsEmpty(void) {
    return EmptySlots().empty();
}

size_t HeldSlot(void) {
    if (Entity *player = Player::GetInstance())
        return *(size_t *)(Function<u32>(0x726090)(player) + 0x8) - 9;
    return 0;
}

void ChangeHeldSlot(size_t index) {
    if (u8 i = 9 + index; i <= 44) {
        if (Entity *player = Player::GetInstance()) {
            *(size_t *)(Function<u32>(0x726090)(player) + 0x8) = i;
        }
    }
}

}    // namespace Inventory
}    // namespace MC3DSPluginFramework