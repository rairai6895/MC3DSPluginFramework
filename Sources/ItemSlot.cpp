#include "ItemSlot.hpp"

namespace MC3DSPluginFramework {

ItemSlot::ItemSlot() {
    Function<void>(0x1D2894)(this, 0, 0, 0);
};

ItemSlot::ItemSlot(ItemID itemID, u8 count, u16 dataValue) {
    Function<void>(0x1D2894)(this, itemID, count, dataValue);
}

ItemSlot::ItemSlot(void *block, u8 count, u16 dataValue) {
    Function<void>(0x1D2704)(this, block, count, dataValue);
}

ItemSlot::ItemSlot(const ItemSlot &other) {
    Function<void>(0x1D2768)(this, &other);
}

ItemSlot::ItemSlot(ItemSlot &&other) noexcept {
    memcpy(this, &other, sizeof(ItemSlot));
    memset(&other, 0, sizeof(ItemSlot));
}

ItemSlot::~ItemSlot() {
    Function<void>(0x1D20E0)(this);
}

ItemSlot &ItemSlot::operator=(const ItemSlot &other) {
    if (this != &other) {
        if (u32 ench = enchantInstance) {
            Function<void>(0x1D2768)(this, &other);
            Function<void>(0x182588)(ench);
        } else
            Function<void>(0x1D2768)(this, &other);
    }
    return *this;
}

ItemSlot &ItemSlot::operator=(ItemSlot &&other) noexcept {
    if (this != &other) {
        if (u32 ench = enchantInstance) {
            memcpy(this, &other, sizeof(ItemSlot));
            memset(&other, 0, sizeof(ItemSlot));
            Function<void>(0x182588)(ench);
        } else {
            memcpy(this, &other, sizeof(ItemSlot));
            memset(&other, 0, sizeof(ItemSlot));
        }
    }
    return *this;
}

gstd::vector<EnchantStatus> ItemSlot::ReadEnchant(void) {
    EnchantArgs args{};
    Function<void>(0x6B25EC)(&args, this);
    return std::move(args.enchants);
}

void ItemSlot::Enchanting(const gstd::vector<EnchantStatus> &enchants) {
    EnchantArgs args{};
    args.enchants = enchants;
    Function<void>(0x1D1670)(this, &args);
}

gstd::string ItemSlot::GetName(void) {
    gstd::string res;
    Function<void>(0x6B1840)(&res, this);
    return res;
}

}    // namespace MC3DSPluginFramework