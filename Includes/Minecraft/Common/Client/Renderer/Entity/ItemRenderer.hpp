#pragma once

namespace MC3DSPluginFramework {
// "C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\src\\common\\client\\renderer\\entity\\ItemRenderer.cpp"
class ItemRenderer {
  public:
    // FUN_0x1D2E04
    static ItemRenderer *getInstance(void) { return instance; }

  private:
    static inline ItemRenderer *&instance = *(ItemRenderer **)0xA32288;
};
}    // namespace MC3DSPluginFramework