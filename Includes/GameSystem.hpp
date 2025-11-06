#ifndef GAMESYSTEM_HPP
#define GAMESYSTEM_HPP

#include "Function.hpp"
#include "gstd.hpp"

namespace MC3DSPluginFramework {

class GameSystem {
  public:
    static inline bool IsLoaded(void) {
        return Function<bool>(0x44907C)();
    }

    static inline GameSystem *GetInstance(void) {
        return Function<GameSystem *>(0x444CA0)();
    }

    inline u32 Offset(u32 offset = 0) {
        return (u32)this + offset;
    }

    inline u32 GetOptions_txt(void) {
        return *(u32 *)((*(gstd::vector<u32> *)((**(u32 **)(*(u32 *)((u32)this + 8) + 0x1A0)) + 4))[0] + 4);
    }

    inline u32 GetController(void) {
        return *(u32 *)(Function<u32>(0x12AAD4)(*(u32 *)Offset(0xC)) + 0x14);
    }

    inline bool IsPaused(void) {
        return !Function<bool>(0x6C734C)(*(u32 *)Offset(0xC));
    }

    // FUN_0x251158
    inline void Pause(void) {
        if (!IsPaused()) {
            u32 param = Function<u32>(0x6C13E8)(*(u32 *)Offset(0xC));
            Function<void>(0x23B758)(param);
        }
    }

    inline gstd::vector<void *> &GetRenderData(void) {
        return **(gstd::vector<void *> **)(*(u32 *)Offset(0x8) + 0x6C);
    }
};

}    // namespace MC3DSPluginFramework

#endif