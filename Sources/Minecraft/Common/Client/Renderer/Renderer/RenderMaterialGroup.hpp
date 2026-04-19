#pragma once

#include "Minecraft/Common/Platform/AppPlatformListener.hpp"
#include "Minecraft/gstd/gstd.hpp"

namespace MC3DSPluginFramework
{
    class MaterialPtr;
    class RenderMaterial;

    // "C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\src\\common\\client\\renderer\\renderer\\RenderMaterialGroup.cpp"
    class RenderMaterialGroup : public AppPlatformListener
    {
    public:
        void            _removeRef(MaterialPtr &materialPtr);
        void            _addRef(MaterialPtr &materialPtr);
        RenderMaterial *_getMaterialPtr(gstd::string name);
        RenderMaterial *_getMaterial(gstd::string name);

    private:
        gstd::map<u32, RenderMaterial *> mMaterials;
        //...
    };
}    // namespace MC3DSPluginFramework