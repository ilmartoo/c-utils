#pragma once
#ifndef _SINGLE_LISTED_LIST_H_
#define _SINGLE_LISTED_LIST_H_

#include "types.h"
#include <stdlib.h>

// Single-linked list element definition
typedef void* SingleLinkedListElement;

// Single-linked list type
typedef void* SingleLinkedList;

// Creates a new linked list
SingleLinkedList sll_new();

// Deletes the linked list
void sll_delete(SingleLinkedList sll);

// Inserts an element at the back of the list
bool sll_push(SingleLinkedList sll, SingleLinkedListElement element);

// Interts an element at the front of the list
bool sll_unshift(SingleLinkedList sll, SingleLinkedListElement element);

// Removes the last element from the list and returns it
SingleLinkedListElement sll_pop(SingleLinkedList sll);

// Removes the first element from the list and returns it
SingleLinkedListElement sll_shift(SingleLinkedList sll);

#endif // _SINGLE_LISTED_LIST_H_