#include "search.h"

/**
 * create_skiplist - Creates a skip list from an array of integers
 * @array: Pointer to the first element of the array
 * @size: Size of the array
 *
 * Return: Pointer to the head of the created skip list, or NULL on failure
 */
skiplist_t *create_skiplist(int *array, size_t size)
{
    skiplist_t *list = NULL, *new = NULL, *temp = NULL;
    size_t i;

    if (size == 0)
        return (NULL);

    for (i = 0; i < size; i++)
    {
        new = malloc(sizeof(skiplist_t));
        if (new == NULL)
        {
            free_skiplist(list);
            return (NULL);
        }
        new->n = array[i];
        new->index = i;
        new->express = NULL;

        if (list == NULL)
        {
            new->next = NULL;
            list = new;
        }
        else
        {
            new->next = list;
            list = new;
        }

        if (i == 0 || i % 2 == 0)
            temp = new;
        else
        {
            temp->express = new;
            temp = temp->next;
        }
    }

    return (list);
}

/**
 * print_skiplist - Prints a skip list
 * @list: Pointer to the head of the skip list
 */
void print_skiplist(const skiplist_t *list)
{
    const skiplist_t *temp = list;

    printf("List:\n");
    while (temp != NULL)
    {
        printf("Index[%lu] = [%d]\n", temp->index, temp->n);
        temp = temp->next;
    }

    printf("\nExpress lane:\n");
    temp = list;
    while (temp != NULL)
    {
        printf("Index[%lu] = [%d]\n", temp->index, temp->n);
        temp = temp->express;
    }
}

/**
 * free_skiplist - Frees a skip list
 * @list: Pointer to the head of the skip list
 */
void free_skiplist(skiplist_t *list)
{
    skiplist_t *temp;

    while (list != NULL)
    {
        temp = list;
        list = list->next;
        free(temp);
    }
}

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
    skiplist_t *current = list, *prev;

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
        while (current->next)
        {
            prev = current;
            current = current->next;
        }
        printf("Value found between indexes [%lu] and [%lu]\n", prev->index, current->index);
    }

    while (prev != current->next && prev->n < value)
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
