#pragma once

#include <types.h>

namespace MC3DSPluginFramework
{
    class BackGroundWorker
    {
    public:
        void sync()
        {
            reinterpret_cast<void (*)(BackGroundWorker *)>(0x107D6C)(this);
        }

    private:
        u32 mAsync;
    };
}    // namespace MC3DSPluginFramework