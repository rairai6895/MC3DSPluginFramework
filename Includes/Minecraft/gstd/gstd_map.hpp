#pragma once

#include <map>
#include <types.h>

namespace MC3DSPluginFramework::gstd
{
    enum _Rb_tree_color : bool {
        red   = false,
        black = true
    };

    struct _Rb_tree_node_base
    {
        using _Base_ptr = _Rb_tree_node_base *;

        _Rb_tree_color mColor;
        _Base_ptr mParent;
        _Base_ptr mLeft;
        _Base_ptr mRight;
    };

    template <typename _Tp>
    struct _Rb_tree_node : public _Rb_tree_node_base
    {
        _Tp mData;
    };

    template <typename _Tp>
    struct _Rb_tree_iterator
    {
        using value_type = _Tp;
        using reference  = _Tp &;
        using pointer    = _Tp *;
        using _Base_ptr  = _Rb_tree_node_base::_Base_ptr;

        _Rb_tree_iterator() noexcept :
            mNode(nullptr) {}

        explicit _Rb_tree_iterator(_Base_ptr node) noexcept :
            mNode(node) {}

        _Rb_tree_iterator(const _Rb_tree_iterator &other) noexcept :
            mNode(other.mNode) {}

        reference operator*() const
        {
            return static_cast<_Rb_tree_node<_Tp> *>(mNode)->mData;
        }

        pointer operator->() const
        {
            return &static_cast<_Rb_tree_node<_Tp> *>(mNode)->mData;
        }

        bool operator==(const _Rb_tree_iterator &other) const
        {
            return this->mNode == other.mNode;
        }

        bool is_header() const
        {
            // ヘッダーは赤固定
            // rootの親はヘッダー

            if (mNode && mNode->mParent)
                return mNode->mColor == _Rb_tree_color::red && mNode->mParent->mParent == mNode;

            return false;
        }

        // 左 < 親 < 右の順番

        _Rb_tree_iterator &operator++()
        {
            _Base_ptr cur = mNode;

            if (cur) {
                if (cur->mRight) {
                    cur = cur->mRight;

                    while (cur->mLeft)
                        cur = cur->mLeft;
                }
                else {
                    // curが右の子の場合
                    while (cur->mParent && cur->mParent->mRight == cur)
                        cur = cur->mParent;

                    // curが左の子の場合
                    cur = cur->mParent;
                }

                mNode = cur;
            }

            return *this;
        }

        _Rb_tree_iterator &operator--()
        {
            _Base_ptr cur = mNode;

            if (cur) {
                // ヘッダーだけ構造が特殊だから別処理
                if (this->is_header()) {
                    cur = cur->mRight;
                }
                else if (cur->mLeft) {
                    cur = cur->mLeft;

                    while (cur->mRight)
                        cur = cur->mRight;
                }
                else {
                    // curが左の子の場合
                    while (cur->mParent && cur->mParent->mLeft == cur)
                        cur = cur->mParent;

                    // curが右の子の場合
                    cur = cur->mParent;
                }

                mNode = cur;
            }

            return *this;
        }

        _Rb_tree_iterator operator++(int)
        {
            _Rb_tree_iterator tmp(*this);
            ++(*this);
            return tmp;
        }

        _Rb_tree_iterator operator--(int)
        {
            _Rb_tree_iterator tmp(*this);
            --(*this);
            return tmp;
        }

        _Base_ptr mNode;
    };

    // insertなどの完全再現は諦め
    // 読み取り専用(Read only)
    template <typename Key, typename Data>
    class map
    {
    public:
        using value_type     = std::pair<const Key, Data>;
        using iterator       = _Rb_tree_iterator<value_type>;
        using const_iterator = const _Rb_tree_iterator<value_type>;
        using node           = _Rb_tree_node<value_type> *;
        using _Base_ptr      = iterator::_Base_ptr;

        struct NodeChunk
        {
            NodeChunk *mNext;
            size_t mSize;    // mNodesの中の要素数
            node mNodes;

            void destroy(void)
            {
                if (mNodes) {
                    for (size_t i = 0; i < mSize; ++i)
                        mNodes[i].mData.~value_type();

                    free((void *)mNodes);
                }
            }
        };

        map()
        {
        }

        map(map &&other)
        {
            memcpy(this, &other, sizeof(map));
            memset(&other, 0, sizeof(map));
        }

        map(const map &)            = delete;
        map &operator=(const map &) = delete;

        map &operator=(map &&other)
        {
            if (this != &other) {
                memcpy(this, &other, sizeof(map));
                memset(&other, 0, sizeof(map));
            }

            return *this;
        }

        /*
        ~map()
        {
            NodeChunk *current = mNodeChunk;
            while (current) {
                NodeChunk *next = current->mNext;
                current->destroy();
                free(current);
                current = next;
            }
        }
        */

        iterator begin()
        {
            return iterator(mHeader->mLeft);
        }

        iterator end()
        {
            return iterator(mHeader);
        }

        const_iterator begin() const
        {
            return const_iterator(mHeader->mLeft);
        }

        const_iterator end() const
        {
            return const_iterator(mHeader);
        }

        iterator lower_bound(const Key &key)
        {
            node end      = this->mHeader;
            _Base_ptr cur = end->mParent;
            iterator last(static_cast<_Base_ptr>(end));

            while (cur) {
                if (static_cast<node>(cur)->mData.first < key) {
                    cur = cur->mRight;
                }
                else {
                    last = iterator(cur);
                    cur  = cur->mLeft;
                }
            }

            return last;
        }

        iterator find(const Key &key)
        {
            auto it = lower_bound(key);
            return (it == end() || key < it->first) ? end() : it;
        }

        Data &operator[](const Key &key)
        {
            /*
            node end      = this->mHeader;
            _Base_ptr cur = end->mParent;

            while (cur) {
                if (static_cast<node>(cur)->mData.first < key)
                    cur = cur->mRight;
                else if (key < static_cast<node>(cur)->mData.first)
                    cur = cur->mLeft;
                else
                    return cur->mData;
            }
            */
            static Data fake;
            auto it = lower_bound(key);
            return (it == end() || key < it->first) ? fake : it->second;
        }

    private:
        NodeChunk *mNodeChunk;
        u32 mUnk1;
        u32 mUnk2;
        u32 mUnk3;
        node mHeader;
        u32 mSize;
        u32 mUnk4;    // u16?
    };

}    // namespace MC3DSPluginFramework::gstd