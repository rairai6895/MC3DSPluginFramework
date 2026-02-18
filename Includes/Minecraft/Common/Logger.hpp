#pragma once

#define LOG(msg, condition, unk) \
    reinterpret_cast<void (*)(const char *, const char *, u32, u32, const char *, const char *)>(0x144474)(msg, #condition, unk, __LINE__, __FILE__, __func__)

namespace MC3DSPluginFramework
{
    class Logger
    {
    public:
    private:
    };
}    // namespace MC3DSPluginFramework
