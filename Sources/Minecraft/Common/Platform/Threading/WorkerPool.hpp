#pragma once

namespace MC3DSPluginFramework
{
    // "C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\src\\common\\platform\\threading\\WorkerPool.cpp"
    class WorkerPool
    {
    public:
        static void start(int i)
        {
            reinterpret_cast<void (*)(int)>(0x10901C)(i);
        }

    private:
        static void *mInstance;
    };
}    // namespace MC3DSPluginFramework