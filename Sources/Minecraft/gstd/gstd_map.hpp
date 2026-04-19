#pragma once

// このファイルには libstdc++ (GNU LGPL v3) の std::map を参考にして作成されたクラス, 構造体, 関数が含まれます。
// 元の実装を改変したものには "base by libstdc++" とコメントを記述してあります。
// 改変部分も含め、ライセンス条件に従って使用してください。
// 詳細: https://www.gnu.org/software/libstdc++/

#include <bits/stl_tree.h>
#include <initializer_list>
#include <tuple>
#include <types.h>

namespace MC3DSPluginFramework::gstd
{
    struct test_allocator
    {
        static void *allocate(size_t s)
        {
            return malloc(s);
        }

        static void deallocate(void *m)
        {
            free(m);
        }
    };

    // base by libstdc++
    template <typename _Val>
    struct _Rb_tree_node : public std::_Rb_tree_node_base
    {
        // C++11の実装と同じ

        _Val _M_value_field;

        _Val *_M_valptr()
        {
            return std::__addressof(_M_value_field);
        }

        const _Val *_M_valptr() const
        {
            return std::__addressof(_M_value_field);
        }
    };

    template <typename _Val>
    struct _Rb_tree_header : public _Rb_tree_node<_Val>
    {
        _Rb_tree_header() noexcept
        {
            std::_Rb_tree_node_base::_M_color = std::_Rb_tree_color::_S_red;
            _M_reset();
        }

        void _M_reset() noexcept
        {
            std::_Rb_tree_node_base::_M_parent = nullptr;
            std::_Rb_tree_node_base::_M_left   = this;
            std::_Rb_tree_node_base::_M_right  = this;
        }
    };

    template <typename _Val, typename _Alloc>
    struct _Rb_tree_node_chunk
    {
        using node = _Rb_tree_node<_Val>;

        _Rb_tree_node_chunk(_Rb_tree_node_chunk *next, size_t size)
        {
            _M_next  = next;
            _M_size  = size;
            _M_nodes = reinterpret_cast<node *>(_Alloc::allocate(sizeof(node) * size));
        }

        void _M_destroy()
        {
            if (_M_nodes)
            {
                for (int i = 0; i < _M_size; ++i)
                    _M_nodes[i]._M_value_field.~_Val();

                _Alloc::deallocate(_M_nodes);
            }
        }

        _Rb_tree_node_chunk *_M_next;
        size_t               _M_size;
        node                *_M_nodes;
    };

    template <typename _Key, typename _Tp, typename _Alloc = test_allocator>
    class map
    {
    public:
        using value_type     = std::pair<const _Key, _Tp>;
        using iterator       = std::_Rb_tree_iterator<value_type>;
        using const_iterator = std::_Rb_tree_const_iterator<value_type>;
        using _Base_ptr      = iterator::_Base_ptr;
        using node_chunk     = _Rb_tree_node_chunk<value_type, _Alloc>;
        using node           = _Rb_tree_node<value_type>;
        using header         = _Rb_tree_header<value_type>;
        using insert_result  = std::pair<iterator, bool>;

        map()
        {
            _M_construct_map();
            _M_create_and_set_header();
        }

        map(const value_type &item)
        {
            _M_construct_map();
            _M_reserve_nodes(2);
            _M_create_and_set_header();
            insert(item);
        }

        map(value_type &&item)
        {
            _M_construct_map();
            _M_reserve_nodes(2);
            _M_create_and_set_header();
            insert(std::move(item));
        }

        map(std::initializer_list<value_type> list)
        {
            _M_construct_map();
            _M_reserve_nodes(list.size() + 1 /* headerの分 */);
            _M_create_and_set_header();
            insert(std::move(list));
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
            if (this != &other)
            {
                memcpy(this, &other, sizeof(map));
                memset(&other, 0, sizeof(map));
            }

            return *this;
        }

        ~map()
        {
            _M_header->_M_right = _M_cur;
            _M_cur              = _M_header;

            node_chunk *cur = _M_node_chunk;
            while (cur)
            {
                node_chunk *next = cur->_M_next;

                cur->_M_destroy();
                _Alloc::deallocate(cur);

                cur = next;
            }
        }

        iterator begin()
        {
            return iterator(_M_header->_M_left);
        }

        iterator end()
        {
            return iterator(_M_header);
        }

        const_iterator begin() const
        {
            return const_iterator(_M_header->_M_left);
        }

        const_iterator end() const
        {
            return const_iterator(_M_header);
        }

        size_t size() const
        {
            return _M_size;
        }

        bool empty() const
        {
            return size() == 0;
        }

