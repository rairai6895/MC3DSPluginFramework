#pragma once

#include "BlockEntity/BlockEntity.hpp"
#include "Minecraft/gstd/gstd.hpp"

namespace MC3DSPluginFramework
{
    class BlockSource;
    class LevelChunk;
    class BlockEntity;

    // 多分
    class BlockSourceListener
    {
    public:
        virtual ~BlockSourceListener() = default;

        // onStartListen?
        // FUN_0x3B52B4
        // +0x8
        virtual void Unknown1(BlockSource &region)
        {
            return;
        }

        // onStopListen?
        // FUN_0x3B52B8
        // +0xC
        virtual void Unknown2(BlockSource &region)
        {
            return;
        }

        // FUN_0x3B52A8
        // +0x10
        virtual void areaChanged(BlockSource &region, const BlockPos &pos)
        {
            return;
        }

        // FUN_0x3B52AC
        // +0x14
        virtual void blockChanged(BlockSource &region, const BlockPos &pos, BlockData newData, BlockData oldData, int p5, Entity *e)
        {
            return;
        }

        // FUN_0x3B52BC
        // +0x18
        virtual void brightnessChanged(BlockSource &region, const BlockPos &p2)
        {
            areaChanged(region, p2);
        }

        // FUN_0x3B52CC
        // +0x1C
        virtual void blockEntityChanged()
        {
            return;
        }

        // FUN_0x3B52B0
        // +0x20
        virtual void Unknown3()
        {
            return;
        }

        // FUN_0x3B52D0
        // +0x24
        virtual gstd::unique_ptr<BlockEntity> blockEntityRemoved(BlockSource &region, gstd::unique_ptr<BlockEntity> &&be)
        {
            return std::move(be);    // 処理がなかったらそのまま返す仕様にしてるのかも
        }

        // FUN_0x3B52A4
        // +0x28
        virtual void blockEvent()
        {
            return;
        }

    private:
    };

    class LevelListener : public BlockSourceListener
    {
    public:
        ~LevelListener() override = default;

        // +0x2C
        virtual void Unknown4() = delete;

        // FUN_0x221A20
        // +0x30
        virtual void *addParticle(int id, const Vec3<float> &pos, const Vec3<float> &velocity, int data)
        {
            return nullptr;
        }

        // +0x34
        virtual void Unknown5() = delete;

        // +0x38
        virtual void Unknown6() = delete;

        // FUN_0x221A2C
        // +0x3C
        virtual void entityAdded(Entity *e)
        {
            return;
        }

        // FUN_0x221A48
        // +0x40
        virtual void entityRemoved(Entity *e)
        {
            return;
        }

        // FUN_0x221A30
        // +0x44
        virtual void onNewChunk(Entity *e, LevelChunk *lc)
        {
            return;
        }

        // FUN_0x221A28
        // +0x48
        virtual void onChunkLoaded(LevelChunk *lc)
        {
            return;
        }

        // FUN_0x221A44
        // +0x4C
        virtual void onChunkRelease(LevelChunk *lc)
        {
            return;
        }

        // FUN_0x221A50
        // +0x50
        virtual void Unknown7()
        {
            return;
        }

        // FUN_0x221A1C
        // +0x54
        virtual void Unknown8()
        {
            return;
        }

        // FUN_0x221A3C
        // +0x58
        virtual void playSound(int id, const Vec3<float> &pos, int p3, int p4, int p5, int p6)
        {
            return;
        }

    private:
        // 0x9A5A8C
    };

}    // namespace MC3DSPluginFramework