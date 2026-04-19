#include "UserManager.hpp"

namespace MC3DSPluginFramework
{
    UserManager::UserManager()
    {
        reinterpret_cast<UserManager *(*)(UserManager *)>(0x624894)(this);
    }

    UserManager::~UserManager()
    {
        reinterpret_cast<UserManager *(*)(UserManager *)>(0x624B8C)(this);
    }

    // FUN_0x624604
    BoxedPtr::Shared<std::pair<void *, gstd::unique_ptr<Options>>> UserManager::getOptions() const
    {
        for (auto &p : mUnk2)
            if (p->first == mUnk1)
                return p;

        return nullptr;
    }
}    // namespace MC3DSPluginFramework