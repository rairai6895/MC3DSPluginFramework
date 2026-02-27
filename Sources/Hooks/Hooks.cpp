#include "Hooks/Hooks.hpp"
#include "Minecraft/Common/Thread.hpp"
#include <algorithm>

namespace MC3DSPluginFramework
{
    std::vector<std::thread::id> Hooks::mPluginThreads;
    HookEx Hooks::mMain;
    HookEx Hooks::mRegisterNbtTags;
    HookEx Hooks::mShaderUpdateSkip;
    HookEx Hooks::mMallocDeadlockFix;

    void Hooks::install()
    {
        mMain.InitSubWrap(0x10001C, (u32)mainCallback, 0x10598C);
        mMain.Enable();

        mRegisterNbtTags.InitRoutine(0x7717BC, registerNbtTagsCallback);
        mRegisterNbtTags.Enable();

        mShaderUpdateSkip.InitMitm(0x66D06C, (u32)shaderUpdateSkipCallback);
        mShaderUpdateSkip.Enable();

        mMallocDeadlockFix.InitMitm(0x11494C, (u32)mallocDeadlockFixCallback);
        mMallocDeadlockFix.Enable();
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

    void Hooks::mainCallback()
    {

        GameScheduler::onMainOnce();
    }

    // グローバル変数でstatic gstd::stringを初期化できないため、ゲームスレッドに初期化させる。
    // あらかじめ使うタグを登録しとく理由はNBTを扱う際に、gstd::stringのメモリ消費を最小限に抑えるためである。
    void Hooks::registerNbtTagsCallback(Regs &regs, u32 *sp, HookEx *hook)
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

    void Hooks::shaderUpdateSkipCallback(Dimension *_this, const BlockPos &pos)
    {
        if (isPluginThread(std::this_thread::get_id()))
            return;

        if (void *p = *(void **)((u32)_this + 0x13C))
            reinterpret_cast<void (*)(void *, const BlockPos &)>(0x4523E4)(p, pos);
    }

    void *Hooks::mallocDeadlockFixCallback(size_t size, Heap::Type type, u32 param3, u32 param4)
    {
        bool paused = CTRPluginFramework::Process::IsPaused();

        // 不正なTypeを弾く
        if (type != Heap::Type::Default && type != Heap::Type::Unknown)
            type = Heap::Type::CTR;

        while (true) {
            if (*(u8 *)0xA30D09)
                type = Heap::Type::CTR;

            // 本当にアロケーターかは分からない
            u32 allocator = **(u32 **)(0x919558 + (u8)type * 4);

            if (type == Heap::Type::Unknown && size < 0x2801) {
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

            if (type != Heap::Type::Default)
                break;

            type = Heap::Type::Unknown;
        }

        if (0x17FFFF < size || *(u32 *)0xA30D08 != 0)
            *(u32 *)nullptr = 0;

        if (*(u8 *)0xA30D08 = 1, *(u32 *)0xA30D0C == 0)
            *(u32 *)nullptr = 0;

        return 0;
    }

}    // namespace MC3DSPluginFramework