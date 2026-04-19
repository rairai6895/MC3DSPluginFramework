#include "Tessellator.hpp"

namespace MC3DSPluginFramework
{
    void Tessellator::_tex(const Vec2<float> &uv, int idx)
    {
        reinterpret_cast<void (*)(Tessellator *, const Vec2<float> &, int)>(0x1B17B8)(this, uv, idx);
    }

    void Tessellator::begin(int mode, int maxVertices)
    {
        reinterpret_cast<void (*)(Tessellator *, int, int)>(0x1B1BFC)(this, mode, maxVertices);
    }

    // FUN_0x1B1BF0
    void Tessellator::begin(int maxVertices)
    {
        begin(1, maxVertices);
    }

    Mesh Tessellator::end(const char *debugName, bool temporary)
    {
        return reinterpret_cast<Mesh (*)(Tessellator *, const char *, bool)>(0x1B15BC)(this, debugName, temporary);
    }

    void Tessellator::clear()
    {
        reinterpret_cast<void (*)(Tessellator *)>(0x1B1EA8)(this);
    }

    // FUN_0x1B1904
    void Tessellator::draw(MaterialPtr &materialPtr)
    {
        if (!mTessellating || mVoidBeginEnd)
            return;

        if (mVertexCount)
        {
            Mesh mesh = end("draw", true);
            mesh.render(materialPtr, 0, 0);
        }

        clear();
    }

    // FUN_0x1B1984
    void Tessellator::draw(MaterialPtr &materialPtr, TexturePtr &texturePtr)
    {
        if (!mTessellating || mVoidBeginEnd)
            return;

        if (mVertexCount)
        {
            Mesh mesh = end("draw", true);
            mesh.render(materialPtr, texturePtr, 0, 0);
        }

        clear();
    }

    void Tessellator::drawCube()
    {
        reinterpret_cast<void (*)(Tessellator *)>(0x3D6EEC)(this);
    }

    // FUN_0x1B20C8
    void Tessellator::color(int r, int g, int b, int a)
    {
        if (mUnk39)
            return;

        mColor = r | (g << 8) | (b << 16) | (a << 24);

        if (!(!m_pCurrentVertexField || ((m_iVertexFormat & iMask) != 0)))
            LOG("Can't add Vertex Color at this point", !m_pCurrentVertexField || ((m_iVertexFormat & iMask) != 0), 0);

        m_iVertexFormat |= iMask;
    }

    // FUN_0x1B1FEC
    void Tessellator::color(float r, float g, float b, float a)
    {
        color((int)(r * 255), (int)(g * 255), (int)(b * 255), (int)(a * 255));
    }

    // FUN_0x1B21BC
    void Tessellator::color(int rgb)
    {
        color((rgb >> 16) & 0xFF, (rgb >> 8) & 0xFF, rgb & 0xFF, 255);
    }

    // FUN_0x1B1F00
    void Tessellator::color(const Color &color)
    {
        this->color(color.r, color.g, color.b, color.a);
    }

    // FUN_0x1B30A8
    void Tessellator::colorABGR(int c)
    {
        if (mUnk39)
            return;

        mColor = c;

        if (!(!m_pCurrentVertexField || ((m_iVertexFormat & iMask) != 0)))
            LOG("Can't add Vertex Color at this point", !m_pCurrentVertexField || ((m_iVertexFormat & iMask) != 0), 0);

        m_iVertexFormat |= iMask;
    }

    // FUN_0x1B1790
    void Tessellator::tex(float u, float v)
    {
        _tex(Vec2(u, v), 0);
    }

    // FUN_0x1B17B0
    void Tessellator::tex(const Vec2<float> &uv)
    {
        _tex(uv, 0);
    }

    // FUN_0x1B1B84
    void Tessellator::tex1(float u, float v)
    {
        _tex(Vec2(u, v), 1);
    }

    // FUN_0x1B1B7C
    void Tessellator::tex1(const Vec2<float> &uv)
    {
        _tex(uv, 1);
    }

    void Tessellator::vertex(float x, float y, float z)
    {
        reinterpret_cast<void (*)(Tessellator *, float, float, float)>(0x1B2444)(this, x, y, z);
    }

    // FUN_0x1B243C
    void Tessellator::vertex(const Vec3<float> &pos)
    {
        vertex(pos.x, pos.y, pos.z);
    }

    // FUN_0x1B300C
    void Tessellator::vertexUV(float x, float y, float z, float u, float v)
    {
        tex(u, v);
        vertex(x, y, z);
    }

    // FUN_0x1B2B60
    void Tessellator::vertexUV(const Vec3<float> &pos, float u, float v)
    {
        vertexUV(pos.x, pos.y, pos.z, u, v);
    }

    void Tessellator::normal(float x, float y, float z)
    {
        reinterpret_cast<void (*)(Tessellator *, float, float, float)>(0x1B2308)(this, x, y, z);
    }

    // FUN_0x1B2300
    void Tessellator::normal(const Vec3<float> &pos)
    {
        normal(pos.x, pos.y, pos.z);
    }

    void Tessellator::triangle(int i1, int i2, int i3)
    {
        reinterpret_cast<void (*)(Tessellator *, int, int, int)>(0x1B28E0)(this, i1, i2, i3);
    }

    void Tessellator::addOffset(float x, float y, float z)
    {
        m_xo += x;
        m_yo += y;
        m_zo += z;
    }

}    // namespace MC3DSPluginFramework