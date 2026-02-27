#include "Minecraft/Common/Client/Input/MinecraftInputHandler.hpp"
#include "Minecraft/Common/Client/Input/PlayerController.hpp"

namespace MC3DSPluginFramework
{
    MinecraftInputHandler::MinecraftInputHandler(PlayerController *parent) :
        mParent(parent) {}
}    // namespace MC3DSPluginFramework