#pragma once

#include "Minecraft/gstd/gstd.hpp"

namespace MC3DSPluginFramework {
class FileManager {
    enum class Flag {
        Read  = 1,
        Write = 2,
    };

    struct Directory {
        u32 handle;       // nn::fs
        wchar_t *path;    // L"extdata://name/"
        u32 flag;
    };

    struct File {
        u32 handle;       // nn::fs
        wchar_t *path;    // L"extdata:/name/"
        u32 flag;
    };

    // extdata:/
    u32 tryCreateFile(const wchar_t *file, u32 unknown1, u32 size, u32 unknown2) {
        return reinterpret_cast<u32 (*)(const wchar_t *, u32, u32, u32)>(0x4AC6E8)(file, unknown1, size, unknown2);
    }

    // folder = L"extdata:/folderName"
    u32 tryCreateDirectory(const wchar_t *folder) {
        return reinterpret_cast<u32 (*)(const wchar_t *)>(0x1328D0)(folder);
    }

    // target = L"extdata:/target"
    // newName = L"extdata:/newName"
    u32 tryRenameFile(const wchar_t *target, const wchar_t *newName) {
        return reinterpret_cast<u32 (*)(const wchar_t *, const wchar_t *)>(0x4AC7D0)(target, newName);
    }

    u32 tryInitialize(File &f) {
        return reinterpret_cast<u32 (*)(u32 *, const wchar_t *, u32)>(0x1226FC)(&f.handle, f.path, f.flag);
    }

    u32 tryInitialize(Directory &d) {
        return reinterpret_cast<u32 (*)(u32 *, const wchar_t *, u32)>(0x132844)(&d.handle, d.path, d.flag);
    }

    class Wrap {
      public:
        // format = header:text
        struct Line {
            gstd::string mHeader;    // key?
            gstd::string mText;
        };

        static void write(const gstd::string &file, const gstd::vector<Line> line) {
            reinterpret_cast<void (*)(const gstd::string &, const gstd::vector<Line>)>(0x1DFFAC)(file, line);
        }
    };
};
}    // namespace MC3DSPluginFramework