        iterator lower_bound(const _Key &key)
        {
            node     *end = this->_M_header;
            _Base_ptr cur = end->_M_parent;
            iterator  last(static_cast<_Base_ptr>(end));

            while (cur)
            {
                if (static_cast<node *>(cur)->_M_value_field.first < key)
                    cur = cur->_M_right;
                else
                {
                    last = iterator(cur);
                    cur  = cur->_M_left;
                }
            }

            return last;
        }

        const_iterator lower_bound(const _Key &key) const
        {
            node          *end = this->_M_header;
            _Base_ptr      cur = end->_M_parent;
            const_iterator last(static_cast<_Base_ptr>(end));

            while (cur)
            {
                if (static_cast<node *>(cur)->_M_value_field.first < key)
                    cur = cur->_M_right;
                else
                {
                    last = const_iterator(cur);
                    cur  = cur->_M_left;
                }
            }

            return last;
        }

        insert_result insert(const value_type &item)
        {
            return _M_insert_unique(item);
        }

        insert_result insert(value_type &&item)
        {
            return _M_insert_unique(std::move(item));
        }

        void insert(std::initializer_list<value_type> list)
        {
            for (auto it = list.begin(); it < list.end(); ++it)
                insert(std::move(*it));
        }

        iterator erase(iterator pos)
        {
            iterator res = pos;
            ++res;

            _M_destroy_node(static_cast<node *>(std::_Rb_tree_rebalance_for_erase(pos._M_node, *_M_header)));
            --_M_size;

            return res;
        }

        iterator find(const _Key &key)
        {
            iterator it = lower_bound(key);
            return (it == end() || key < it->first) ? end() : it;
        }

        const_iterator find(const _Key &key) const
        {
            const_iterator it = lower_bound(key);
            return (it == end() || key < it->first) ? end() : it;
        }

        _Tp &operator[](const _Key &key)
        {
            iterator it = lower_bound(key);

            if (it == end() || key < it->first)
            {
                insert_result res = insert(value_type(std::piecewise_construct, std::forward_as_tuple(key), std::tuple<>()));
                it                = res.first;
            }

            return it->second;
        }

        _Tp &operator[](_Key &&key)
        {
            iterator it = lower_bound(key);

            if (it == end() || key < it->first)
            {
                insert_result res = insert(value_type(std::piecewise_construct, std::forward_as_tuple(std::move(key)), std::tuple<>()));
                it                = res.first;
            }

            return it->second;
        }

    private:
        // construct functions

        void _M_construct_map()
        {
            _M_node_chunk = nullptr;
            _M_free       = nullptr;
            _M_cur        = nullptr;
            _M_end        = nullptr;
            _M_header     = nullptr;
            _M_size       = 0;
            mUnk4         = true;
            mUnk5         = true;
        }

        /*
        void _M_construct_node(node *node, const value_type &val)
        {
            node->_M_color  = std::_Rb_tree_color::_S_red;
            node->_M_parent = nullptr;
            node->_M_left   = nullptr;
            node->_M_right  = nullptr;
            new ((void *)&node->_M_value_field) value_type(std::piecewise_construct, std::tuple(val.first), std::tuple(val.second));
        }
        */

        /*
        void _M_construct_node(node *node, value_type &&val)
        {
            node->_M_color  = std::_Rb_tree_color::_S_red;
            node->_M_parent = nullptr;
            node->_M_left   = nullptr;
            node->_M_right  = nullptr;
            new ((void *)&node->_M_value_field) value_type(
                std::piecewise_construct,
                std::forward_as_tuple(std::move(val.first)),
                std::forward_as_tuple(std::move(val.second))
            );
        }
        */

        template <class... Args>
        void _M_construct_node(node *node, Args &&...args)
        {
            node->_M_color  = std::_Rb_tree_color::_S_red;
            node->_M_parent = nullptr;
            node->_M_left   = nullptr;
            node->_M_right  = nullptr;
            new ((void *)&node->_M_value_field) value_type(std::forward<Args>(args)...);
        }

        void _M_construct_header(header *h)
        {
            h->_M_left  = nullptr;
            h->_M_right = nullptr;

            new (reinterpret_cast<void *>(h)) header();
            _M_header = h;
        }

    private:
        // destruct functions

        void _M_destruct_node(node *node)
        {
            node->_M_value_field.~value_type();
        }

    private:
        // insert system functions

        using insert_pos = std::pair<_Base_ptr, _Base_ptr>;

        // base by libstdc++
        insert_pos _M_get_insert_unique_pos(const _Key &key)
        {
            _Base_ptr x   = _M_header->_M_parent;
            _Base_ptr y   = _M_header;
            bool      cmp = false;

            while (x)
            {
                y   = x;
                cmp = key < static_cast<node *>(x)->_M_value_field.first;

                if (cmp)
                    x = x->_M_left;
                else
                    x = x->_M_right;
            }

            iterator j = iterator(y);

            if (cmp)
            {
                if (j == begin())
                    return insert_pos(x, y);
                else
                    --j;
            }
            if (j->first < key)
                return insert_pos(x, y);

            return insert_pos(j._M_node, nullptr);
        }

