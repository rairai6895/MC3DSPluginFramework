#pragma once

#include "Attribute.hpp"

namespace MC3DSPluginFramework
{
    // "C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\src\\common\\world\\attribute\\AttributeInstance.cpp"
    class AttributeInstance
    {
        USE_GAME_ALLOCATOR
    public:
        static inline AttributeInstance &NULL_INSTANCE = *(AttributeInstance *)0xB08A7C;

        AttributeInstance(const gstd::map<gstd::string, AttributeInstance> *parent, const Attribute *attribute)
        {

            mParent    = parent;
            mAttribute = attribute;

            mDefaultValues[0] = 0;
            mDefaultValues[1] = std::numeric_limits<float>::max();
            mDefaultValues[2] = 0;
            mValues[0]        = 0;
            mValues[1]        = std::numeric_limits<float>::max();
            mValues[2]        = 0;
        }

        virtual ~AttributeInstance();
        virtual void Unknown1();
        virtual void Unknown2();
        virtual void Unknown3();

        // FUN_0x6E6768
        float getDefaultValue(u32 idx)
        {
            if (idx > 2)
                LOG("Invalid Operand", , 0);

            return mDefaultValues[idx];
        }

        float getValue(u32 idx)
        {
            if (idx > 2)
                LOG("Invalid Operand", , 0);

            return mValues[idx];
        }

        void setCurrentValue(float set)
        {
            mValues[2] = set;
        }

        float getCurrentValue()
        {
            return mValues[2];
        }

        void setValue(u32 idx, float set)
        {
            if (idx > 2)
                LOG("Invalid Operand", , 0);

            mValues[idx] = set;
        }

    private:
        // 0x9B6470

        const gstd::map<gstd::string, AttributeInstance> *mParent;    // +0x4
        const Attribute                                  *mAttribute;    // +0x8
        gstd::vector<gstd::type_unknown<>>                vec1;    // +0xC
        gstd::vector<gstd::type_unknown<>>                vec2;    // +0x18
        gstd::vector<gstd::type_unknown<>>                vec3;    // +0x24
        BoxedPtr::Shared<gstd::type_unknown<0x14>>        mUnk1;    // +0x30
        float                                             mDefaultValues[3];    // +0x38
        float                                             mValues[3];    // +0x44
    };
}    // namespace MC3DSPluginFramework