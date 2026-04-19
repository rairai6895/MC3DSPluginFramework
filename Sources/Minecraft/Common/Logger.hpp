#pragma once

// #define LOGGER_ON

#ifdef LOGGER_ON
#define LOG(msg, condition, unk) \
    reinterpret_cast<void (*)(const char *, const char *, int, int, const char *, const char *)>(0x144474)(msg, #condition, unk, __LINE__, __FILE__, __func__)
#define LOG_V(unk1, level, fmt, args...) \
    reinterpret_cast<void (*)(int, LogLevel, const char *, int, const char *, ...)>(0x114F50)(unk1, level, __func__, __LINE__, fmt, args)
#else
#define LOG(msg, condition, unk)
#define LOG_V(unk1, level, fmt, args...)
#endif

namespace MC3DSPluginFramework
{
    enum class LogLevel {
        Notice  = 1 << 0,
        Info    = 1 << 1,
        Warning = 1 << 2,
        Error   = 1 << 3,
    };
}    // namespace MC3DSPluginFramework
