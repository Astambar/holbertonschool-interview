#include "lists.h"

/**
 * is_palindrome - checks if the linked list is a palindrome
 * @head: pointer to the head of the linked list
 * Return: 1 if it is a palindrome, 0 otherwise
 */


int is_palindrome(listint_t **head)
{
    if (*head == NULL)
        return (1);

    int length = 0;
    listint_t *current = *head;

    while (current != NULL)
    {
        current = current->next;
        length++;
    }

    return (check_palindrome(head, length));
}


/**
 * check_palindrome - checks if a linked list is a palindrome
 * @head: pointer to pointer of first node of listint_t list
 * @length: length of the linked list
 * Return: 1 if the linked list is a palindrome, 0 otherwise
 */
int check_palindrome(listint_t **head, int length)
{
    int *stack = malloc(sizeof(int) * (length / 2));
    listint_t *current = *head;
    int result;

    fill_stack_with_first_half(&stack, &current, length);
    result = compare_second_half_with_stack(stack, current, length);
    free(stack);

    return (result);
}


/**
 * fill_stack_with_first_half - fills a stack with the first half of a linked list
 * @stack: array to be filled with the first half of the linked list
 * @current: pointer to current node of linked list
 * @length: length of the linked list
 * Return: void
 */
void fill_stack_with_first_half(int **stack, listint_t **current, int length)
{
    int i;

    for (i = 0; i < length / 2; i++)
    {
        (*stack)[i] = (*current)->n;
        (*current) = (*current)->next;
    }
}


/**
 * compare_second_half_with_stack - compares the second half of a linked list with a stack
 * @stack: array filled with the first half of the linked list
 * @current: pointer to current node of linked list
 * @length: length of the linked list
 * Return: 1 if the linked list is a palindrome, 0 otherwise
 */
int compare_second_half_with_stack(int *stack, listint_t *current, int length)
{
    int i;

    if (length % 2 != 0)
        current = current->next;

    for (i = length / 2 - 1; i >= 0; i--)
    {
        if (stack[i] != current->n)
            return (0);

        current = current->next;
    }

    return (1);
}


/**
 * is_even_list_length - checks if the list length is even
 * @length: length of the linked list
 * Return: 1 if the list is even, 0 otherwise
 */
int is_even_list_length(int length)
{
return ((length % 2 == 0)? 1 : 0);
}
