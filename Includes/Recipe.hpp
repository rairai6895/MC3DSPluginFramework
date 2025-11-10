#ifndef CRAFT_HPP
#define CRAFT_HPP

#include "GameStructs.hpp"
#include "HookEx.hpp"
#include "ItemSlot.hpp"
#include "gstd.hpp"
#include "mutex"

namespace MC3DSPluginFramework {
namespace Recipe {

enum Category : u16 {
    Structures     = 1,
    Tools          = 2,
    Food           = 3,
    Mechanisms     = 4,
    Transportation = 5,
    Decorations    = 6,
};

struct RecipeData {
    u32 vtable        = 0x9A2664;
    Category category = Category::Structures;
    u16 num           = 0;
    u32 unk1[12]      = {};
    u32 size_x        = 0;
    u32 size_y        = 0;
    gstd::vector<ItemSlot> need;
    gstd::vector<ItemSlot> res;

    RecipeData(Category category, u16 num, u32 size_x, u32 size_y, gstd::vector<ItemSlot> &&need, gstd::vector<ItemSlot> &&res) :
        category(category), num(num), size_x(size_x), size_y(size_y), need(std::move(need)), res(std::move(res)) {}
};

struct Item {
    ItemID itemID;
    u8 count;
    u16 dataValue;
    std::vector<EnchantStatus> enchants = {};

    Item(ItemID itemID, u8 count, u16 dataValue, const std::vector<EnchantStatus> &enchants = {}) :
        itemID(itemID), count(count), dataValue(dataValue), enchants(enchants) {}

    Item(ItemID itemID, u8 count, u16 dataValue, const std::initializer_list<EnchantStatus> &enchants) :
        itemID(itemID), count(count), dataValue(dataValue), enchants(enchants) {}
};

gstd::vector<RecipeData *> *GetList(void);
void Append(Category category, u16 num, u32 x, u32 y, const std::vector<Item> &need, const Item &res);

};    // namespace Recipe
}    // namespace MC3DSPluginFramework

#endif