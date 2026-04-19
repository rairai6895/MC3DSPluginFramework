#pragma once

#include "Minecraft/Common/Logger.hpp"

namespace MC3DSPluginFramework::Util
{
    // "C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\project\\3DS\\..\\..\\src-deps\\Core/Utility/Singleton.h"
    template <typename T>
    class Singleton
    {
    public:
        Singleton()
        {
            if (mInstance)
                LOG("You attempted to create a singleton where one already exists", , 0);
        }

        static bool createInstance()
        {
            if (!mInstance)
            {
                T *newInstance = new T();
                T *oldInstance = mInstance;

                mInstance = newInstance;

                if (oldInstance)
                    delete oldInstance;

                return true;
            }

            return false;
        }

        static void deleteInstance()
        {
            if (mInstance)
                delete mInstance;
        }

        static T &getInstance()
        {
            if (!mInstance)
                LOG("The singleton instance doesn't exist", , 0);

            return *mInstance;
        }

    private:
        static inline T *mInstance = nullptr;
    };
}    // namespace MC3DSPluginFramework::Util