#pragma once

#include "Minecraft/gstd/gstd.hpp"
#include "Minecraft/src-deps/Input/RectangleArea.hpp"

namespace MC3DSPluginFramework
{
    class ClientInputHandler;

    // "C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\src\\common\\client\\input\\MinecraftInputHandler.cpp"
    class MinecraftInputHandler
    {
        USE_GAME_ALLOCATOR
    public:
        MinecraftInputHandler(ClientInputHandler *parent);
        virtual ~MinecraftInputHandler() = default;    // 仮

    private:
        // 0x9C3900

        ClientInputHandler *mParent;
        RectangleArea       mUnk1[30];
    };
}    // namespace MC3DSPluginFramework