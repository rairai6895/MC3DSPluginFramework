#ifndef GSTD_ALLOC_HPP
#define GSTD_ALLOC_HPP

#include <types.h>

namespace MC3DSPluginFramework {
/**
 *  Game standard Functions.
 *  Do not use while the game thread is stopped.
 */
namespace gstd {

size_t memsize(void *memory);
void *malloc(size_t size);
void free(void *memory);
void *calloc(size_t size, size_t dataSize);
void *realloc(void *memory, size_t new_size);

template <typename T>
inline T *_new(size_t size = 1) {
    if (size)
        if (T *memory = (T *)gstd::malloc(sizeof(T) * size)) {
            for (size_t i = 0; i < size; ++i)
                new (memory + i) T();

            return memory;
        }

    return nullptr;
}

template <typename T>
inline T *_new(void *memory, size_t size = 1) {
    if (memory && size)
        for (size_t i = 0; i < size; ++i)
            new ((T *)memory + i) T();

    return memory;
}

template <typename T>
inline void _delete(T *memory, size_t size) {
    if (memory && size) {
        for (size_t i = 0; i < size; ++i)
            (memory + i)->~T();

        gstd::free(memory);
    }
}

}    // namespace gstd
}    // namespace MC3DSPluginFramework

#endif