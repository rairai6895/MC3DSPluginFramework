#pragma once

#include "Attribute.hpp"

namespace MC3DSPluginFramework
{
    // "C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\src\\common\\world\\attribute\\AttributeInstance.cpp"
    class AttributeInstance
    {
    public:
        virtual ~AttributeInstance();
        virtual void Unknown1();
        virtual void Unknown2();
        virtual void Unknown3();

    private:
        gstd::map<gstd::string, AttributeInstance> *mParent;
        Attribute *mKey;
        gstd::vector<u32> vec1;    // 謎
        gstd::vector<u32> vec2;    // 謎
        gstd::vector<u32> vec3;    // 謎
        Util::BoxedPtr::Shared<void *> mUnk1;    // テンプレートっぽい
        u32 mUnk2;    // 0
        float mFakeMaxValue;
        float mFakeCurrentValue;
        u32 mUnk3;    // 0

    public:
        float MaxValue;
        float CurrentValue;
    };
}    // namespace MC3DSPluginFramework