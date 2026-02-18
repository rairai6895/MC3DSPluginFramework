#include "Minecraft/Common/World/Item/CreativeMenu.hpp"

namespace MC3DSPluginFramework
{
    namespace CreativeMenu
    {

        struct AddItemData {
            Category category;
            u16 number;
            ItemId itemID;
            u16 dataValue;
            std::vector<EnchantStatus> enchants;
        };

        static bool Hook_Installed;
        static std::vector<AddItemData> Append_Items;
        static std::mutex mutex;

        gstd::vector<ItemInstance> &GetItemList(void)
        {
            return *(gstd::vector<ItemInstance> *)0xB0D744;
        }

        void SetUpMenuItems(Regs &regs, u32 *sp, HookEx *hook)
        {
            std::lock_guard<std::mutex> lock(mutex);
            reinterpret_cast<void (*)()>(0x56E450)();    // original function

            for (auto &Append_Item : Append_Items) {
                ItemInstance item(Append_Item.itemID, 1, Append_Item.dataValue);
                item.mCategory = Append_Item.category;
                item.mNumber   = Append_Item.number;

                if (!Append_Item.enchants.empty())
                    item.setEnchants(gstd::vector<EnchantStatus>(Append_Item.enchants.begin(), Append_Item.enchants.end()));

                reinterpret_cast<void (*)(const ItemInstance &)>(0x56E108)(item);
            }
        }

        void InstallHook(void)
        {
            static HookEx hook;
            hook.InitRoutine(0x47AEEC, SetUpMenuItems);
            hook.Enable();
            Hook_Installed = hook.IsEnabled();
        }

        void Append(Category category, u16 number, ItemId itemId, u16 dataValue)
        {
            std::lock_guard<std::mutex> lock(mutex);
            if (!Hook_Installed)
                InstallHook();

            Append_Items.push_back(AddItemData { category, number, itemId, dataValue, {} });
        }

        void Append(Category category, u16 number, ItemId itemId, u16 dataValue, const std::initializer_list<EnchantStatus> &enchants)
        {
            std::lock_guard<std::mutex> lock(mutex);
            if (!Hook_Installed)
                InstallHook();

            Append_Items.push_back(AddItemData { category, number, itemId, dataValue, enchants });
        }

        void Append(Category category, u16 number, ItemId itemId, u16 dataValue, const std::vector<EnchantStatus> &enchants)
        {
            std::lock_guard<std::mutex> lock(mutex);
            if (!Hook_Installed)
                InstallHook();

            Append_Items.push_back(AddItemData { category, number, itemId, dataValue, enchants });
        }

    }    // namespace CreativeMenu
}    // namespace MC3DSPluginFramework