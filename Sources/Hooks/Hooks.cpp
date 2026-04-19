#include "Hooks.hpp"
#include "Extensions/Event.hpp"
#include "Extensions/UserCode.hpp"
#include "Minecraft/Common/Client/Game/MinecraftGame.hpp"
#include "Minecraft/Common/Client/Gui/Components/BaseButton.hpp"
#include "Minecraft/Common/Client/Gui/Screens/BaseScreen.hpp"
#include "Minecraft/Common/Thread.hpp"
#include "Minecraft/Common/World/Item/Crafting/Recipes.hpp"
#include <algorithm>

namespace MC3DSPluginFramework
{
    void Hooks::install()
    {
        constexpr u32 NOP = 0xE320F000;

        MainHook.initSubWrap(0x10001C, (u32)Main, 0);
        MainHook.enable();

        RegisterNbtTagsHook.initRoutine(0x7717BC, RegisterNbtTags);
        RegisterNbtTagsHook.enable();

        ShaderUpdateSkipHook.initMitm(0x66D06C, (u32)ShaderUpdateSkip);
        ShaderUpdateSkipHook.enable();

        CreativeMenu_registerMenuItemsHook.initSubWrap(0x56C2AC, 0, (u32)CreativeMenu_registerMenuItems);
        CreativeMenu_registerMenuItemsHook.enable();

        // ボタンのバグ修正
        *(u32 *)0x9A144C = (u32)BaseButton_onTouchRelease;
        *(u32 *)0x9CB638 = (u32)BaseButton_onTouchRelease;
        *(u32 *)0x9D9F94 = (u32)BaseButton_onTouchRelease;
        *(u32 *)0x9DA454 = (u32)BaseButton_onTouchRelease;
        *(u32 *)0x9DAB9C = (u32)BaseButton_onTouchRelease;

        // 無駄なregisterCreativeItems呼び出しを削除
        *(u32 *)0x47AEEC = NOP;

        // 無駄なregisterRecipes呼び出しを削除
        *(u32 *)0x47AF04 = NOP;

        Recipes_registerRecipesHook.initRoutine(0x635D08, Recipes_registerRecipes);
        Recipes_registerRecipesHook.enable();
    }

    void Hooks::pushPluginThreadId(std::thread::id id)
    {
        if (gMainThread != id)
            mPluginThreads.push_back(id);
    }

    void Hooks::erasePluginThreadId(std::thread::id id)
    {
        mPluginThreads.erase(
            std::remove_if(
                mPluginThreads.begin(),
                mPluginThreads.end(),
                [&](std::thread::id _id) {
                    return _id == id;
                }
            )
        );
    }

    bool Hooks::isPluginThread(std::thread::id id)
    {
        for (auto p : mPluginThreads)
            if (id == p)
                return true;

        return false;
    }

    void Hooks::Main()
    {
        UserCode::onMainOnce();
    }

    // グローバル変数でstatic gstd::stringを初期化できないため、ゲームスレッドに初期化させる。
    // あらかじめ使うタグを登録しとく理由はNBTを扱う際に、gstd::stringのメモリ消費を最小限に抑えるため
    void Hooks::RegisterNbtTags(Regs &regs, u32 *sp, Asterium::AstHook *hook)
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

        Event::States |= EventStates::RegisteredNbtTags;
    }

    void Hooks::ShaderUpdateSkip(Dimension *_this, const BlockPos &pos)
    {
        // BackGroundWorkerが原因の可能性あり

        if (isPluginThread(std::this_thread::get_id()))
            return;

        if (void *p = *(void **)((u32)_this + 0x13C))
            reinterpret_cast<void (*)(void *, const BlockPos &)>(0x4523E4)(p, pos);
    }

    bool Hooks::BaseButton_onTouchRelease(BaseButton *_this, MinecraftGame *minecraftGame, int touchX, int touchY)
    {
        bool clicked = _this->mDragging && _this->isHovered(touchX, touchY);
        _this->stopDragging();

        if (!clicked)
            return false;

        if (_this->mScreen_UnknownClass2)
            _this->mScreen_UnknownClass2->Unknown1(*_this);

        return true;
    }

    void Hooks::CreativeMenu_registerMenuItems()
    {
        auto registerCreativeItem = reinterpret_cast<void (*)(const ItemInstance &)>(0x56E108);
        UserCode::registerCreativeItems(registerCreativeItem);
    }

    void Hooks::Recipes_registerRecipes(Regs &regs, u32 *sp, Asterium::AstHook *hook)
    {
        Recipes &_this = *reinterpret_cast<Recipes *>(regs.r0);
        _this.registerRecipes();
        UserCode::registerRecipes(_this);
    }

}    // namespace MC3DSPluginFramework