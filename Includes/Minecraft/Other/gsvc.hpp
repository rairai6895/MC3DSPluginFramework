#pragma once

#include <3ds.h>

namespace MC3DSPluginFramework {
namespace gsvc {

static inline Handle &Thread_Handle = *(Handle *)0x919548;

inline Result CreateThread(Handle *thread, ThreadFunc entrypoint, u32 arg, u32 *stack_top, s32 thread_priority, s32 processor_id) {
    return reinterpret_cast<Result (*)(Handle *, ThreadFunc, u32, u32 *, s32, s32)>(0x10F20C)(thread, entrypoint, arg, stack_top, thread_priority, processor_id);
}

// 0xA
inline void SleepThread(s64 nanoseconds) {
    reinterpret_cast<void (*)(s64)>(0x125BCC)(nanoseconds);
}

// 0x22
inline Result ArbitrateAddress(Handle arbiter, u32 addr, ArbitrationType type, s32 value, s64 nanoseconds) {
    return reinterpret_cast<Result (*)(Handle, u32, ArbitrationType, s32, s64)>(0x125BA8)(arbiter, addr, type, value, nanoseconds);
}

// 0x35
inline Result GetProcessId(u32 *out, Handle process) {
    return reinterpret_cast<Result (*)(u32 *, Handle)>(0x121618)(out, process);
}

// 0x37
inline Result GetThreadId(u32 *out, Handle handle) {
    return reinterpret_cast<Result (*)(u32 *, Handle)>(0x121630)(out, handle);
}

// 0x3C
inline void Break(UserBreakType breakReason) {
    reinterpret_cast<void (*)(UserBreakType)>(0x125BC0)(breakReason);
}

}    // namespace gsvc
}    // namespace MC3DSPluginFramework