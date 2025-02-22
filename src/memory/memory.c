#include "memory.h"

void *memory_copy(void *dest, void *const src, size_t size)
{
    for (char *d = dest, *s = src; size; --size, ++d, ++s) { *d = *s; }
    return dest;
}
