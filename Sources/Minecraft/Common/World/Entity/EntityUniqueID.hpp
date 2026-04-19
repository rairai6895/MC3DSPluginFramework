#pragma once

#include <cstdint>

namespace MC3DSPluginFramework
{
    class EntityUniqueID
    {
    public:
        u32 mId1, mId2;

        EntityUniqueID() :
            mId1(-1),
            mId2(-1)
        {
        }

        EntityUniqueID(const EntityUniqueID &other)
        {
            mId1 = other.mId1;
            mId2 = other.mId2;
        }

        explicit operator bool() const
        {
            return mId1 != -1 && mId2 != -1;
        }

        EntityUniqueID &operator=(const EntityUniqueID &other)
        {
            mId1 = other.mId1;
            mId2 = other.mId2;

            return *this;
        }
    };
}    // namespace MC3DSPluginFramework