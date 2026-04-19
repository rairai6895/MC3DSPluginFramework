#pragma once

#include "Minecraft/gstd/gstd.hpp"

// "C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\src\\common\\platform\\file.cpp"
namespace MC3DSPluginFramework::file
{

    // extdata:/name
    bool deleteDirectory(gstd::string path)
    {
        return reinterpret_cast<bool (*)(gstd::string)>(0x55AF6C)(path);
    }

    // フォルダーの中にしか作れないっぽい
    // extdata:/a/b
    bool _createOneFolder(gstd::string path)
    {
        return reinterpret_cast<bool (*)(gstd::string)>(0x114AB0)(path);
    }

}    // namespace MC3DSPluginFramework::file