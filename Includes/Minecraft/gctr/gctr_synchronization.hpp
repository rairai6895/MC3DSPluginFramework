#pragma once

#include "Minecraft/Other/gsvc.hpp"

namespace MC3DSPluginFramework::gctr {

class LightLock {
  public:
    LightLock();

    void lock(void);
    void unlock(void);

  private:
    s32 mState;
};

class RecursiveLock {
  public:
    RecursiveLock();

    void lock(void);
    void unlock(void);

    bool isLocked(void);

  private:
    LightLock mLock;
    u32 mThread_tag;
    u32 mCounter;
};

}    // namespace MC3DSPluginFramework::gctr