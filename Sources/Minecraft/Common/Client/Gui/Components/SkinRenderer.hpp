#pragma once

#include "Minecraft/Common/Client/Player/Skin.hpp"
#include "Minecraft/src-deps/Renderer/TexturePtr.hpp"
#include <types.h>

namespace MC3DSPluginFramework
{
    class MinecraftGame;
    class Skin;
    class TextureGroup;
    class ResourceLoader;

    class SkinRenderer_UnknownClass
    {
    public:
        // FUN_0x1EBFC0
        SkinRenderer_UnknownClass() :
            mUnk3(),
            mUnk4(0),
            mUnk5(0),
            mUnk8(0)
        {
        }

        virtual ~SkinRenderer_UnknownClass() = default;
        virtual void Unknown1()              = delete;

        void FUN_001ebe7c(gstd::string str)
        {
            mUnk1 = str;
        }

    private:
        // 0x9A2804

        gstd::string                mUnk1;    // +0x4
        gstd::string                mUnk2;    // +0x8
        TexturePtr                  mUnk3;    // +0xC
        gstd::type_unknown<0x1FC0> *mUnk4;    // +0x2C
        int                         mUnk5;    // +0x30
        int                         mUnk6;    // +0x34
        gstd::string                mUnk7;    // +0x38
        char                        mUnk8;    // +0x3C
    };

    // "C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\src\\common\\client\\gui\\components\\SkinRenderer.cpp"
    class SkinRenderer
    {
        USE_GAME_ALLOCATOR
    public:
        enum Mode : char {
            Default,
            Rotation,    // 回転する
            ControlHead,    // タッチパッドでスキンの頭(yaw, pitch)を動かせる
        };

        SkinRenderer(MinecraftGame *minecraftGame, int x, int y, float z, Mode mode, u8 p6, float p7)
        {
            reinterpret_cast<SkinRenderer *(*)(SkinRenderer *, MinecraftGame *, int, int, float, Mode, u8, float)>(0x1EC930)(this, minecraftGame, x, y, z, mode, p6, p7);
        }

        void render(float unknown)
        {
            reinterpret_cast<void (*)(SkinRenderer *, float)>(0x1EC148)(this, unknown);
        }

        // FUN_0x1EC110
        void tick()
        {
            mTick++;    // 増加量でアニメーションの速度が上がる
        }

        // FUN_0x1EC8A8
        void setSkin(Skin *skin)
        {
            mSkin = skin;
            mUnk13.FUN_001ebe7c(skin->mSerializableName);
            mUnk11 = 0;

            if (!mUnk10)
                return;

            // 仮名
            float scale   = mSkin->mUnk9;
            float scaledZ = mDefaultZ * scale;
            float scaledY = mUnk5 * scale;

            scale = scale * 2;
            mZ    = scaledZ;
            mUnk4 = scaledY;
            mX    = scaledZ / scale + mDefaultX;
            mY    = scaledY / scale + mDefaultY;
        }

        Skin *getSkin()
        {
            return mSkin;
        }

    private:
        MinecraftGame            *mMinecraftGame;    // +0x0
        float                     mX;    // +0x4
        float                     mDefaultX;    // +0x8 計算に使ってるっぽい
        float                     mY;    // +0xC
        float                     mDefaultY;    // +0x10
        float                     mZ;    // +0x14
        float                     mDefaultZ;    // +0x18
        float                     mUnk4;    // +0x1C
        float                     mUnk5;    // +0x20
        int                       mTick;    // +0x24
        float                     mUnk6;    // +0x28
        u8                        mUnk7;    // +0x2C
        Mode                      mMode;    // +0x2D
        u8                        mUnk9;    // +0x2E
        u8                        mUnk10;    // +0x2F
        float                     mUnk11;    // +0x30 回転のステップ
        float                     mUnk12;    // +0x34
        Skin                     *mSkin;    // +0x38
        SkinRenderer_UnknownClass mUnk13;    // +0x3C
        int                       mUnk14;    // +0x7C
        int                       mUnk15;    // +0x80
        int                       mUnk16;    // +0x84
        float                     mYaw;    // +0x88
        float                     mPitch;    // +0x8C
    };
}    // namespace MC3DSPluginFramework