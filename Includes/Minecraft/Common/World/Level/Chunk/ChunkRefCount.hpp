#pragma once

#include "Minecraft/Common/Logger.hpp"
#include "Minecraft/Common/Thread.hpp"
#include "Minecraft/gstd/gstd.hpp"

namespace MC3DSPluginFramework
{
    // "C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\src\\common\\world\\level\\chunk\\ChunkRefCount.cpp"
    class ChunkRefCount
    {
    public:
        // FUN_0x206E10
        int grab()
        {
            if (!(gstd::this_thread::get_id() == gMainThread))
                LOG("This code should only be executed on the main thread", gstd::this_thread::get_id() == gMainThread, 0);

            mRefCount++;
            return mUnk1;
        }

        // FUN_0x206EE4
        void release()
        {
            if (!(gstd::this_thread::get_id() == gMainThread))
                LOG("This code should only be executed on the main thread", gstd::this_thread::get_id() == gMainThread, 0);

            if (!(mRefCount > 0))
                LOG("Releasing an already released chunk", mRefCount > 0, 0);

            mRefCount--;
        }

    private:
        int mRefCount;
        u32 mUnk1;
    };
}    // namespace MC3DSPluginFramework