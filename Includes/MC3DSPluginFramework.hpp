#pragma once

#include "Minecraft/Common/Util/Util.hpp"
#include "Minecraft/Common/World/Entity/Entity.hpp"
#include "Minecraft/Common/World/Entity/EntityClass.hpp"
#include "Minecraft/Common/World/Entity/Player/Player.hpp"
#include "Minecraft/Common/World/Entity/Spawn.hpp"
#include "Minecraft/Common/World/Item/CreativeMenu.hpp"
#include "Minecraft/Common/World/Item/Inventory.hpp"
#include "Minecraft/Common/World/Item/ItemInstance.hpp"
#include "Minecraft/Common/World/Item/Recipe.hpp"
#include "Minecraft/Common/World/Level/Block.hpp"
#include "Minecraft/Common/World/Level/BlockSource.hpp"
#include "Minecraft/Common/World/Level/Level.hpp"
#include "Minecraft/Helper/GameStructs.hpp"
#include "Minecraft/Other/Achievement.hpp"
#include "Minecraft/Other/Dropper.hpp"
#include "Minecraft/Other/GameController.hpp"
#include "Minecraft/Other/GameHelper.hpp"
#include "Minecraft/Other/GameHooks.hpp"
#include "Minecraft/Other/GameSound.hpp"
#include "Minecraft/Other/Language.hpp"
#include "Minecraft/Other/TextCode.hpp"
#include "Minecraft/Other/gsvc.hpp"
#include "Minecraft/gstd/gstd.hpp"

namespace MC3DSPluginFramework
{

    inline gstd::string GameModeToString(GameModes mode)
    {
        return reinterpret_cast<gstd::string (*)(GameModes)>(0x1C99C0)(mode);
    }

}    // namespace MC3DSPluginFramework
