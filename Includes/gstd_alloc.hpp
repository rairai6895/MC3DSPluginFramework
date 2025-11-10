#ifndef GSTD_ALLOC_HPP
#define GSTD_ALLOC_HPP

#include <types.h>
#include <utility>

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
inline T *_new(T &&object) {
    if (T *memory = (T *)gstd::malloc(sizeof(T)))
        return new (memory) T(std::move(object));

    return nullptr;
}

template <typename T, size_t size>
inline T *_new(T (&object)[size]) {
    if (T *memory = (T *)gstd::malloc(sizeof(T) * size)) {
        for (size_t i = 0; i < size; ++i)
            new (memory + i) T(std::move(object[i]));

        return memory;
    }

    return nullptr;
}

template <typename T>
inline void _delete(T *memory, size_t size = 1) {
    if (memory && size) {
        for (size_t i = 0; i < size; ++i)
            (memory + i)->~T();

        gstd::free(memory);
    }
}

}    // namespace gstd
}    // namespace MC3DSPluginFramework

#endif