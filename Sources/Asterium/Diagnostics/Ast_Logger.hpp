#pragma once

#include <CTRPluginFramework.hpp>

namespace Asterium
{
    namespace CTRPF = CTRPluginFramework;

    class Logger
    {
    public:
        Logger(const char *path) :
            mPath(path)
        {
            if (!CTRPF::File::Exists(mPath))
                CTRPF::File::Create(mPath);

            CTRPF::File::Open(mFile, mPath);
            mFile.Seek(0, CTRPF::File::SeekPos::END);
        }

        void write(const std::string &line)
        {
            if (mFile.IsOpen())
                mFile.WriteLine(line);
        }

        void clear()
        {
            if (mFile.IsOpen())
                mFile.Clear();
        }

    private:
        std::string mPath;
        CTRPF::File mFile;
    };
}    // namespace Asterium