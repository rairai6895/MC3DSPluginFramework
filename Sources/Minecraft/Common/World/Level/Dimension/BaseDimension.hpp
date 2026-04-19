#pragma once

#include "Minecraft/Common/World/Level/LevelListener.hpp"
#include "Minecraft/gstd/gstd.hpp"

namespace MC3DSPluginFramework
{
    class Level;

    class Dimension_UnknownClass1
    {
    public:
        virtual ~Dimension_UnknownClass1() = default;

    private:
        // 0x9D6CE0

        int          mUnk1;
        gstd::string mUnk2;
        Level       *mLevel;
    };

    class BaseDimension : public LevelListener, public Dimension_UnknownClass1
    {
    public:
    private:
    };
}    // namespace MC3DSPluginFramework