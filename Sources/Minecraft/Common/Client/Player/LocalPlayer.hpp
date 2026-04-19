#pragma once

#include "Minecraft/Common/Client/Game/ClientInstance.hpp"
#include "Minecraft/Common/World/Entity/Player/Player.hpp"
#include "Minecraft/Common/World/Item/ItemInstance.hpp"
#include "Minecraft/Common/World/Phys/HitResult.hpp"

namespace MC3DSPluginFramework
{
    // "C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\src\\common\\client\\player\\LocalPlayer.cpp"
    class LocalPlayer : public Player
    {
        USE_GAME_ALLOCATOR
    public:
        void            pickBlockCreative(HitResult &hitResult, bool saveBlockEntityNbt);
        void            addItemCreative(const ItemInstance &item);
        ClientInstance &getClient();

    private:
        // 0x99C31C

        int   m0x19A0;
        int   m0x19A4;
        int   m0x19A8;
        int   m0x19AC;
        int   m0x19B0;
        int   m0x19B4;
        int   m0x19B8;
        int   m0x19BC;
        float m0x19C0;
        float m0x19C4;

        ClientInstance *mClientInstance;    // +0x19C8
    };
}    // namespace MC3DSPluginFramework