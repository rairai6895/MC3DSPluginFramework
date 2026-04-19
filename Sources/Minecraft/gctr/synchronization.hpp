#pragma once

#include <types.h>

namespace MC3DSPluginFramework::gctr
{

    class LightLock
    {
    public:
        LightLock();

        void lock();
        void unlock();

    private:
        int32_t mState;
    };

    class RecursiveLock
    {
    public:
        RecursiveLock();

        void lock();
        void unlock();

        bool isLocked();

    private:
        LightLock mLock;
        u32       mThread_tag;
        u32       mCounter;
    };

}    // namespace MC3DSPluginFramework::gctr