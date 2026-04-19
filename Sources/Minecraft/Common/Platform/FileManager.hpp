#pragma once

#include "Minecraft/gstd/gstd.hpp"

namespace MC3DSPluginFramework::FileManager
{
    enum Flag {
        Read  = 1,
        Write = 2,
    };

    struct Directory
    {
        Handle   handle;    // nn::fs 多分ポインタ
        wchar_t *path;    // L"extdata://name/"
        u32      flag;
    };

    struct File
    {
        Handle   handle;    // nn::fs
        wchar_t *path;    // L"extdata:/name/"
        u32      flag;
    };

    // extdata:/
    Result _TryCreateFile(const wchar_t *path, u32 unknown1, size_t size, u32 unknown2)
    {
        return reinterpret_cast<Result (*)(const wchar_t *, u32, size_t, u32)>(0x4AC6E8)(path, unknown1, size, unknown2);
    }

    // folder = L"extdata:/folderName"
    Result _TryCreateDirectory(const wchar_t *path)
    {
        return reinterpret_cast<Result (*)(const wchar_t *)>(0x1328D0)(path);
    }

    // target = L"extdata:/target"
    // newName = L"extdata:/newName"
    Result _TryRenameFile(const wchar_t *target, const wchar_t *newName)
    {
        return reinterpret_cast<Result (*)(const wchar_t *, const wchar_t *)>(0x4AC7D0)(target, newName);
    }

    Result _TryInitialize(File &f)
    {
        return reinterpret_cast<Result (*)(File &, const wchar_t *, u32)>(0x1226FC)(f, f.path, f.flag);
    }

    Result _TryInitialize(Directory &d)
    {
        return reinterpret_cast<Result (*)(Directory &, const wchar_t *, u32)>(0x132844)(d, d.path, d.flag);
    }

    class Wrap
    {
    public:
        // format = header:text
        struct Line
        {
            gstd::string mHeader;    // key?
            gstd::string mText;
        };

        static void write(const gstd::string &file, const gstd::vector<Line> line)
        {
            reinterpret_cast<void (*)(const gstd::string &, const gstd::vector<Line>)>(0x1DFFAC)(file, line);
        }
    };
}    // namespace MC3DSPluginFramework::FileManager