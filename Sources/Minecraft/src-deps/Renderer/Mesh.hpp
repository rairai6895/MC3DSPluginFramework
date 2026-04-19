#pragma once

#include "MaterialPtr.hpp"
#include "Minecraft/gstd/gstd.hpp"
#include "TexturePtr.hpp"

namespace MC3DSPluginFramework
{
    class MinecraftGame;
    class Sprite;

    // "C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\src-deps\\Renderer\\Mesh.cpp"
    class Mesh
    {
    public:
        Mesh()
        {
            reinterpret_cast<Mesh *(*)(Mesh *)>(0x5091CC)(this);
        }

        Mesh(Sprite *p1, MinecraftGame *minecraftGame, int x, int y, int w, int h, TexturePtr &texturePtr, int u, int v, int texW, int texH, bool temporary)
        {
            using sig = void (*)(Mesh *, Sprite *, MinecraftGame *, int, int, int, int, TexturePtr &, int, int, int, int, bool);
            sig(0x55FC28)(this, p1, minecraftGame, x, y, w, h, texturePtr, u, v, texW, texH, temporary);
        }

        ~Mesh()
        {
            reinterpret_cast<Mesh *(*)(Mesh *)>(0x509214)(this);
        }

        void render(MaterialPtr &materialPtr, int startOffset, int count)
        {
            reinterpret_cast<void (*)(Mesh *, MaterialPtr &, int, int)>(0x7177C0)(this, materialPtr, startOffset, count);
        }

        Mesh &operator=(Mesh &&other)
        {
            return reinterpret_cast<Mesh &(*)(Mesh *, Mesh &&)>(0x509284)(this, std::move(other));
        }

        void render(MaterialPtr &materialPtr, TexturePtr &texturePtr, int startOffset, int count)
        {
            reinterpret_cast<void (*)(Mesh *, MaterialPtr &, TexturePtr &, int, int)>(0x717658)(this, materialPtr, texturePtr, startOffset, count);
        }

    private:
        gstd::type_unknown<100> todo;
    };
}    // namespace MC3DSPluginFramework