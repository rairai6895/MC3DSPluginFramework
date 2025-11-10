#ifndef ITEMSLOT_HPP
#define ITEMSLOT_HPP

#include "GameEnums.hpp"
#include "ItemClass.hpp"
#include "cstring"
#include "gstd.hpp"

namespace MC3DSPluginFramework {

struct EnchantStatus {
    Enchants id;
    u32 level;
};

struct EnchantArgs {
  private:
    u32 data1 = 0x7FFF;

  public:
    gstd::vector<EnchantStatus> enchants;

  private:
    u32 data3[7];
};

class ItemSlot {
  public:
    ItemSlot();
    ItemSlot(ItemID itemID, u8 count, u16 dataValue);
    ItemSlot(void *block, u8 count, u16 dataValue);
    ItemSlot(const ItemSlot &other);
    ItemSlot(ItemSlot &&other) noexcept;
    ~ItemSlot();

    ItemSlot &operator=(const ItemSlot &other);
    ItemSlot &operator=(ItemSlot &&other) noexcept;

    gstd::vector<EnchantStatus> ReadEnchant(void);
    void Enchanting(const gstd::vector<EnchantStatus> &enchants);

    gstd::string GetName(void);

    u8 count;
    u8 unk1;
    u16 dataValue;
    u32 unk2;
    u32 enchantInstance;
    Item *itemInstance;
    u32 renderInstance;
    u16 category;
    u16 number;
    u8 unk3[24];
};
}    // namespace MC3DSPluginFramework

#endif