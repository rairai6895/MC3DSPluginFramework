#pragma once

#include "FillingContainer.hpp"

namespace MC3DSPluginFramework
{
    class Inventory : public FillingContainer
    {
    public:
        ~Inventory() override;

        void setupDefault();

    private:
        // 0x9D4930
    };
}    // namespace MC3DSPluginFramework