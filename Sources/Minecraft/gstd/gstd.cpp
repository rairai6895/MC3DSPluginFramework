#include "Minecraft/gstd/gstd.hpp"

namespace MC3DSPluginFramework::gstd {

void *calloc(size_t size, size_t dataSize) {
    if (size > 0 && dataSize > 0) {

        if (dataSize > SIZE_MAX / size)
            return nullptr;

        size_t allocSize = dataSize * size;

        if (void *memory = gstd::malloc(allocSize)) {
            memset(memory, 0, allocSize);
            return memory;
        }
    }
    return nullptr;
}

void *realloc(void *memory, size_t new_size) {
    if (memory) {
        size_t old_size = gstd::memsize(memory);

        if (old_size >= new_size)
            return memory;

        if (u8 *newMemory = (u8 *)gstd::malloc(new_size)) {
            for (size_t i = 0; i < old_size; ++i)
                newMemory[i] = ((u8 *)memory)[i];

            gstd::free(memory);
            return newMemory;
        }
    }
    return nullptr;
}

}    // namespace MC3DSPluginFramework::gstd