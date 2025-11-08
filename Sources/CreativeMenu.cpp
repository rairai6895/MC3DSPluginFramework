#include "CreativeMenu.hpp"

namespace MC3DSPluginFramework {
namespace CreativeMenu {

struct AddItemData {
    Category category;
    u16 number;
    ItemID itemID;
    u16 dataValue;
    std::vector<EnchantStatus> enchants;
};

static bool Hook_Installed;
static std::vector<AddItemData> Append_Items;
static std::mutex mutex;

gstd::vector<ItemSlot> &GetItemList(void) {
    return *(gstd::vector<ItemSlot> *)0xB0D744;
}

void SetUpMenuItems(Regs &regs, u32 *sp, HookEx *hook) {
    std::lock_guard<std::mutex> lock(mutex);
    Function<void>(0x56E450)();    // original function

    for (auto &Append_Item : Append_Items) {
        ItemSlot item(Append_Item.itemID, 1, Append_Item.dataValue);
        item.category = Append_Item.category;
        item.number   = Append_Item.number;

        if (!Append_Item.enchants.empty())
            item.Enchanting(gstd::vector<EnchantStatus>(Append_Item.enchants.begin(), Append_Item.enchants.end()));

        Function<void>(0x56E108)(item);
    }
}

void InstallHook(void) {
    static HookEx hook(0x47AEEC, SetUpMenuItems, HookEx::USE_LR_TO_RETURN);
    hook.Enable();
    Hook_Installed = hook.IsEnabled();
}

void Append(Category category, u16 number, ItemID itemID, u16 dataValue) {
    std::lock_guard<std::mutex> lock(mutex);
    if (!Hook_Installed)
        InstallHook();

    Append_Items.push_back(AddItemData{category, number, itemID, dataValue, {}});
}

void Append(Category category, u16 number, ItemID itemID, u16 dataValue, const std::initializer_list<EnchantStatus> &enchants) {
    std::lock_guard<std::mutex> lock(mutex);
    if (!Hook_Installed)
        InstallHook();

    Append_Items.push_back(AddItemData{category, number, itemID, dataValue, enchants});
}

void Append(Category category, u16 number, ItemID itemID, u16 dataValue, const std::vector<EnchantStatus> &enchants) {
    std::lock_guard<std::mutex> lock(mutex);
    if (!Hook_Installed)
        InstallHook();

    Append_Items.push_back(AddItemData{category, number, itemID, dataValue, enchants});
}

}    // namespace CreativeMenu
}    // namespace MC3DSPluginFramework