#pragma once

#include "Minecraft/Common/World/Entity/Entity.hpp"

namespace MC3DSPluginFramework
{
    // "C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\src\\common\\world\\entity\\item\\ItemEntity.cpp"
    class ItemEntity
    {
    public:
        void _validateItem()
        {
            reinterpret_cast<void (*)(ItemEntity *)>(0x155684)(this);
        }

        void readAdditionalSaveData(CompoundTag &nbt)
        {
            reinterpret_cast<void (*)(ItemEntity *, CompoundTag &)>(0x155B90)(this, nbt);
        }

    private:
    };
}    // namespace MC3DSPluginFramework