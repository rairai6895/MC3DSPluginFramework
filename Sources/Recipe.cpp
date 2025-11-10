#include "Recipe.hpp"

namespace MC3DSPluginFramework {
namespace Recipe {

struct AppendRecipe {
    Category category;
    u16 num;
    u32 size_x;
    u32 size_y;
    std::vector<Item> need;
    Item res;
};

static bool Hook_Installed;
static std::vector<AppendRecipe> Append_Recipes;
static std::mutex mutex;

gstd::vector<RecipeData *> *CreateList(void) {
    return Function<gstd::vector<RecipeData *> *>(0x635CCC)();
}

void ResetList(gstd::vector<RecipeData *> *list) {
    Function<void>(0x638CC0)(list);
}

void SetUpRecipes(Regs &regs, u32 *sp, HookEx *hook) {
    std::lock_guard<std::mutex> lock(mutex);
    gstd::vector<RecipeData *> *recipeList = (gstd::vector<RecipeData *> *)regs.r0;
    ResetList(recipeList);

    for (auto &Append_Recipe : Append_Recipes) {
        gstd::vector<ItemSlot> need;
        need.reserve(std::max<u32>(Append_Recipe.size_x, 1) * std::max<u32>(Append_Recipe.size_y, 1));
        for (auto &data : Append_Recipe.need) {
            ItemSlot item(data.itemID, data.count, data.dataValue);

            if (!data.enchants.empty())
                item.Enchanting(gstd::vector<EnchantStatus>(data.enchants.begin(), data.enchants.end()));

            need.push_back(std::move(item));
        }

        ItemSlot res(Append_Recipe.res.itemID, Append_Recipe.res.count, Append_Recipe.res.dataValue);

        if (!Append_Recipe.res.enchants.empty())
            res.Enchanting(gstd::vector<EnchantStatus>(Append_Recipe.res.enchants.begin(), Append_Recipe.res.enchants.end()));

        RecipeData *newRecipe = gstd::_new<RecipeData>(
            RecipeData(
                Append_Recipe.category,
                Append_Recipe.num,
                Append_Recipe.size_x,
                Append_Recipe.size_y,
                std::move(need),
                std::move(gstd::vector<ItemSlot>({std::move(res)}))
            )
        );

        recipeList->push_back(newRecipe);
    }
}

void InstallHook(void) {
    static HookEx hook(0x47AF04, SetUpRecipes, HookEx::USE_LR_TO_RETURN);
    hook.Enable();
    Hook_Installed = hook.IsEnabled();
}

gstd::vector<RecipeData *> *GetList(void) {
    return *(gstd::vector<RecipeData *> **)0xA33EBC;
}

void Append(Category category, u16 num, u32 x, u32 y, const std::vector<Item> &need, const Item &res) {
    std::lock_guard<std::mutex> lock(mutex);
    if (!Hook_Installed)
        InstallHook();

    Append_Recipes.push_back({category, num, x, y, need, res});
}

/*
void Append(Category category, u16 num, u32 x, u32 y, const std::vector<SlotData> &need, const SlotData &res) {
    if (gstd::vector<RecipeData *> *list = GetList()) {
        if (RecipeData *newRecipe = gstd::_new<RecipeData>()) {
            newRecipe->vtable   = 0x9A2664;
            newRecipe->category = category;
            newRecipe->num      = num;
            *newRecipe->unk1    = {};
            newRecipe->size_x   = x;
            newRecipe->size_y   = y;
            newRecipe->need     = std::move(gstd::vector<SlotData>(need.begin(), need.end()));
            newRecipe->res      = std::move(gstd::vector<SlotData>({res}));
            list->push_back(newRecipe);
        }
    }
}
*/

}    // namespace Recipe
}    // namespace MC3DSPluginFramework