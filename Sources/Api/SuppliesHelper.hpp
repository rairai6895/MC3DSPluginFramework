#pragma once

#include "Minecraft/Common/World/Entity/Player/PlayerInventoryProxy.hpp"

namespace MC3DSPluginFramework
{
    // 解析が進んで不要になったら削除予定
    class SuppliesHelper
    {
    public:
        static int getCount(PlayerInventoryProxy &supplies, Item *item, u16 dataValue, bool useDataValue)
        {
            int res = 0;

            if (useDataValue)
            {
                for (int i = 0; i < 36; ++i)
                {
                    ItemInstance &slot = supplies.getItem(i + 9, 0);

                    if (slot.mItem == item)
                        res += slot.mCount;
                }

                return res;
            }

            for (int i = 0; i < 36; ++i)
            {
                ItemInstance &slot = supplies.getItem(i + 9, 0);

                if (slot.mItem == item && slot.getAuxValue() == dataValue)
                    res += slot.mCount;
            }

            return res;
        }

        static ItemInstance *getNextEmptySlot(PlayerInventoryProxy &supplies)
        {
            for (int i = 0; i < 36; ++i)
            {
                ItemInstance &slot = supplies.getItem(i + 9, 0);

                if (slot.isNull())
                    return &slot;
            }

            return nullptr;
        }

        static ItemInstance *search(PlayerInventoryProxy &supplies, Item *item, u16 dataValue, bool useDataValue)
        {
            if (useDataValue)
            {
                for (int i = 0; i < 36; ++i)
                {
                    ItemInstance &slot = supplies.getItem(i + 9, 0);

                    if (slot.mItem == item)
                        return &slot;
                }
            }

            for (int i = 0; i < 36; ++i)
            {
                ItemInstance &slot = supplies.getItem(i + 9, 0);

                if (slot.mItem == item && slot.getAuxValue() == dataValue)
                    return &slot;
            }

            return nullptr;
        }

    private:
    };
}    // namespace MC3DSPluginFramework