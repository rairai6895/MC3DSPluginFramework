#pragma once

#include "Minecraft/Common/World/Phys/Vec2.hpp"
#include "Minecraft/Common/World/Phys/Vec3.hpp"
#include "Minecraft/gstd/gstd.hpp"
#include "Minecraft/src-deps/Core/Math/Color.hpp"
#include "Minecraft/src-deps/Renderer/Mesh.hpp"
#include <types.h>

namespace MC3DSPluginFramework
{
    class MaterialPtr;

    // "C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\src\\common\\client\\renderer\\renderer\\Tessellator.cpp"
    class Tessellator
    {
    private:
        void _tex(const Vec2<float> &uv, int idx);

    public:
        static inline Tessellator &instance = *(Tessellator *)0xAC42D8;    // singleton

        virtual ~Tessellator();

        void begin(int mode, int maxVertices);
        void begin(int maxVertices);
        Mesh end(const char *debugName, bool temporary);
        void clear();
        void draw(MaterialPtr &materialPtr);
        void draw(MaterialPtr &materialPtr, TexturePtr &texturePtr);
        void drawCube();
        void color(int r, int g, int b, int a);
        void color(float r, float g, float b, float a);
        void color(int rgb);
        void color(const Color &color);
        void colorABGR(int c);
        void tex(float u, float v);
        void tex(const Vec2<float> &uv);
        void tex1(float u, float v);
        void tex1(const Vec2<float> &uv);
        void vertex(float x, float y, float z);
        void vertex(const Vec3<float> &pos);
        void vertexUV(float x, float y, float z, float u, float v);
        void vertexUV(const Vec3<float> &pos, float u, float v);
        void normal(float x, float y, float z);
        void normal(const Vec3<float> &pos);
        void triangle(int i1, int i2, int i3);
        void addOffset(float x, float y, float z);

    private:
        //  0x99EBC8

        static constexpr int iMask = 2;

        gstd::string mUnk1;    // +0x4
        int          mUnk2;    // +0x8

        gstd::map<gstd::type_unknown<>, gstd::type_unknown<>> mUnk3;    // +0xC

        char        mIndexPhase;    // +0x28
        int         mIndexSize;    // +0x2C
        int         mIndexCount;    // +0x30
        int         m_iVertexFormat;    // +0x34
        int         mUnk6;    // +0x38
        float      *m_pCurrentVertexField;    // +0x3C
        int         mUnk7;    // +0x40
        float       m_xo;    // +0x44
        float       m_yo;    // +0x48
        float       m_zo;    // +0x4C
        float       mUnk8;    // +0x50
        float       mUnk9;    // +0x54
        float       mUnk10;    // +0x58
        float       mUnk11;    // +0x5C
        float       mUnk12;    // +0x60
        float       mUnk13;    // +0x64
        Vec2<float> mUnk14;    // +0x68
        int         mUnk16;    // +0x70
        int         mUnk17;    // +0x74
        int         mUnk18;    // +0x78
        int         mUnk19;    // +0x7C
        int         mColor;    // +0x80
        int         mUnk20;    // +0x84
        int         mUnk21;    // +0x88
        int         mUnk22;    // +0x8C
        float       mUnk23;    // +0x90
        float       mUnk24;    // +0x94
        float       mUnk25;    // +0x98
        int         mUnk26;    // +0x9C
        float       mUnk27;    // +0xA0
        float       mUnk28;    // +0xA4
        float       mUnk29;    // +0xA8
        int         mUnk30;    // +0xAC
        float       mUnk31;    // +0xB0
        float       mUnk32;    // +0xB4
        float       mUnk33;    // +0xB8
        int         mUnk34;    // +0xBC
        float       mUnk35;    // +0xC0
        float       mUnk36;    // +0xC4
        float       mUnk37;    // +0xC8
        float       mUnk38;    // +0xCC
        bool        mUnk39;    // +0xD0
        bool        mVoidBeginEnd;    // +0xD1
        int         mUnk40;    // +0xD4
        int         mUnk41;    // +0xD8
        int         mUnk42;    // +0xDC
        int         mUnk43;    // +0xE0
        int         mVertexCount;    // +0xE4
        bool        mTessellating;    // +0xE8
        char        mUnk44;    // +0xE9
        void       *mUnk45;    // +0xEC
        int         mUnk46;    // +0xF0
        int         mUnk47;    // +0xF4
        int         mUnk48;    // +0xF8
        int         mUnk49;    // +0xFC
        void       *mUnk50;    // +0x100
        int         mUnk51;    // +0x104
        int         mUnk52;    // +0x108
        int         mUnk53;    // +0x10C
        void       *mUnk54;    // +0x110
        int         mUnk55;    // +0x114
        int         mUnk56;    // +0x118
        int         mUnk57;    // +0x11C
    };
}    // namespace MC3DSPluginFramework