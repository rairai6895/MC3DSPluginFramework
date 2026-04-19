#include "RenderMaterialGroup.hpp"
#include "Minecraft/Common/Util/StringUtils.hpp"

namespace MC3DSPluginFramework
{
    void RenderMaterialGroup::_removeRef(MaterialPtr &materialPtr)
    {
        reinterpret_cast<void (*)(RenderMaterialGroup *, MaterialPtr &)>(0x4FFE54)(this, materialPtr);
    }

    void RenderMaterialGroup::_addRef(MaterialPtr &materialPtr)
    {
        reinterpret_cast<void (*)(RenderMaterialGroup *, MaterialPtr &)>(0x500B38)(this, materialPtr);
    }

    // FUN_0x716090
    RenderMaterial *RenderMaterialGroup::_getMaterialPtr(gstd::string name)
    {
        return mMaterials.find(Util::hashCode(name.c_str()))->second;
    }

    // FUN_0x715F10
    RenderMaterial *RenderMaterialGroup::_getMaterial(gstd::string name)
    {
        return _getMaterialPtr(name);
        // ゲーム内にはnullptrの場合ログを出す処理がある
    }
}    // namespace MC3DSPluginFramework