#pragma once

#include "../ItemInstance.hpp"

namespace MC3DSPluginFramework
{
    // 派生クラスが多すぎるので解析はしばらく諦め
    class Recipe
    {
    public:
        virtual ~Recipe() = default;

        u16                                   mCategory;    // +0x4
        u16                                   mPos;    // +0x6
        gstd::map<int, gstd::type_unknown<8>> m0x8;
        int                                   m0x24;
        int                                   m0x28;
        int                                   m0x2C;
        int                                   m0x30;
        int                                   m0x34;
    };

    /*
    class ShapedRecipe : public Recipe
    {
        ~ShapedRecipe() override;

        int                        mWidth  = 0;    // +0x38
        int                        mHeight = 0;    // +0x3C
        gstd::vector<ItemInstance> mIngredients;    // +0x40
        gstd::vector<ItemInstance> mResult;    // +0x4C
    };
    */

    // "C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\src\\common\\world\\item\\crafting\\Recipes.cpp"
    class Recipes
    {
    public:
        struct Type
        {
            Item        *mItem;    // +0x0
            Block       *mBlock;    // +0x4
            ItemInstance mItemInstance;    // +0x8 // データ値とか細かい情報を持たせるとき用？
            char         mC;    // +0x38

            Type(char c, Item *item) :
                mItem(item), mBlock(nullptr), mC(c) {}

            Type(char c, Block *block) :
                mItem(nullptr), mBlock(block), mC(c) {}

            Type(char c, const ItemInstance &itemInstance) :
                mItem(nullptr), mBlock(nullptr), mItemInstance(itemInstance), mC(c) {}
        };

        using TypeList = gstd::vector<Type>;
        using RowList  = gstd::vector<gstd::string>;

        void addShapedRecipe(const gstd::vector<ItemInstance> &result, const RowList &rows, const TypeList &types, u16 category, u16 pos);
        void addShapedRecipe(const ItemInstance &result, const RowList &rows, const TypeList &types, u16 category, u16 pos);
        void addShapedRecipe(const ItemInstance &result, const gstd::string &r0, const TypeList &types, u16 category, u16 pos);
        void addShapedRecipe(const ItemInstance &result, const gstd::string &r0, const gstd::string &r1, const TypeList &types, u16 category, u16 pos);
        void addShapedRecipe(const ItemInstance &result, const gstd::string &r0, const gstd::string &r1, const gstd::string &r2, const TypeList &types, u16 category, u16 pos);

        void            registerRecipes();
        static Recipes &getInstance();

    private:
        static inline gstd::unique_ptr<Recipes> &mInstance = *(gstd::unique_ptr<Recipes> *)0xA33EBC;

        gstd::vector<gstd::unique_ptr<Recipe>> mRecipes;
    };

    Recipes::TypeList definition(char c0, Block *block);
    Recipes::TypeList definition(char c0, const ItemInstance &itemInstance);
    Recipes::TypeList definition(char c0, Item *item0, char c1, Item *item1);

}    // namespace MC3DSPluginFramework