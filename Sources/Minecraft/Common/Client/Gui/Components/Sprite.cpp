#include "Sprite.hpp"
#include "Minecraft/Common/Client/Game/MinecraftGame.hpp"

namespace MC3DSPluginFramework
{
    // FUN_0x55FE08
    Sprite::Sprite(MinecraftGame *minecraftGame, int x, int y, int w, int h, const ResourceLocation &resourceLocation, int u, int v, int texW, int texH) :
        mVisible(true),
        mMaterialPtr(reinterpret_cast<RenderMaterialGroup *>(0xAC41E8), "ui_textured"),
        mMeshRef(mMesh),
        mColor(Color::WHITE)
    {
        mTexturePtr = TexturePtr(minecraftGame->getTextures(), resourceLocation);
        mMesh       = Mesh(this, minecraftGame, x, y, w, h, mTexturePtr, u, v, texW, texH, false);
    }

    // FUN_0x55FDC4
    void Sprite::render()
    {
        if (mVisible)
        {
            Unanalyzed::setShaderColor(mColor);
            mMeshRef.render(mMaterialPtr, mTexturePtr, 0, 0);
        }
    }
}    // namespace MC3DSPluginFramework