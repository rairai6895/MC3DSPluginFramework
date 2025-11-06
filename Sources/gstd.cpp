#include "gstd.hpp"

namespace MC3DSPluginFramework {
namespace gstd {

size_t memsize(void *memory) {
    return *((u32 *)memory - 3);
}

void *malloc(size_t size) {
    // normal = 0x1010CA | 1
    return Function<void *>(0x11493C)(size);
}

void free(void *memory) {
    Function<void>(0x1007D0, true)(memory);
}

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

void memcpy(void *dest, void *src, size_t size) {
    Function<void>(0x12CE5C)(dest, src, size);
}

size_t strlen(const char *str) {
    return Function<size_t>(0x2FE990)(str);
}

int vsnprintf(char *buffer, size_t size, const char *fmt, va_list vals) {
    return Function<int>(0x100120, true)(buffer, size, fmt, vals);
}

gstd::string format(const char *fmt, ...) {
    char buffer[0x100] = {0};
    va_list argList;
    va_start(argList, fmt);
    gstd::vsnprintf(buffer, sizeof(buffer), fmt, argList);
    va_end(argList);
    return gstd::string(buffer);
}

}    // namespace gstd
}    // namespace MC3DSPluginFramework