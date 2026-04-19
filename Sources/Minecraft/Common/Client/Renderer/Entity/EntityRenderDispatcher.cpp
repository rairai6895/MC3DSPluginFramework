#include "EntityRenderDispatcher.hpp"
#include "Minecraft/Common/Logger.hpp"

namespace MC3DSPluginFramework
{
    void EntityRenderDispatcher::createInstance(MinecraftGame *minecraftGame, ClientInstance *clientInstance)
    {
        reinterpret_cast<void (*)(MinecraftGame *, ClientInstance *)>(0x444E14)(minecraftGame, clientInstance);
    }

    // FUN_0x44907C
    bool EntityRenderDispatcher::hasInstance()
    {
        return (bool)mInstance;
    }

    // FUN_0x444CA0
    EntityRenderDispatcher *EntityRenderDispatcher::getInstance()
    {
        return mInstance.get();
    }

    // FUN_0x444CB0
    void *EntityRenderDispatcher::getRenderer(int rendererId) const
    {
        if (!(rendererId >= 0 && rendererId < _ER_RENDERERS_COUNT))
            LOG("Invalid mRenderer requested", rendererId >= 0 && rendererId < _ER_RENDERERS_COUNT, 0);

        return mRenderer[rendererId];
    }

    MinecraftGame &EntityRenderDispatcher::getMinecraftGame() const
    {
        return *mMinecraftGame;
    }

    ClientInstance &EntityRenderDispatcher::getClientInstance() const
    {
        return *mClientInstance;
    }

}    // namespace MC3DSPluginFramework