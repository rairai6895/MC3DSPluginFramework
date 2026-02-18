#pragma once

#include <Minecraft/Common/Heap.hpp>
#include <types.h>
#include <utility>

namespace MC3DSPluginFramework::gstd
{

    inline size_t memsize(void *memory)
    {
        return *((u32 *)memory - 3);
    }

    inline void *malloc(size_t size)
    {
        return Heap::alloc(size, Heap::Type::Default, 4, 0);
    }

    inline void free(void *memory)
    {
        // 0x1146E8
        // 0x2FEA60 -> 0x1146E8
        // 0x2FF2F0) -> 0x1146E8
        // 0x1007D0 | 1 -> 0x2FF2F0
        reinterpret_cast<void (*)(void *, int)>(0x1146E8)(memory, -1);
    }

    void *calloc(size_t size, size_t dataSize);
    void *realloc(void *memory, size_t new_size);

    // 基本的にgstd::mallocを使用するoperator newを持たないオブジェクトで使う用
    template <typename T>
    inline T *_new(T &&object)
    {
        if (T *memory = (T *)gstd::malloc(sizeof(T)))
            return new (memory) T(std::move(object));

        return nullptr;
    }

    // 基本的にgstd::freeを使用するoperator deleteを持たないオブジェクトで使う用
    template <typename T>
    inline void _delete(T *memory, size_t size = 1)
    {
        if (memory && size) {
            for (size_t i = 0; i < size; ++i)
                (memory + i)->~T();

            gstd::free(memory);
        }
    }

}    // namespace MC3DSPluginFramework::gstd