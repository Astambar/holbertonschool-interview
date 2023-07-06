#include "search.h"

/**
 * linear_skip - Searches for a value in a sorted skip list of integers
 * @list: Pointer to the head of the skip list
 * @value: Value to search for
 *
 * Return: Pointer to the first node where value is located,
 *         or NULL if value is not present or if head is NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
    skiplist_t *current = list, *prev = NULL;

    if (list == NULL)
        return (NULL);

    while (current->express && current->n < value)
    {
        prev = current;
        current = current->express;
        printf("Value checked at index [%lu] = [%d]\n", current->index, current->n);
    }

    if (current->n >= value)
    {
        printf("Value found between indexes [%lu] and [%lu]\n", prev->index, current->index);
        current = prev;
    }
    else
    {
        prev = current;
        while (current->next && current->n < value)
        {
            prev = current;
            current = current->next;
        }
        printf("Value found between indexes [%lu] and [%lu]\n", prev->index, current->index);
    }

    while (prev && prev != current->next && prev->n < value)
    {
        printf("Value checked at index [%lu] = [%d]\n", prev->index, prev->n);
        if (prev->n == value)
            return (prev);
        prev = prev->next;
    }

    printf("Value checked at index [%lu] = [%d]\n", prev->index, prev->n);
    if (prev->n == value)
        return (prev);

    return (NULL);
}
