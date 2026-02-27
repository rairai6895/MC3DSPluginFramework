#pragma once

#include "Extensions/Event.hpp"
#include "Extensions/GameScheduler.hpp"
#include "Helpers/Macro.hpp"
#include "HookEx/HookEx.hpp"
#include "Minecraft/Common/Client/Game/MinecraftGame.hpp"
#include "Minecraft/Common/NBT/Tag.hpp"
#include "Minecraft/gctr/gctr_synchronization.hpp"
#include <CTRPluginFramework/System/Process.hpp>

namespace MC3DSPluginFramework
{
    class Hooks
    {
    public:
        // PatchProcessで呼んでください
        static void install();

        static void pushPluginThreadId(std::thread::id id);
        static void erasePluginThreadId(std::thread::id id);
        static bool isPluginThread(std::thread::id id);

    private:
        static std::vector<std::thread::id> mPluginThreads;

        static HookEx mMain;
        static HookEx mRegisterNbtTags;
        static HookEx mShaderUpdateSkip;
        static HookEx mMallocDeadlockFix;

        static void mainCallback();
        static void registerNbtTagsCallback(Regs &regs, u32 *sp, HookEx *hook);
        static void shaderUpdateSkipCallback(Dimension *_this, const BlockPos &pos);
        static void *mallocDeadlockFixCallback(size_t size, Heap::Type type, u32 param3, u32 param4);
    };

}    // namespace MC3DSPluginFramework