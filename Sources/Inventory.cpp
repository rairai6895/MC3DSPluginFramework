#include "Inventory.hpp"
#include "Dropper.hpp"
#include "Function.hpp"
#include "GameSound.hpp"
#include "PlayerClass.hpp"

namespace MC3DSPluginFramework {
namespace Inventory {

SlotData *Get(size_t index) {
    if (u8 i = 9 + index; i <= 44)    // 9 ~ 44
        if (Entity *player = Player::GetInstance()) {
            u32 param = Function<u32>(0x726090)(player);
            return Function<SlotData *>(0x703998)(param, i);
        }

    return nullptr;
}

SlotData *NextEmptySlot(void) {
    if (SlotData *inv = Get(0))
        for (size_t i = 0; i < 36; ++i)
            if (!inv[i].itemdata)
                return &inv[i];

    return nullptr;
}

std::vector<SlotData *> EmptySlots(void) {
    std::vector<SlotData *> res{};
    if (SlotData *inv = Get(0))
        for (size_t i = 0; i < 36; ++i)
            if (!inv[i].itemdata)
                res.push_back(&inv[i]);

    return res;
}

SlotData *Search(ItemData *itemdata, u16 dataValue, bool useDataValue) {
    if (SlotData *inv = Get(0))
        for (size_t i = 0; i < 36; ++i) {
            SlotData &target = inv[i];
            if (target.itemdata == itemdata)
                if (useDataValue ? target.dataValue == dataValue : true)
                    return &target;
        }

    return nullptr;
}

std::vector<SlotData *> Search_Vec(ItemData *itemdata, u16 dataValue, bool useDataValue) {
    std::vector<SlotData *> res{};
    if (SlotData *inv = Get(0))
        for (size_t i = 0; i < 36; ++i) {
            SlotData &target = inv[i];
            if (target.itemdata == itemdata)
                if (useDataValue ? target.dataValue == dataValue : true)
                    res.push_back(&target);
        }

    return res;
}

size_t Count(ItemData *itemdata, u16 dataValue, bool useDataValue) {
    std::vector<SlotData *> find = Search_Vec(itemdata, dataValue, useDataValue);
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