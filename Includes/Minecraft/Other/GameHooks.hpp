#pragma once

#include "HookEx/HookEx.hpp"
#include "Minecraft/Common/NBT/Tag.hpp"
#include "Minecraft/gctr/gctr_synchronization.hpp"
#include <CTRPluginFramework/System/Process.hpp>

namespace MC3DSPluginFramework
{
    namespace GameHooks
    {

        inline void ctr_mainCallback(Regs &regs, u32 *sp, HookEx *hook)
        {
        }

        static u32 pluginThreadId;
        inline void shaderUpdateSkipCallback(u32 param1, u32 param2)
        {
            u32 callThreadId;
            svcGetThreadId(&callThreadId, CUR_THREAD_HANDLE);

            if (callThreadId == pluginThreadId)
                return;

            if (param1 = *(u32 *)(param1 + 0x13C))
                reinterpret_cast<void (*)(u32, u32)>(0x4523E4)(param1, param2);
        }

        inline void assertHandlerCallback(Regs &regs, u32 *sp, HookEx *hook)
        {
            gstd::string error(*(gstd::string *)regs.r0);
        }

        inline void registerNbtTagsCallback(Regs &regs, u32 *sp, HookEx *hook)
        {
            Tag::RepairCost          = "RepairCost",
            Tag::BlockEntityTag      = "BlockEntityTag",
            Tag::EntityId            = "EntityId",
            Tag::Delay               = "Delay",
            Tag::MinSpawnDelay       = "MinSpawnDelay",
            Tag::MaxSpawnDelay       = "MaxSpawnDelay",
            Tag::SpawnCount          = "SpawnCount",
            Tag::MaxNearbyEntities   = "MaxNearbyEntities",
            Tag::RequiredPlayerRange = "RequiredPlayerRange",
            Tag::SpawnRange          = "SpawnRange",
            Tag::CustomName          = "CustomName",
            Tag::Unbreakable         = "Unbreakable",
            Tag::customColor         = "customColor",
            Tag::ench                = "ench",
            Tag::id                  = "id",
            Tag::lvl                 = "lvl",
            Tag::display             = "display",
            Tag::Name                = "Name",
            Tag::Text1               = "Text1",
            Tag::Text2               = "Text2",
            Tag::Text3               = "Text3",
            Tag::Text4               = "Text4",
            Tag::Count               = "Count",
            Tag::Damage              = "Damage",
            Tag::Slot                = "Slot",
            Tag::Items               = "Items",
            Tag::Item                = "Item",
            Tag::tag                 = "tag",
            Tag::ItemRotation        = "ItemRotation";

            MinecraftGame::InitializedNbtTags = true;
        }

        // mainで呼んでください
        inline void initVariable(void)
        {
            svcGetThreadId(&pluginThreadId, CUR_THREAD_HANDLE);
        }

        // PatchProcessで呼んでください
        inline void initHooks(void)
        {

            /*
            static HookEx ctr_main;
            ctr_main.InitRoutine(0x105F7C, ctr_mainCallback, HookEx::EXECUTE_ORIGINAL_INSTR_AFTER);
            ctr_main.Enable();
            */

            // フリーズ修正
            static HookEx ShaderUpdateSkip;
            ShaderUpdateSkip.InitMitm(0x66D06C, (u32)shaderUpdateSkipCallback);
            ShaderUpdateSkip.Enable();

            /*
            static HookEx AssertHandler;
            AssertHandler.InitRoutine(0x1447AC, assertHandlerCallback);
            AssertHandler.Enable();
            */

            // static初期化処理
            static HookEx RegisterNbtTags;
            RegisterNbtTags.InitRoutine(0x7717BC, registerNbtTagsCallback);
            RegisterNbtTags.Enable();
        }

    }    // namespace GameHooks
}    // namespace MC3DSPluginFramework