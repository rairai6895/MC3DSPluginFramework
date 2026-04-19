#pragma once

#include "../GuiComponent.hpp"
#include "Minecraft/src-deps/Core/Math/Color.hpp"
#include "Minecraft/src-deps/Renderer/MaterialPtr.hpp"
#include "Minecraft/src-deps/Renderer/Mesh.hpp"
#include "Minecraft/src-deps/Renderer/TexturePtr.hpp"

namespace MC3DSPluginFramework
{
    class RenderMaterialGroup;

    // 仮名
    class Sprite
    {
        USE_GAME_ALLOCATOR
    public:
        Sprite(MinecraftGame *minecraftGame, int x, int y, int w, int h, const ResourceLocation &resourceLocation, int u, int v, int texW, int texH);
        ~Sprite() = default;

        void render();

    private:
        bool        mVisible;    // +0x0
        MaterialPtr mMaterialPtr;    // +0x4
        TexturePtr  mTexturePtr;    // +0x10
        Mesh        mMesh;    // +0x30
        Mesh       &mMeshRef;    // +0x94 なんであるのか意味不明
        Color       mColor;    // +0x98
    };
}    // namespace MC3DSPluginFramework