#include "LocalPlayer.hpp"

namespace MC3DSPluginFramework
{
    void LocalPlayer::pickBlockCreative(HitResult &hitResult, bool saveBlockEntityNbt)
    {
        reinterpret_cast<void (*)(LocalPlayer *, HitResult &, bool)>(0x196AF4)(this, hitResult, saveBlockEntityNbt);
    }

    void LocalPlayer::addItemCreative(const ItemInstance &item)
    {
        reinterpret_cast<void (*)(LocalPlayer *, const ItemInstance &)>(0x19562C)(this, item);
    }

    // FUN_0x6A6910
    ClientInstance &LocalPlayer::getClient()
    {
        return *mClientInstance;
    }
}