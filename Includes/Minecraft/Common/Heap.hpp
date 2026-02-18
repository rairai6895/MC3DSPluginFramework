#pragma once

#include "HookEx/HookEx.hpp"
#include "Minecraft/gctr/gctr_synchronization.hpp"
#include <CTRPluginFramework/System/Process.hpp>
#include <types.h>

namespace MC3DSPluginFramework
{
    class Heap
    {
    public:
        enum class Type {
            CTR,
            Default,
            Unknown,
        };

        static void *alloc(size_t size, Type type, u32 unk1, u32 unk2)
        {
            // 0x1010CA | 1
            // 0x2FEEB0 -> 0x11494C
            // 0x2FF4EC -> 0x2FEEB0
            // 0x2FE9F0 -> 0x2FF4EC

            return reinterpret_cast<void *(*)(size_t, Type, u32, u32)>(0x11494C)(size, type, unk1, unk2);
        }

        static void InstallDeadlockFixHook()
        {
            static HookEx hook;

            if (!hook.IsEnabled()) {
                hook.InitMitm(0x11494C, (u32)DeadlockFixCallback);
                hook.Enable();
            }
        }

    private:
        static void *DeadlockFixCallback(size_t size, Type type, u32 param3, u32 param4)
        {
            bool paused = CTRPluginFramework::Process::IsPaused();

            // 不正なTypeを弾く
            if (type != Type::Default && type != Type::Unknown)
                type = Type::CTR;

            while (true) {
                if (*(u8 *)0xA30D09)
                    type = Type::CTR;

                // 本当にアロケーターかは分からない
                u32 allocator = **(u32 **)(0x919558 + (u8)type * 4);

                if (type == Type::Unknown && size < 0x2801) {
                    allocator = *(u32 *)0xA30D20;
                }

                gctr::RecursiveLock *lock = (gctr::RecursiveLock *)(allocator + 0x58);

                if (!paused)
                    lock->lock();

                void *res = reinterpret_cast<void *(*)(u32, size_t, u32, u32, u32, u32)>(0x10BA88)(allocator, size, param3, param4, 0, 0);

                if (!paused)
                    lock->unlock();

                if (res != 0)
                    return res;

                if (allocator == *(u32 *)0xA30D20) {
                    allocator = **(u32 **)(0x919558 + (u8)type * 4);
                    lock      = (gctr::RecursiveLock *)(allocator + 0x58);

                    if (!paused)
                        lock->lock();

                    res = reinterpret_cast<void *(*)(u32, size_t, u32, u32, u32, u32)>(0x10BA88)(allocator, size, param3, param4, 0, 0);

                    if (!paused)
                        lock->unlock();

                    if (res != 0)
                        return res;
                }

                if (type != Type::Default)
                    break;

                type = Type::Unknown;
            }

            if (0x17FFFF < size || *(u32 *)0xA30D08 != 0)
                *(u32 *)nullptr = 0;

            if (*(u8 *)0xA30D08 = 1, *(u32 *)0xA30D0C == 0)
                *(u32 *)nullptr = 0;

            return 0;
        }
    };
}    // namespace MC3DSPluginFramework