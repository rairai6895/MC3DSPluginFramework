#pragma once

#include "HookEx/HookEx.hpp"
#include "Minecraft/Common/World/Item/ItemInstance.hpp"
#include "Minecraft/Helper/GameStructs.hpp"
#include "Minecraft/gstd/gstd.hpp"
#include <mutex>

namespace MC3DSPluginFramework
{
    namespace CreativeMenu
    {

        enum Category : u16 {
            Building_Blocks        = 1,
            Decorations            = 2,
            RedStone_and_Transport = 3,
            Food_and_Materials     = 4,
            Tools                  = 5,
            Brewing                = 6,
            Miscellaneous          = 7,
        };

        gstd::vector<ItemInstance> &GetItemList(void);
        void Append(Category category, u16 number, ItemId itemId, u16 dataValue);
        void Append(Category category, u16 number, ItemId itemId, u16 dataValue, const std::initializer_list<EnchantStatus> &enchants);
        void Append(Category category, u16 number, ItemId itemId, u16 dataValue, const std::vector<EnchantStatus> &enchants);

    };    // namespace CreativeMenu
}    // namespace MC3DSPluginFramework