        // base by libstdc++
        iterator _M_insert_(_Base_ptr x, _Base_ptr p, const value_type &val)
        {
            bool insert_left = (x || p == _M_header || val.first < static_cast<node *>(p)->_M_value_field.first);

            node *res = _M_create_node(val);
            std::_Rb_tree_insert_and_rebalance(insert_left, res, p, *_M_header);
            ++_M_size;

            return iterator(res);
        }

        // base by libstdc++
        iterator _M_insert_(_Base_ptr x, _Base_ptr p, value_type &&val)
        {
            bool insert_left = (x || p == _M_header || val.first < static_cast<node *>(p)->_M_value_field.first);

            node *res = _M_create_node(std::move(val));
            std::_Rb_tree_insert_and_rebalance(insert_left, res, p, *_M_header);
            ++_M_size;

            return iterator(res);
        }

        // base by libstdc++
        insert_result _M_insert_unique(const value_type &val)
        {
            insert_pos pos = _M_get_insert_unique_pos(val.first);

            if (pos.second)
                return insert_result(_M_insert_(pos.first, pos.second, val), true);

            return insert_result(iterator(pos.first), false);
        }

        // base by libstdc++
        insert_result _M_insert_unique(value_type &&val)
        {
            insert_pos pos = _M_get_insert_unique_pos(val.first);

            if (pos.second)
                return insert_result(_M_insert_(pos.first, pos.second, std::move(val)), true);

            return insert_result(iterator(pos.first), false);
        }

    private:
        // Node controlling functions

        node *_M_get_node()
        {
            // フリーリストから確保
            if (node *node = _M_pop_free_node())
                return node;

            // 残ってるノードから確保
            if (_M_cur != _M_end)
                return _M_cur++;

            size_t count = 0;

            // 初回は1ノードだけ
            if (!_M_node_chunk)
                count = 1;

            // 2回目以降は一度に複数確保
            else
            {
                size_t size = _M_node_chunk->_M_size;
                size_t grow = size + (size >> 1) + (size >> 3);
                count       = std::max(size + 1, grow);
            }

            _M_node_chunk = _M_create_chunk(count);

            node *begin = _M_node_chunk->_M_nodes;
            _M_cur      = begin + 1;
            _M_end      = begin + count;

            return begin;
        }

        void _M_reserve_nodes(size_t n)
        {
            if (_M_node_chunk)
                return;

            _M_node_chunk = _M_create_chunk(n);

            node *begin = _M_node_chunk->_M_nodes;
            _M_cur      = begin;
            _M_end      = begin + n;
        }

        node *_M_pop_free_node()
        {
            node *n = _M_free;

            // 切り離し
            if (n)
                _M_free = static_cast<node *>(n->_M_right);

            return n;
        }

        void _M_push_free_node(node *node)
        {
            // 連結
            node->_M_right = _M_free;
            _M_free        = node;
        }

    private:
        // Creation functions

        node_chunk *_M_create_chunk(size_t size)
        {
            return new (_Alloc::allocate(sizeof(node_chunk))) node_chunk(_M_node_chunk, size);
        }

        node *_M_create_node(const value_type &val)
        {
            node *res = _M_get_node();
            _M_construct_node(res, std::piecewise_construct, std::forward_as_tuple(val.first), std::forward_as_tuple(val.second));
            return res;
        }

        node *_M_create_node(value_type &&val)
        {
            node *res = _M_get_node();
            _M_construct_node(res, std::piecewise_construct, std::forward_as_tuple(std::move(val.first)), std::forward_as_tuple(std::move(val.second)));
            return res;
        }

        void _M_create_and_set_header()
        {
            if (_M_header)
                return;

            header *h = reinterpret_cast<header *>(_M_get_node());
            _M_construct_header(h);
            _M_header = h;
        }

    private:
        // Destroy functions

        void _M_destroy_node(node *destroy)
        {
            _M_destruct_node(destroy);
            _M_push_free_node(destroy);
        }

    private:
        node_chunk *_M_node_chunk;    // +0x0
        node       *_M_free;    // +0x4
        node       *_M_cur;    // +0x8
        node       *_M_end;    // +0xC
        header     *_M_header;    // +0x10
        size_t      _M_size;    // +0x14
        bool        mUnk4;    // +0x18
        bool        mUnk5;    // +0x19
    };

}    // namespace MC3DSPluginFramework::gstd