#include "lists.h"

/**
 * is_palindrome - checks if the linked list is a palindrome
 * @head: pointer to the head of the linked list
 * Return: 1 if it is a palindrome, 0 otherwise
 */
int is_palindrome(listint_t **head)
{
    if (!head)
        return (1);
    if (!*head)
        return (1);

    int length = 0;
    listint_t *current = *head;

    while (current != NULL)
    {
        current = current->next;
        length++;
    }

    return check_palindrome(head, length);
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

    fill_stack(stack, current, length);
    result = compare_stack_to_list(stack, current, length);
    free(stack);

    return result;
}



/**
 * fill_stack - fills a stack with the first half of a linked list
 * @stack: array to be filled
 * @current: pointer to current node of linked list
 * @length: length of the linked list
 * Return: void
 */
void fill_stack(int *stack, listint_t *current, int length)
{
    int i = 0;
    while (i < length / 2)
    {
        stack[i] = current->n;
        current = current->next;
        i++;
    }
}

/**
 * compare_stack_to_list - compares the stack to the second half of the linked list
 * @stack: the stack to compare
 * @current: pointer to the current node of the linked list
 * @length: the length of the linked list
 * Return: 1 if the stack and second half of the list match, 0 otherwise
 */
int compare_stack_to_list(int *stack, listint_t *current, int length)
{
    int i;
    if (length % 2 != 0)
    {
        current = current->next;
    }
    i = length / 2 - 1;
    while (current != NULL)
    {
        if (stack[i] != current->n)
        {
            return 0;
        }
        current = current->next;
        i--;
    }
    return 1;
}
