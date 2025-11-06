#include "CreativeMenu.hpp"

namespace MC3DSPluginFramework {
namespace CreativeMenu {

namespace CTRPF = CTRPluginFramework;

struct AddItemData {
    Category category;
    u16 number;
    u16 itemID;
    u16 dataValue;
    std::vector<EnchantStatus> enchants;
};

static bool Hook_Installed;
static std::vector<AddItemData> Append_Items;

gstd::vector<SlotData> &GetItemList(void) {
    return *(gstd::vector<SlotData> *)0xB0D744;
}

void SetUpMenuItems(CTRPF::Regs &regs, u32 *sp, CTRPF::HookEx *hook) {
    Function<void>(0x56E450)();    // original function

    for (auto &Append_Item : Append_Items) {
        SlotData item(Append_Item.itemID, 1, Append_Item.dataValue);
        item.category = (u16)Append_Item.category;
        item.number   = Append_Item.number;

        if (!Append_Item.enchants.empty())
            item.Enchant(Append_Item.enchants);

        Function<void>(0x56E108)(item);
    }
}

void InstallHook(void) {
    static CTRPF::HookEx hook(0x47AEEC, SetUpMenuItems, CTRPF::HookEx::USE_LR_TO_RETURN);
    hook.Enable();
    Hook_Installed = hook.IsEnabled();
}

void Append(Category category, u16 number, u16 itemID, u16 dataValue) {
    if (!Hook_Installed)
        InstallHook();

    Append_Items.push_back(AddItemData{category, number, itemID, dataValue, {}});
}

void Append(Category category, u16 number, u16 itemID, u16 dataValue, const std::initializer_list<EnchantStatus> &enchants) {
    if (!Hook_Installed)
        InstallHook();

    Append_Items.push_back(AddItemData{category, number, itemID, dataValue, enchants});
}

void Append(Category category, u16 number, u16 itemID, u16 dataValue, const std::vector<EnchantStatus> &enchants) {
    if (!Hook_Installed)
        InstallHook();

    Append_Items.push_back(AddItemData{category, number, itemID, dataValue, enchants});
}

}    // namespace CreativeMenu
}    // namespace MC3DSPluginFramework