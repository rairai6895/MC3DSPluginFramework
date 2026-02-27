#pragma once

#include "Minecraft/Common/Client/Game/ClientInstance.hpp"

namespace MC3DSPluginFramework
{
    // "C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\src\\common\\client\\renderer\\entity\\EntityRenderDispatcher.cpp"
    class EntityRenderDispatcher
    {
    public:
        static void createInstance(MinecraftGame *minecraftGame, ClientInstance *clientInstance)
        {
            reinterpret_cast<void (*)(MinecraftGame *, ClientInstance *)>(0x444E14)(minecraftGame, clientInstance);
        }

        // FUN_0x44907C
        static bool isLoaded(void) { return mInstance; }

        // FUN_0x444CA0
        static EntityRenderDispatcher *getInstance(void) { return mInstance; }

        void *getRenderer(u32 rendererId) const
        {
            return reinterpret_cast<void *(*)(const EntityRenderDispatcher *, u32)>(0x444CB0)(this, rendererId);
        }

        ClientInstance *getClientInstance(void) const
        {
            return mClientInstance;
        }

        Level *getLevel(void) const { return mLevel; }
        u32 getOptions(void) const { return (u32)mOptions; }

    private:
        static inline EntityRenderDispatcher *&mInstance = *(EntityRenderDispatcher **)0xA3226C;

        u32 vtable;
        void *mUnk1;
        MinecraftGame *mMinecraftGame;
        ClientInstance *mClientInstance;
        void *mUnk3;
        void *mUnk4;
        Level *mLevel;
        u32 mUnk5;
        u32 mUnk6;
        void *mOptions;
        void *mRenderer;    // 多分
        u32 mUnk7;
        u32 mUnk8;
        void *mUnk9;
        void *mUnk10;
        void *mUnk11;
        void *mUnk12;
        void *mUnk13;
        void *mUnk14;
        void *mUnk15;
        void *mUnk16;
        void *mUnk17;
        void *mUnk18;
        void *mUnk19;
        void *mUnk20;
        void *mUnk21;
        u32 mUnk22;
        void *mUnk23;
        void *mUnk24;
        void *mUnk25;
        void *mUnk26;
        void *mUnk27;
        void *mUnk28;
        void *mUnk29;
        void *mUnk30;
        void *mUnk31;
        void *mUnk32;
        void *mUnk33;
        void *mUnk34;
        void *mUnk35;
        void *mUnk36;
        void *mUnk37;
        void *mUnk38;
        void *mUnk39;
        void *mUnk40;
        void *mUnk41;
        void *mUnk42;
        void *mUnk43;
        void *mUnk44;
        void *mUnk45;
        void *mUnk46;
        void *mUnk47;
        void *mUnk48;
        void *mUnk49;
        void *mUnk50;
        void *mUnk51;
        void *mUnk52;
        void *mUnk53;
        void *mUnk54;
        void *mUnk55;
        void *mUnk56;
        void *mUnk57;
        void *mUnk58;
        void *mUnk59;
        void *mUnk60;
        void *mUnk61;
        void *mUnk62;
        void *mUnk63;
        void *mUnk64;
        u32 mUnk65;
        void *mUnk66;
        void *mUnk67;
        void *mUnk68;
        void *mUnk69;
        u32 mUnk70;
        void *mUnk71;
        void *mUnk72;
        void *mUnk73;
        u32 mUnk74;
        void *mUnk75;
        void *mUnk76;
        void *mUnk77;
        void *mUnk78;
        void *mUnk79;
        void *mUnk80;
        void *mUnk81;
        void *mUnk82;
        void *mUnk83;
        void *mUnk84;
    };
}    // namespace MC3DSPluginFramework