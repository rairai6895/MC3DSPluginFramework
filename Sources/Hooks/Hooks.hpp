#pragma once

#include "Asterium/AstHook/AstHook.hpp"
#include "Minecraft/Common/World/Level/BlockPos.hpp"
#include "Minecraft/gctr/gctr.hpp"
#include <thread>

namespace MC3DSPluginFramework
{
    class Dimension;
    class BaseButton;
    class MinecraftGame;

    class Hooks
    {
    public:
        // PatchProcessで呼んでください
        static void install();

        static void pushPluginThreadId(std::thread::id id);
        static void erasePluginThreadId(std::thread::id id);
        static bool isPluginThread(std::thread::id id);

    private:
        static inline std::vector<std::thread::id> mPluginThreads;

        static inline Asterium::AstHook MainHook;
        static inline Asterium::AstHook RegisterNbtTagsHook;
        static inline Asterium::AstHook ShaderUpdateSkipHook;
        static inline Asterium::AstHook CreativeMenu_registerMenuItemsHook;
        static inline Asterium::AstHook Recipes_registerRecipesHook;

        static void Main();
        static void RegisterNbtTags(Regs &, u32 *, Asterium::AstHook *);
        static void ShaderUpdateSkip(Dimension *, const BlockPos &);
        static bool BaseButton_onTouchRelease(BaseButton *, MinecraftGame *, int, int);
        static void CreativeMenu_registerMenuItems();
        static void Recipes_registerRecipes(Regs &, u32 *, Asterium::AstHook *);
    };

}    // namespace MC3DSPluginFramework