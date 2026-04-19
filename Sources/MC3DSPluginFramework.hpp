#pragma once

#include "Api/Api.hpp"
#include "Hooks/Hooks.hpp"
#include "Minecraft/Common/Client/Gui/Screens/ScreenStack.hpp"
#include "Minecraft/Common/Client/Locale/Language.hpp"
#include "Minecraft/Common/Client/Player/LocalPlayer.hpp"
#include "Minecraft/Common/Util/Util.hpp"
#include "Minecraft/Common/World/Entity/Entity.hpp"
#include "Minecraft/Common/World/Item/Item.hpp"
#include "Minecraft/Common/World/Item/ItemInstance.hpp"
#include "Minecraft/Common/World/Level/Block/Block.hpp"
#include "Minecraft/Common/World/Level/BlockSource.hpp"
#include "Minecraft/Common/World/Level/Level.hpp"
#include "Minecraft/Other/GameController.hpp"
#include "Minecraft/Other/TextCode.hpp"
#include "Minecraft/gctr/gsvc.hpp"
#include "Minecraft/gstd/gstd.hpp"

namespace MC3DSPluginFramework
{
    inline gstd::string getEntityName(EntityId id)
    {
        return reinterpret_cast<gstd::string (*)(EntityId)>(0x1496EC)(id);
    }

}    // namespace MC3DSPluginFramework
