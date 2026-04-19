#pragma once

#include "Minecraft/Common/Client/Options/Options.hpp"
#include "Minecraft/Common/Util/BoxedPtr.hpp"

namespace MC3DSPluginFramework
{
    class UserManager
    {
        USE_GAME_ALLOCATOR
    public:
        UserManager();
        ~UserManager();

        BoxedPtr::Shared<std::pair<void *, gstd::unique_ptr<Options>>> getOptions() const;

    private:
        void *mUnk1;

        gstd::vector<BoxedPtr::Shared<std::pair<void *, gstd::unique_ptr<Options>>>> mUnk2;
    };
}    // namespace MC3DSPluginFramework