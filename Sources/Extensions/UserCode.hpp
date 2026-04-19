#pragma once

#include "Minecraft/Common/World/Item/ItemInstance.hpp"

namespace MC3DSPluginFramework
{
    class Recipes;

    namespace UserCode
    {
        void onMainOnce();
        void registerRecipes(Recipes &recipes);
        void registerCreativeItems(void (*registerCreativeItem)(const ItemInstance &));
    }    // namespace UserCode
}    // namespace MC3DSPluginFramework