#include "MaterialPtr.hpp"
#include "Minecraft/Common/Client/Renderer/Renderer/RenderMaterialGroup.hpp"

namespace MC3DSPluginFramework
{
    // FUN_0x4F149C
    MaterialPtr::MaterialPtr(RenderMaterialGroup *renderMaterialGroup, gstd::string name) :
        mRenderMaterialGroup(renderMaterialGroup),
        mPtr(nullptr),
        mName(name)
    {
        renderMaterialGroup->_addRef(*this);
        onGroupReloaded();
    }

    // FUN_0x4F153C
    MaterialPtr::~MaterialPtr()
    {
        _deref();
    }

    void MaterialPtr::_deref()
    {
        if (mRenderMaterialGroup)
        {
            mRenderMaterialGroup->_removeRef(*this);
            mRenderMaterialGroup = nullptr;
        }

        mPtr = nullptr;
    }

    // FUN_0x4F0DFC
    void MaterialPtr::onGroupReloaded()
    {
        // ゲーム内にはmRenderMaterialGroupがnullptrの場合ログを出す処理がある

        mPtr = mRenderMaterialGroup->_getMaterial(mName);
    }

    // FUN_0x4F1574
    MaterialPtr &MaterialPtr::operator=(MaterialPtr &&other)
    {
        this->mRenderMaterialGroup = other.mRenderMaterialGroup;
        this->mPtr                 = other.mPtr;
        this->mName                = other.mName;

        other._deref();
        this->mRenderMaterialGroup->_addRef(*this);

        return *this;
    }
}    // namespace MC3DSPluginFramework