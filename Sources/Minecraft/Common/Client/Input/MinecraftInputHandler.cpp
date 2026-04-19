#include "MinecraftInputHandler.hpp"
#include "ClientInputHandler.hpp"

namespace MC3DSPluginFramework
{
    MinecraftInputHandler::MinecraftInputHandler(ClientInputHandler *parent) :
        mParent(parent) {}
}    // namespace MC3DSPluginFramework