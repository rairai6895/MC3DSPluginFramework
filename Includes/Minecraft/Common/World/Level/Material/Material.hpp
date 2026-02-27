#pragma once

#include "Minecraft/Common/Logger.hpp"
#include "Minecraft/gstd/gstd.hpp"

namespace MC3DSPluginFramework
{
    // "C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\src\\common\\world\\level\\material\\Material.cpp"
    class Material
    {
    public:
        // FUN_0x6596B4
        Material(int type, int unknown1, float unknown2)
        {
            mType = type;
            mUnk1 = 0;
            mUnk2 = 0;
            mUnk3 = 1;
            mUnk4 = 0;
            mUnk5 = 0;
            mUnk6 = unknown2;
            mUnk7 = 1;
            mUnk8 = 1;
            mUnk9 = 0;

            u32 *p = (u32 *)0xB2E560;

            mUnk10 = p[0];
            mUnk11 = p[1];
            mUnk12 = p[2];
            mUnk13 = p[3];

            if (unknown1 == 1) {
                mUnk8 = 0;
                mUnk7 = 0;
                mUnk4 = 1;
            }
            if (unknown1 == 2) {
                mUnk8 = 0;
                mUnk5 = 1;
                mUnk7 = 0;
                mUnk4 = 1;
            }
            if (unknown1 == 3 || unknown1 == 4) {
                mUnk8 = 0;
                mUnk7 = 0;
            }
        }

        static void registerMaterial()
        {
            reinterpret_cast<void (*)()>(0x658E90)();
        }

        // FUN_0x658DE8
        static Material *getMaterial(int i)
        {
            if (!(mInitialized == true))
                LOG("Attempt to get material before initializing", mInitialized == true, 0);

            return mMaterials[i].get();
        }

        static void addMaterial(gstd::unique_ptr<Material> &&mat)
        {
            reinterpret_cast<void (*)(gstd::unique_ptr<Material> &&)>(0x658B38)(std::move(mat));
        }

    private:
        using Materials = gstd::vector<gstd::unique_ptr<Material>>;

        static inline bool &mInitialized    = *(bool *)0xA35110;
        static inline Materials &mMaterials = *(Materials *)0xB16C68;

    public:
        int mType;
        u8 mUnk1;
        u8 mUnk2;
        u8 mUnk3;
        u8 mUnk4;
        u8 mUnk5;
        float mUnk6;
        u8 mUnk7;
        u8 mUnk8;
        u8 mUnk9;
        u32 mUnk10;
        u32 mUnk11;
        u32 mUnk12;
        u32 mUnk13;
    };
}    // namespace MC3DSPluginFramework