#pragma once

#include "../IntRectangle.hpp"
#include "GuiElement.hpp"

namespace MC3DSPluginFramework
{
    class NinePatchDescription
    {
        USE_GAME_ALLOCATOR
    public:
        NinePatchDescription(float x, float y, float x1, float x2, float x3, float y1, float y2, float y3, float west, float east, float north, float south);

        NinePatchDescription       &transformUVForImageSize(int w, int h);
        static NinePatchDescription createSymmetrical(int texW, int texH, const IntRectangle &src, int xCutAt, int yCutAt);

        float mU0;    // +0x0
        float mU1;    // +0x4
        float mU2;    // +0x8
        float mU3;    // +0xC
        float mV0;    // +0x10
        float mV1;    // +0x14
        float mV2;    // +0x18
        float mV3;    // +0x1C
        float mWest;    // +0x20
        float mEast;    // +0x24
        float mNorth;    // +0x28
        float mSouth;    // +0x2C
        int   mTexW;    // +0x30
        int   mTexH;    // +0x34
    };

    class NinePatchLayer : public GuiElement
    {
        USE_GAME_ALLOCATOR
    public:
        NinePatchLayer(const NinePatchDescription &description, const TexturePtr &texturePtr, float w, float h);
        ~NinePatchLayer() override = default;

        void _setSize(float w, float h);
        void draw(Tessellator &t, float x, float y);

    private:
        // 0x9AC2A0

        struct Quad
        {
            float mX0;    // +0x0
            float mX1;    // +0x4
            float mY0;    // +0x8
            float mY1;    // +0xC
            float mZ;    // +0x10
            float mU0;    // +0x14
            float mU1;    // +0x18
            float mV0;    // +0x1C
            float mV1;    // +0x20
        };

        float                mW;    // +0x38
        float                mH;    // +0x3C
        NinePatchDescription mDescription;    // +0x40
        TexturePtr           mTexturePtr;    // +0x78
        int                  mSkip;    // +0x98
        Quad                 mQuads[9];    // +0x9C
    };

    class NinePatchFactory
    {
        USE_GAME_ALLOCATOR
    public:
        NinePatchFactory(TextureGroup &textures, const ResourceLocation &resourceLocation);
        gstd::unique_ptr<NinePatchLayer> createSymmetrical(const IntRectangle &src, int xCutAt, int yCutAt, float w, float h);

    private:
        TextureGroup    *mTextures;    // +0x0
        ResourceLocation mResourceLocation;    // +0x4
        int              mW;    // +0x18
        int              mH;    // +0x1C
    };
}    // namespace MC3DSPluginFramework