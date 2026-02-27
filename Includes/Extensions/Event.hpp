#pragma once

#include <types.h>

namespace MC3DSPluginFramework
{

    namespace EventStates
    {
        enum {
            RegisteredNbtTags = 1 << 0,
        };
    }    // namespace EventStates

    namespace Event
    {
        inline u64 States = 0;
    }

}    // namespace MC3DSPluginFramework