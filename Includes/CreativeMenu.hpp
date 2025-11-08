#ifndef CREATIVEMENU_HPP
#define CREATIVEMENU_HPP

#include "GameStructs.hpp"
#include "HookEx.hpp"
#include "ItemSlot.hpp"
#include "gstd.hpp"

namespace MC3DSPluginFramework {
namespace CreativeMenu {

enum Category : u16 {
    Building_Blocks        = 1,
    Decorations            = 2,
    RedStone_and_Transport = 3,
    Food_and_Materials     = 4,
    Tools                  = 5,
    Brewing                = 6,
    Miscellaneous          = 7,
};

gstd::vector<ItemSlot> &GetItemList(void);
void Append(Category category, u16 number, ItemID itemID, u16 dataValue);
void Append(Category category, u16 number, ItemID itemID, u16 dataValue, const std::initializer_list<EnchantStatus> &enchants);
void Append(Category category, u16 number, ItemID itemID, u16 dataValue, const std::vector<EnchantStatus> &enchants);

};    // namespace CreativeMenu

}    // namespace MC3DSPluginFramework

#endif