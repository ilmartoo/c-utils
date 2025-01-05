#include "single_linked_list.h"
#include "types.h"
#include <stdlib.h>

// Single-linked list element definition
// typedef int SingleLinkedListElement;

typedef struct {
    SingleLinkedListElement element;
    SingleLinkedListNode* next;
} SingleLinkedListNode;

typedef struct SingleLinkedList {
    size_t size;
    SingleLinkedListNode* elements;
}* SingleLinkedList;

SingleLinkedList sll_new()
{
    SingleLinkedList sll = (SingleLinkedList)malloc(sizeof(struct SingleLinkedList));
    sll->size = 0;
    sll->elements = NULL;
    return sll;
}

SingleLinkedListNode* create_node(SingleLinkedListElement element)
{
    SingleLinkedListNode* node = (SingleLinkedListNode*)malloc(sizeof(SingleLinkedListNode));
    node->element = element;
    node->next = NULL;
    return node;
}

void sll_delete(SingleLinkedList sll)
{
    SingleLinkedListNode* node = sll->elements;
    while (node != NULL) {
        SingleLinkedListNode* next_node = node->next;
        free(node);
        node = next_node;
    }
}

bool sll_push(SingleLinkedList sll, SingleLinkedListElement element)
{
    SingleLinkedListNode* new_node = create_node(element);

    if (new_node == NULL) {
        return false;
    }

    if (sll->elements == NULL) {
        sll->elements = new_node;
    } else {
        SingleLinkedListNode* node = sll->elements;
        while (node->next != NULL) {
            node = node->next;
        }
        node->next = new_node;
    }
    sll->size += 1;
    return true;
}

bool sll_unshift(SingleLinkedList sll, SingleLinkedListElement element)
{
    SingleLinkedListNode* new_node = create_node(element);

    if (new_node == NULL) {
        return false;
    }

    if (sll->elements == NULL) {
        sll->elements = new_node;
    } else {
        new_node->next = sll->elements;
        sll->elements = new_node;
    }
    sll->size += 1;
    return true;
}

SingleLinkedListElement sll_pop(SingleLinkedList sll)
{
    if (sll->elements == NULL || sll->size == 0) {
        return NULL;
    }

    SingleLinkedListNode* node = sll->elements;
    while (node->next != NULL) {
        node = node->next;
    }
    SingleLinkedListElement removed_element = node->element;

    free(node);
    sll->size -= 1;

    return removed_element;
}

SingleLinkedListElement sll_shift(SingleLinkedList sll)
{
    if (sll->elements == NULL || sll->size == 0) {
        return NULL;
    }

    SingleLinkedListNode* node = sll->elements;
    SingleLinkedListNode* next_node = node->next;
    sll->elements = next_node;

    SingleLinkedListElement removed_element = node->element;

    free(node);
    sll->size -= 1;

    return removed_element;
}
