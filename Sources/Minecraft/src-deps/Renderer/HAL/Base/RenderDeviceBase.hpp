#pragma once

namespace MC3DSPluginFramework::HAL::Base
{
    // "C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\src-deps\\Renderer\\HAL\\Base\\RenderDeviceBase.cpp"
    class RenderDeviceBase
    {
    public:
        static void *getRenderContext()
        {
            return reinterpret_cast<void *(*)()>(0x12E87C)();
        }

    private:
    };
}    // namespace MC3DSPluginFramework::HAL::Base