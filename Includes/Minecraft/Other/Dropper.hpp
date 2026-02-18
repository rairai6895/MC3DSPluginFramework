#pragma once

#include "Minecraft/Common/World/Entity/EntityClass.hpp"
#include "Minecraft/Common/World/Item/ItemInstance.hpp"

namespace MC3DSPluginFramework
{
    namespace Dropper
    {

        // Do not use while the game thread is stopped.
        inline void Send(Entity *entity, const ItemInstance &item, bool swing, bool diffusion)
        {
            reinterpret_cast<void (*)(Entity *, const ItemInstance &, bool)>(swing ? 0x198174 : 0x5F2F38)(entity, item, diffusion);
        }

    }    // namespace Dropper
}    // namespace MC3DSPluginFramework