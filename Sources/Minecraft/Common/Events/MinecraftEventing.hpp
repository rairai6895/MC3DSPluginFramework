#pragma once

namespace MC3DSPluginFramework
{
    class Player;

    // "C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\src\\common\\Events\\MinecraftEventing.cpp"
    class MinecraftEventing
    {
    public:
        static void fireEventPlayerTeleported(Player *player, float metersTravelled, int teleportationCause, int teleportationItem)
        {
            reinterpret_cast<void (*)(Player *, float, int, int)>(0x36799C)(player, metersTravelled, teleportationCause, teleportationItem);
        }

    private:
        char field[0x48];
    };
}    // namespace MC3DSPluginFramework