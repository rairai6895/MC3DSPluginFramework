#include "UserCode.hpp"
#include "Minecraft/Common/World/Item/Crafting/Recipes.hpp"
#include "Minecraft/Common/World/Item/Item.hpp"

namespace MC3DSPluginFramework::UserCode
{

    void onMainOnce()
    {
    }

    void registerRecipes(Recipes &recipes)
    {
        /*
        recipes.addShapedRecipe(
            ItemInstance((u16)ItemId::apple, 1, 0),
            "XX",
            "XX",
            { { 'X', ItemInstance((u16)ItemId::dirt, 1, 0) } },
            1, 1
        );
        */
    }

    void registerCreativeItems(void (*registerCreativeItem)(const ItemInstance &))
    {
        enum Category : u16 {
            Building_Blocks        = 1,
            Decorations            = 2,
            RedStone_and_Transport = 3,
            Food_and_Materials     = 4,
            Tools                  = 5,
            Brewing                = 6,
            Miscellaneous          = 7,
        };
    }

}    // namespace MC3DSPluginFramework::UserCode