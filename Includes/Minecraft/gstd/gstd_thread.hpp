#pragma once

#include <thread>

namespace MC3DSPluginFramework::gstd {
namespace thread {

using id = std::thread::id;

}

namespace this_thread {

inline gstd::thread::id get_id(void) {
    return reinterpret_cast<std::thread::id (*)()>(0x123468)();
}

}    // namespace this_thread
}    // namespace MC3DSPluginFramework::gstd