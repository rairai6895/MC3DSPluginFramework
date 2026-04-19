#pragma once

#include "Tag.hpp"

namespace MC3DSPluginFramework
{
    class TagMap
    {
    public:
        TagMap()
        {
        }

        size_t size() const
        {
            return mTags.size();
        }

        // FUN_0x8B658C
        size_t find(const gstd::string &key) const
        {
            for (int i = 0; i < mKeys.size(); ++i)
                if (mKeys[i].second == key)
                    return i;

            return mKeys.size();
        }

        Tag *get(const gstd::string &key) const
        {
            size_t idx = find(key);
            return (mTags.size() == idx) ? nullptr : mTags[mKeys[idx].first].get();
        }

        // FUN_0x7DE884
        gstd::unique_ptr<Tag> &operator[](const gstd::string &key)
        {
            size_t idx = find(key);

            if (mKeys.size() <= idx)
            {
                mKeys.push_back(std::make_pair(idx, key));
                return mTags.emplace_back();
            }

            return mTags[idx];
        }

        bool erase(const gstd::string &key)
        {
            return reinterpret_cast<bool (*)(TagMap *, const gstd::string &)>(0x7DE778)(this, key);
        }

    private:
        gstd::vector<std::pair<size_t, gstd::string>> mKeys;
        gstd::vector<gstd::unique_ptr<Tag>>           mTags;
    };
}    // namespace MC3DSPluginFramework