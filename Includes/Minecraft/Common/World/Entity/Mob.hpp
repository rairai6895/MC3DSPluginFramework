#pragma once

#include "Entity.hpp"

namespace MC3DSPluginFramework
{
    class Mob : public _Entity
    {
    public:
        void createAIGoals()
        {
            reinterpret_cast<void (*)(Mob *)>(0x4E504C)(this);
        }

    public:
        ~Mob() override;
        void initializeComponents(bool unknown) override;
        void tick() override;
        void _removeRider() override;

    private:
        // // vtable 9c6e24
    };
}    // namespace MC3DSPluginFramework