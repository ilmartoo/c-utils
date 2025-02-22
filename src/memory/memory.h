#pragma once
#ifndef __ILMARTO_MEMORY_H_
#define __ILMARTO_MEMORY_H_

#ifndef size_t
typedef unsigned long long size_t;
#endif

/**
 * Copies the specified number of bytes from a source to a destination.
 * @param dest Destination memory space.
 * @param src Source memory space.
 * @param bytes Number of bytes to copy.
 * @return Reference to the destination memory space.
 */
void *memory_copy(void *dest, const void *src, size_t bytes);
/**
 * Copies the bytes of a type from a source to a destination.
 * @param dest Destination memory space.
 * @param src Source memory space.
 * @param type Type to copy.
 * @return Reference to the destination memory space.
 */
#define memory_copy_type(dest, src, type) ((type *)memory_copy(dest, src, sizeof(type)))

#endif // __ILMARTO_MEMORY_H_
