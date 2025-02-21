#include <stdlib.h>
#include <string.h>
#include "arena.h"

#define DEFAULT_ARENA_PAGE_BYTE_SIZES 1024

Arena areana_create_custom(size_t size) { return (Arena){malloc(size), size, 0}; }

Arena arena_create(void) { return areana_create_custom(DEFAULT_ARENA_PAGE_BYTE_SIZES); }

void areana_delete(Arena *arena) { free(arena->memory); };

void *arena_push(Arena *arena, size_t size)
{
    if (arena->memory_size - arena->memory_pos < size)
    {
        do {
            arena->memory_size *= 2;
        } while (arena->memory_size - arena->memory_pos < size);
        arena->memory = realloc(arena->memory, arena->memory_size);
    }
    void *allocPos = (void *)((size_t)arena->memory + arena->memory_pos);
    arena->memory_pos += size;
    return allocPos;
}

void *arena_push_zero(Arena *arena, size_t size)
{
    void *allocPos = arena_push(arena, size);
    memset(allocPos, 0, size);
    return allocPos;
}

void arena_pop(Arena *arena, size_t size) { arena->memory_pos = arena->memory_pos < size ? 0 : arena->memory_pos - size; }

void areana_delete(Arena *arena) { arena->memory_pos = 0; }

size_t arena_size(Arena arena) { return arena.memory_pos; }
