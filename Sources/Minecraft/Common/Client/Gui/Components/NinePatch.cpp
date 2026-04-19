#include "NinePatch.hpp"

namespace MC3DSPluginFramework
{
    // FUN_0x3F79E0
    NinePatchDescription::NinePatchDescription(float x, float y, float x1, float x2, float x3, float y1, float y2, float y3, float west, float east, float north, float south)
    {
        this->mU0    = x;
        this->mU1    = x + x1;
        this->mU2    = x + x2;
        this->mU3    = x + x3;
        this->mV0    = y;
        this->mV1    = y + y1;
        this->mV2    = y + y2;
        this->mV3    = y + y3;
        this->mWest  = west;
        this->mEast  = east;
        this->mNorth = north;
        this->mSouth = south;
        this->mTexW  = -1;
        this->mTexH  = -1;
    }

    // FUN_0x3F7934
    NinePatchDescription &NinePatchDescription::transformUVForImageSize(int w, int h)
    {
        if (mTexH < 0)
        {
            mTexH = 1;
            mTexW = 1;
        }

        float uScale = float(mTexH) / float(w);
        float vScale = float(mTexH) / float(h);

        mU0 *= uScale;
        mU1 *= uScale;
        mU2 *= uScale;
        mU3 *= uScale;

        mV0 *= vScale;
        mV1 *= vScale;
        mV2 *= vScale;
        mV3 *= vScale;

        mTexW = w;
        mTexH = h;

        return *this;
    }

    // FUN_0x3F786C
    NinePatchDescription NinePatchDescription::createSymmetrical(int texW, int texH, const IntRectangle &src, int xCutAt, int yCutAt)
    {
        NinePatchDescription res(
            src.mX,
            src.mY,
            xCutAt,
            src.mWidth - xCutAt,
            src.mWidth,
            yCutAt,
            src.mHeight - yCutAt,
            src.mHeight,
            xCutAt,
            xCutAt,
            yCutAt,
            yCutAt
        );

        if (0 < texW)
            res.transformUVForImageSize(texW, texH);

        return res;
    }

    // FUN_0x27F230
    NinePatchLayer::NinePatchLayer(const NinePatchDescription &description /* ゲーム内ではコピー渡しっぽい */, const TexturePtr &texturePtr, float w, float h) :
        GuiElement(true, true, 0, 0, 24, 24, 192),
        mDescription(description),
        mTexturePtr(texturePtr),
        mSkip(0)
    {
        _setSize(w, h);
    }

    // FUN_0x27F0EC
    void NinePatchLayer::_setSize(float w, float h)
    {
        if (mW == w && mH == h)
            return;

        this->mW = w;
        this->mH = h;

        int i = 0;
        for (auto &q : mQuads)
        {
            int yid = i / 3;
            int xid = i % 3;

            q.mU0 = (&mDescription.mU0)[xid];
            q.mU1 = (&mDescription.mU1)[xid];
            q.mV0 = (&mDescription.mV0)[yid];
            q.mV1 = (&mDescription.mV1)[yid];
            q.mZ  = 0;

            if (xid == 0)
            {
                q.mX0 = 0;
                q.mX1 = mDescription.mWest;
            }
            else if (xid == 1)
            {
                q.mX0 = mDescription.mWest;
                q.mX1 = mW - mDescription.mEast;
            }
            else if (xid == 2)
            {
                q.mX0 = mW - mDescription.mEast;
                q.mX1 = mW;
            }
            if (yid == 0)
            {
                q.mY0 = 0;
                q.mY1 = mDescription.mNorth;
            }
            else if (yid == 1)
            {
                q.mY0 = mDescription.mNorth;
                q.mY1 = mH - mDescription.mSouth;
            }
            else if (yid == 2)
            {
                q.mY0 = mH - mDescription.mSouth;
                q.mY1 = mH;
            }

            ++i;
        }
    }

    // FUN_0x27EFE0
    void NinePatchLayer::draw(Tessellator &t, float x, float y)
    {
        t.begin(0x24);
        t.addOffset(x, y, 0);

        int i = 1;
        for (auto &q : mQuads)
        {
            if (!(mSkip & i))
            {
                t.vertexUV(q.mX0, q.mY1, q.mZ, q.mU0, q.mV1);
                t.vertexUV(q.mX1, q.mY1, q.mZ, q.mU1, q.mV1);
                t.vertexUV(q.mX1, q.mY0, q.mZ, q.mU1, q.mV0);
                t.vertexUV(q.mX0, q.mY0, q.mZ, q.mU0, q.mV0);
            }

            i <<= 1;
        }

        t.addOffset(-x, -y, 0);
        t.draw(Materials::ui_textured, mTexturePtr);
    }

    NinePatchFactory::NinePatchFactory(TextureGroup &textures, const ResourceLocation &resourceLocation)
    {
        reinterpret_cast<NinePatchFactory *(*)(NinePatchFactory *, TextureGroup &, const ResourceLocation &)>(0x3382F8)(this, textures, resourceLocation);
    }

    // FUN_0x338130
    gstd::unique_ptr<NinePatchLayer> NinePatchFactory::createSymmetrical(const IntRectangle &src, int xCutAt, int yCutAt, float w, float h)
    {
        return gstd::make_unique<NinePatchLayer>(NinePatchDescription::createSymmetrical(mW, mH, src, xCutAt, yCutAt), TexturePtr(*mTextures, mResourceLocation), w, h);
    }

}    // namespace MC3DSPluginFramework