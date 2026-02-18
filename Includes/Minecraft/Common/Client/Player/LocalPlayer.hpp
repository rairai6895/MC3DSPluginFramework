#pragma once

#include "Minecraft/Common/Client/Game/ClientInstance.hpp"

namespace MC3DSPluginFramework
{
    // "C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\src\\common\\client\\player\\LocalPlayer.cpp"
    class LocalPlayer
    {
    public:
        static void pickBlockCreative(ClientInstance *clientInstance)
        {
            reinterpret_cast<void (*)(ClientInstance *)>(0x3E99DC)(clientInstance);
        }

        void addItemCreative(const ItemInstance &itemInstance)
        {
            reinterpret_cast<void (*)(LocalPlayer *, const ItemInstance &)>(0x19562C)(this, itemInstance);
        }

    private:
    };
}    // namespace MC3DSPluginFramework