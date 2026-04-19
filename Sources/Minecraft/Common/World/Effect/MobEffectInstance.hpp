#pragma once

#include "Minecraft/Common/Logger.hpp"
#include "Minecraft/Common/World/Entity/Effects.hpp"
#include <cstdint>

namespace MC3DSPluginFramework
{
    // "C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\src\\common\\world\\effect\\MobEffectInstance.cpp"
    class MobEffectInstance
    {
    public:
        // FUN_0x36B9D0
        MobEffectInstance(int id, int time, int level) :
            mId(id),
            mTime(time),
            mLevel(level),
            m0xC(0),
            m0xD(0),
            m0xE(1)
        {
        }

        bool isType(const Effect &type) const
        {
            return mId == type.getId();
        }

        // FUN_0x36B894
        void update(const MobEffectInstance &takeOver)
        {
            if (!(mId == takeOver.mId))
                LOG("This method should only be called for matching effects!", mId == takeOver.mId, 0);

            if (mLevel < takeOver.mLevel)
            {
                mLevel = takeOver.mLevel;
                mTime  = takeOver.mTime;
            }
            else if ((takeOver.mLevel == mLevel) && (mTime < takeOver.mTime))
            {
                mTime = takeOver.mTime;
            }
            else if (!takeOver.m0xC && m0xC)
            {
                m0xC = 0;
            }

            m0xE = takeOver.m0xE;
        }

    private:
        int mId;    // +0x0
        int mTime;    // +0x4
        int mLevel;    // +0x8
        u8  m0xC;
        u8  m0xD;
        u8  m0xE;
    };
}    // namespace MC3DSPluginFramework