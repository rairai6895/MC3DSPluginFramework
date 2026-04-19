#pragma once

#include "Minecraft/gstd/gstd.hpp"

namespace MC3DSPluginFramework
{
    class AppPlatform;
    class MinecraftGame;
    class ClientInstance;
    class Level;
    class Options;
    class Font;

    // "C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\src\\common\\client\\renderer\\entity\\EntityRenderDispatcher.cpp"
    class EntityRenderDispatcher
    {
        USE_GAME_ALLOCATOR
    public:
        virtual ~EntityRenderDispatcher();

        static void                    createInstance(MinecraftGame *minecraftGame, ClientInstance *clientInstance);
        static bool                    hasInstance();
        static EntityRenderDispatcher *getInstance();
        void                          *getRenderer(int rendererId) const;
        MinecraftGame                 &getMinecraftGame() const;
        ClientInstance                &getClientInstance() const;

    private:
        static inline gstd::unique_ptr<EntityRenderDispatcher> &mInstance           = *(gstd::unique_ptr<EntityRenderDispatcher> *)0xA3226C;
        static constexpr int                                    _ER_RENDERERS_COUNT = 78;

        AppPlatform    *mAppPlatform;    // +0x4
        MinecraftGame  *mMinecraftGame;    // +0x8
        ClientInstance *mClientInstance;    // +0xC
        void           *mUnk3;    // +0x10
        void           *mUnk4;    // +0x14
        Level          *mLevel;    // +0x18
        float           mUnk5;    // +0x1C
        float           mUnk6;    // +0x20
        Options        *mOptions;    // +0x24
        Font           *mFont;    // +0x28
        void           *mRenderer[_ER_RENDERERS_COUNT];    // +0x2C
    };
}    // namespace MC3DSPluginFramework