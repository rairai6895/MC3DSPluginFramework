#ifndef GSTD_HPP
#define GSTD_HPP

#include "Function.hpp"
#include "gstd_alloc.hpp"
#include "gstd_string.hpp"
#include "gstd_vector.hpp"
#include <cstring>
#include <stdarg.h>

namespace MC3DSPluginFramework {

#define MC_NULLPTR (void *)0xB3EB10

/**
 *  Game standard Functions.
 *  Do not use while the game thread is stopped.
 */
namespace gstd {

void memcpy(void *dest, void *src, size_t size);
size_t strlen(const char *str);
int vsnprintf(char *buffer, size_t size, const char *fmt, va_list vals);
gstd::string format(const char *fmt, ...);

}    // namespace gstd
}    // namespace MC3DSPluginFramework

#endif