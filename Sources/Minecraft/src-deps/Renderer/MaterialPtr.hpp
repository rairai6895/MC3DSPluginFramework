#pragma once

#include "Minecraft/gstd/gstd.hpp"

namespace MC3DSPluginFramework
{
    class RenderMaterialGroup;
    class RenderMaterial;

    // "C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\project\\3DS\\systems\\Renderer\\Renderer.3DS\\..\\..\\..\\..\\..\\src-deps\\Renderer/MaterialPtr.h"
    // "C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\src-deps\\Renderer\\MaterialPtr.cpp"
    class MaterialPtr
    {
    public:
        MaterialPtr(RenderMaterialGroup *renderMaterialGroup, gstd::string name);
        ~MaterialPtr();

        void         _deref();
        void         onGroupReloaded();
        MaterialPtr &operator=(MaterialPtr &&other);

    private:
        RenderMaterialGroup *mRenderMaterialGroup;    // +0x0
        RenderMaterial      *mPtr;    // +0+4
        gstd::string         mName;    // +0x8
    };
}    // namespace MC3DSPluginFramework