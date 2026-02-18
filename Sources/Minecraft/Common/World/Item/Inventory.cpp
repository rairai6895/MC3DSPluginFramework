#include "Minecraft/Common/World/Item/Inventory.hpp"
#include "Minecraft/Common/World/Entity/Player/Player.hpp"
#include "Minecraft/Other/Dropper.hpp"
#include "Minecraft/Other/GameSound.hpp"

namespace MC3DSPluginFramework
{
    namespace Inventory
    {

        ItemInstance *Get(size_t index)
        {
            if (u8 i = 9 + index; i <= 44)    // 9 ~ 44
                if (Entity *player = Player::GetInstance()) {
                    u32 param = reinterpret_cast<u32 (*)(const Entity *)>(0x726090)(player);
                    return reinterpret_cast<ItemInstance *(*)(u32, size_t)>(0x703998)(param, i);
                }

            return nullptr;
        }

        ItemInstance *NextEmptySlot(void)
        {
            if (ItemInstance *inv = Get(0))
                for (size_t i = 0; i < 36; ++i)
                    if (!inv[i].mItem)
                        return &inv[i];

            return nullptr;
        }

        std::vector<ItemInstance *> EmptySlots(void)
        {
            std::vector<ItemInstance *> res {};
            if (ItemInstance *inv = Get(0))
                for (size_t i = 0; i < 36; ++i)
                    if (!inv[i].mItem)
                        res.push_back(&inv[i]);

            return res;
        }

        ItemInstance *Search(Item *itemInstance, u16 dataValue, bool useDataValue)
        {
            if (ItemInstance *inv = Get(0))
                for (size_t i = 0; i < 36; ++i) {
                    ItemInstance &target = inv[i];
                    if (target.mItem == itemInstance)
                        if (useDataValue ? target.mDataValue == dataValue : true)
                            return &target;
                }

            return nullptr;
        }

        std::vector<ItemInstance *> Search_Vec(Item *itemInstance, u16 dataValue, bool useDataValue)
        {
            std::vector<ItemInstance *> res {};
            if (ItemInstance *inv = Get(0))
                for (size_t i = 0; i < 36; ++i) {
                    ItemInstance &target = inv[i];
                    if (target.mItem == itemInstance)
                        if (useDataValue ? target.mDataValue == dataValue : true)
                            res.push_back(&target);
                }

            return res;
        }

        size_t Count(Item *itemInstance, u16 dataValue, bool useDataValue)
        {
            std::vector<ItemInstance *> find = Search_Vec(itemInstance, dataValue, useDataValue);
            size_t res                       = 0;
            for (auto slot : find)
                res += slot->mCount;

            return res;
        }

        bool IsFull(void)
        {
            return !NextEmptySlot();
        }

        bool IsEmpty(void)
        {
            return EmptySlots().empty();
        }

        size_t HeldSlot(void)
        {
            if (Entity *player = Player::GetInstance())
                return *(size_t *)(reinterpret_cast<u32 (*)(Entity *)>(0x726090)(player) + 0x8) - 9;
            return 0;
        }

        void ChangeHeldSlot(size_t index)
        {
            if (u8 i = 9 + index; i <= 44) {
                if (Entity *player = Player::GetInstance()) {
                    *(size_t *)(reinterpret_cast<u32 (*)(Entity *)>(0x726090)(player) + 0x8) = i;
                }
            }
        }

    }    // namespace Inventory
}    // namespace MC3DSPluginFramework