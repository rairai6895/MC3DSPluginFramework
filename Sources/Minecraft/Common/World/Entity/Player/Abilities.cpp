#include "Abilities.hpp"

namespace MC3DSPluginFramework
{
    // FUN_0x735384
    Ability &Abilities::getAbility(gstd::string ability)
    {
        auto it = mAbilities.find(ability);

        if (!(it != mAbilities.end()))
            LOG("Tried to get unregistered ability", it != mAbilities.end(), 0);

        return it->second;
    }

    // FUN_0x7356A4
    bool Abilities::getBool(gstd::string ability)
    {
        return getAbility(ability).getBool();
    }

    // FUN_0x665B14
    void Abilities::setBool(gstd::string ability, bool set)
    {
        getAbility(ability).setBool(set);
    }

    // FUN_0x735708
    float Abilities::getFloat(gstd::string ability)
    {
        return getAbility(ability).getFloat();
    }

    void Abilities::setFloat(gstd::string ability, float set)
    {
        getAbility(ability).setFloat(set);
    }

    // FUN_0x73576C
    bool Abilities::isFlying()
    {
        return (getAbility(FLYING).getBool() || getAbility(NOCLIP).getBool());
    }

    // FUN_0x73569C
    u8 Abilities::getPermissionsLevel() const
    {
        return *mPermissionsLevel;
    }

    // FUN_0x665B7C
    void Abilities::loadSaveData(const CompoundTag &tag)
    {
        reinterpret_cast<void (*)(Abilities *, const CompoundTag &)>(0x665B7C)(this, tag);
    }

    // FUN_0x7354D4
    void Abilities::addSaveData(CompoundTag &tag)
    {
        reinterpret_cast<void (*)(Abilities *, CompoundTag &)>(0x7354D4)(this, tag);
    }

    // FUN_0x6F83F0
    void Abilities::putPermissionsLevel(u8 *permissionsLevel, CompoundTag &tag)
    {
        tag.putInt("permissionsLevel", *permissionsLevel);
    }

}    // namespace MC3DSPluginFramework
