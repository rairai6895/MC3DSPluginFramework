#include "ResourceLoader.hpp"

namespace MC3DSPluginFramework
{
    // FUN_0x289114
    ResourceLoader::ResourceLoader(const char *path)
    {
        mPath = (path ? gstd::strdup(path) : nullptr);
    }

    // FUN_0x28914C
    // +0x0
    ResourceLoader::~ResourceLoader()
    {
        if (mPath)
            gstd::free(mPath);
    }

    // FUN_0x6CF8F8
    // +0xC
    const char *ResourceLoader::getPath()
    {
        return mPath;
    }

}    // namespace MC3DSPluginFramework