#pragma once

#include <types.h>

namespace MC3DSPluginFramework::gstd {
// insertなどの完全再現は諦め
// 読み取り専用(Read only)
template <typename Key, typename Data>
class map {
  public:
    struct Node {
        u32 mColor;
        Node *mParent;    // ヘッダならroot
        Node *mLeft;      // ヘッダならbegin
        Node *mRight;     // ヘッダならend
        std::pair<const Key, Data> mData;

        void Destroy(void) { mData.~__pair_base(); }
    };

    struct NodeChunk {
        NodeChunk *mNext;
        size_t mSize;    // mNodesの中の要素数
        Node *mNodes;

        void Destroy(void) {
            if (mNodes) {
                for (size_t i = 0; i < mSize; ++i)
                    mNodes[i].Destroy();

                free(mNodes);
            }
        }
    };

    using Iter = Node *;

    ~map() {
        NodeChunk *current = mNodeChunk;
        while (current) {
            NodeChunk *next = current->mNext;
            current->Destroy();
            free(current);
            current = next;
        }
    }

    Iter find(const Key &key) {
        Node *cur = mHeader->mParent;
        while (cur) {
            if (cur->mKey < key)
                cur = cur->mRight;
            else if (key < cur->mKey)
                cur = cur->mLeft;
            else
                return cur;
        }
        return nullptr;
    }

    Data &operator[](const Key &key) {
        static Data fake;
        Node *cur = mHeader->mParent;
        while (cur) {
            if (cur->mKey < key)
                cur = cur->mRight;
            else if (key < cur->mKey)
                cur = cur->mLeft;
            else
                return cur->mData;
        }
        return fake;
    }

  private:
    NodeChunk *mNodeChunk;
    u32 mUnk1;
    u32 mUnk2;
    u32 mUnk3;
    Node *mHeader;
    u32 mSize;
    u32 mUnk4;    // u16?
};

}    // namespace MC3DSPluginFramework::gstd