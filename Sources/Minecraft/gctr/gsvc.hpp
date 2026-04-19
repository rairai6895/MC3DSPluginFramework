#pragma once

#include <3ds/svc.h>

namespace MC3DSPluginFramework::gsvc
{
    inline Handle &Thread_Handle = *(Handle *)0x919548;

    inline Result CreateThread(Handle *thread, ThreadFunc entrypoint, u32 arg, u32 *stack_top, int32_t thread_priority, int32_t processor_id)
    {
        return reinterpret_cast<Result (*)(Handle *, ThreadFunc, u32, u32 *, int32_t, int32_t)>(0x10F20C)(thread, entrypoint, arg, stack_top, thread_priority, processor_id);
    }

    // 0xA
    inline void SleepThread(int64_t nanoseconds)
    {
        reinterpret_cast<void (*)(int64_t)>(0x125BCC)(nanoseconds);
    }

    // 0x22
    inline Result ArbitrateAddress(Handle arbiter, u32 addr, ArbitrationType type, int32_t value, int64_t nanoseconds)
    {
        return reinterpret_cast<Result (*)(Handle, u32, ArbitrationType, int32_t, int64_t)>(0x125BA8)(arbiter, addr, type, value, nanoseconds);
    }

    inline Result ConnectToPort(Handle *out, const char *portName)
    {
        return reinterpret_cast<Result (*)(Handle *, const char *)>(0x118E28)(out, portName);
    }

    // 0x35
    inline Result GetProcessId(u32 *out, Handle process)
    {
        return reinterpret_cast<Result (*)(u32 *, Handle)>(0x121618)(out, process);
    }

    // 0x37
    inline Result GetThreadId(u32 *out, Handle handle)
    {
        return reinterpret_cast<Result (*)(u32 *, Handle)>(0x121630)(out, handle);
    }

    // 0x3C
    inline void Break(UserBreakType breakReason)
    {
        reinterpret_cast<void (*)(UserBreakType)>(0x125BC0)(breakReason);
    }

}    // namespace MC3DSPluginFramework::gsvc