#pragma once

#include "gstd_alloc.hpp"
#include "gstd_map.hpp"
#include "gstd_reference_ptr.hpp"
#include "gstd_string.hpp"
#include "gstd_temporary_ptr.hpp"
#include "gstd_thread.hpp"
#include "gstd_type_unknown.hpp"
#include "gstd_unique_ptr.hpp"
#include "gstd_vector.hpp"
#include <3ds.h>
#include <stdarg.h>

namespace MC3DSPluginFramework::gstd
{

    NORETURN inline void crash(void)
    {
        *(volatile u32 *)nullptr = 0;
        for (;;)
            ;
    }

    inline bool isheap(void *memory)
    {
        return ((u32)memory >= 0x30000000 && (u32)memory <= 0x3697F000);
    }

    inline void *memcpy(void *dest, const void *src, size_t size)
    {
        return reinterpret_cast<void *(*)(void *, const void *, size_t)>(0x12CE5C)(dest, src, size);
    }

    inline void *fast_memcpy(void *dest, const void *src, size_t size)
    {
        return reinterpret_cast<void *(*)(void *, const void *, size_t)>(0x3001D0)(dest, src, size);
    }

    inline char *fast_strcpy(char *dest, const char *src)
    {
        return reinterpret_cast<char *(*)(char *, const char *)>(0x2FE9F8)(dest, src);
    }

    inline NAKED int snprintf(char *buffer, size_t size, const char *fmt, ...)
    {
        asm volatile("ldr pc, =0x1000C1 \n");
    }

    inline int vsnprintf(char *buffer, size_t size, const char *fmt, va_list vals)
    {
        return reinterpret_cast<int (*)(char *, size_t, const char *, va_list)>(0x100120 | 1)(buffer, size, fmt, vals);
    }

    inline char *vasprintf(char *buffer, size_t size, const char *fmt, va_list vals)
    {
        // buffer == nullptr なら自動確保
        // size == 0 なら0x40になる
        return reinterpret_cast<char *(*)(char *, size_t, const char *, va_list)>(0x2FE938 | 1)(buffer, size, fmt, vals);
    }

    inline int to_int(char c, size_t max)
    {
        // -1 error
        // 'A' = 10
        // '8' = 8
        return reinterpret_cast<int (*)(char, size_t)>(0x2FE6A8 | 1)(c, max);
    }

    inline unsigned long strtoul(const char *str, char **end, int base)
    {
        return reinterpret_cast<long (*)(const char *, char **, int)>(0x2FE5F4 | 1)(str, end, base);
    }

    inline long strtol(const char *str, char **end, int base)
    {
        return reinterpret_cast<long (*)(const char *, char **, int)>(0x100048 | 1)(str, end, base);
    }

    inline void localtime(time_t *time)
    {
        reinterpret_cast<void (*)(time_t *)>(0x118F7C)(time);
    }

    inline gstd::string to_string(float value)
    {
        return reinterpret_cast<gstd::string (*)(float)>(0x11DA74)(value);
    }

    inline float truncf(float value)
    {
        return reinterpret_cast<float (*)(float)>(0x74F240)(value);
    }

    // FUN_0x10F494
    inline char *strdup(const char *src)
    {
        if (!src)
            return nullptr;

        char *result = reinterpret_cast<char *>(malloc(strlen(src) + 1));
        fast_strcpy(result, src);

        return result;
    }

}    // namespace MC3DSPluginFramework::gstd