#pragma once

#include "Minecraft/gstd/gstd_alloc.hpp"

namespace MC3DSPluginFramework::gstd {
class type_unknown {
  public:
    type_unknown() = default;

    void *operator new(size_t s) { return malloc(s); }
    void operator delete(void *m) { free(m); }

  private:
};
}    // namespace MC3DSPluginFramework