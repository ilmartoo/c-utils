#pragma once
#ifndef __ILMARTO_HELPERS_H_
#define __ILMARTO_HELPERS_H_

#include <stddef.h>

// Retrieves the maximum value
#define max(a, b) (((a) > (b)) ? (a) : (b))
// Retrieves the minimum value
#define min(a, b) (((a) < (b)) ? (a) : (b))
// Allocates a new element in the heap
#define reserve(data_type) (data_type *)malloc(sizeof(data_type))
// Allocates a new array of elements in the heap
#define reserve_array(data_type, number_of_elements) (data_type *)malloc(sizeof(data_type) * number_of_elements)
// Retrieves the size of an array
#define countof(array) (size_t)(sizeof(array) / sizeof(*(array)))
// Retrieves the size of a string
#define lengthof(str) (countof(str) - 1)

#endif // __ILMARTO_HELPERS_H_
