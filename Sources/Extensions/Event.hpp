#pragma once

#include "Helpers/Macro.hpp"
#include <cstdint>

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
        inline uint64_t States = 0;
    }    // namespace Event

}    // namespace MC3DSPluginFramework