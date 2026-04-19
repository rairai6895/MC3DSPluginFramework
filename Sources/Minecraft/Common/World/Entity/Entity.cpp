#include "Minecraft/Common/World/Entity/Entity.hpp"
#include "../Level/BlockSource.hpp"
#include "../Level/Level.hpp"

namespace MC3DSPluginFramework
{
    // FUN_0x5F741C
    // FUN_0x724F54
    Level &Entity::getLevel()
    {
        if (!mLevel)
            LOG("Entity was not placed in a level", mLevel, 0);

        return *mLevel;
    }

    BlockSource &Entity::getRegion()
    {
        return *mRegion;
    }

    // 多分参照返し
    Dimension *Entity::getDimension()
    {
        if (!mRegion)
            LOG("This entity doesn't have a region right now", mRegion, 0);

        return mRegion->getDimension();
    }

    Vec3<float> Entity::getAttachPos(int p1)
    {
        return reinterpret_cast<Vec3<float> (*)(Entity *, int)>(0x723714)(this, p1);
    }

    // FUN_0x5E9584
    void Entity::setUniqueID(EntityUniqueID ID)
    {
        if (!ID)
            LOG("Invalid ID", ID, 0);

        if (mUniqueID)
            LOG("This entity already has a unique ID you villain", !mUniqueID, 0);

        mUniqueID = ID;
    }

    bool Entity::hasCategory(EntityCategory category)
    {
        return reinterpret_cast<bool (*)(Entity *, EntityCategory)>(0x723678)(this, category);
    }

    // FUN_0x723CAC
    bool Entity::getSharedFlag(SynchedEntityData::EntitySharedFlag flag)
    {
        return mSynchedEntityData.getFlag<s64>(0, (int)flag);
    }

    // FUN_0x725588
    bool Entity::isRemoved() const
    {
        return mRemoved;
    }

    // FUN_0x71439C
    bool Entity::isGliding()
    {
        return getSharedFlag(SynchedEntityData::EntitySharedFlag::Gliding);
    }

    // FUN_0x5F63FC
    // +0x28
    void Entity::vFunc0x28()
    {
        m0xD49 = false;

        if (!getLevel().isClientSide())
        {
            initializeComponents(m0x4);
        }

        m0xD49 = true;
    }
}    // namespace MC3DSPluginFramework