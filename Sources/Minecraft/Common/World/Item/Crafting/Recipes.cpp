#include "Recipes.hpp"

namespace MC3DSPluginFramework
{
    void Recipes::addShapedRecipe(const gstd::vector<ItemInstance> &result, const RowList &rows, const TypeList &types, u16 category, u16 pos)
    {
        // result2つ以上でも1つしか反映されない。なぜvectorにしたのか謎

        using sig = void (*)(Recipes *, const gstd::vector<ItemInstance> &, const RowList &, const TypeList &, u16, u16);
        sig(0x6368F0)(this, result, rows, types, category, pos);
    }

    // FUN_0x63684C
    void Recipes::addShapedRecipe(const ItemInstance &result, const RowList &rows, const TypeList &types, u16 category, u16 pos)
    {
        addShapedRecipe(gstd::vector<ItemInstance>({ result }), rows, types, category, pos);
    }

    // FUN_0x6366DC
    void Recipes::addShapedRecipe(const ItemInstance &result, const gstd::string &r0, const TypeList &types, u16 category, u16 pos)
    {
        addShapedRecipe(result, { r0 }, types, category, pos);
    }

    // FUN_0x636744
    void Recipes::addShapedRecipe(const ItemInstance &result, const gstd::string &r0, const gstd::string &r1, const TypeList &types, u16 category, u16 pos)
    {
        addShapedRecipe(result, { r0, r1 }, types, category, pos);
    }

    // FUN_0x6367C0
    void Recipes::addShapedRecipe(const ItemInstance &result, const gstd::string &r0, const gstd::string &r1, const gstd::string &r2, const TypeList &types, u16 category, u16 pos)
    {
        addShapedRecipe(result, { r0, r1, r2 }, types, category, pos);
    }

    void Recipes::registerRecipes()
    {
        reinterpret_cast<void (*)(Recipes *)>(0x638CC0)(this);    // なぜコンストラクタにしなかったのか謎
    }

    // FUN_0x635CCC
    Recipes &Recipes::getInstance()
    {
        if (!mInstance)
        {
            mInstance = gstd::make_unique<Recipes>();
            mInstance->registerRecipes();
        }

        return *mInstance;
    }

    // 多分テンプレート

    // FUN_0x7CAB98
    Recipes::TypeList definition(char c0, Block *block)
    {
        Recipes::TypeList res;
        res.push_back(Recipes::Type(c0, block));
        return res;
    }

    // FUN_0x7CA74C
    Recipes::TypeList definition(char c0, const ItemInstance &itemInstance)
    {
        Recipes::TypeList res;
        res.push_back(Recipes::Type(c0, itemInstance));
        return res;
    }

    // FUN_0x7CA97C
    Recipes::TypeList definition(char c0, Item *item0, char c1, Item *item1)
    {
        Recipes::TypeList res;
        res.push_back(Recipes::Type(c0, item0));
        res.push_back(Recipes::Type(c1, item1));
        return res;
    }

}    // namespace MC3DSPluginFramework