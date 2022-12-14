#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - Insère un nouveau noeud dans une liste chaînée triée
 * @head: Pointeur vers la tête de la liste chaînée
 * @number: La valeur à insérer dans le nouveau noeud
 * Return: un pointeur vers le nouveau noeud créé, ou NULL en cas d'échec
 */

    
listint_t *insert_node(listint_t **head, int number)
{
    listint_t *new_node;
    listint_t **current = head;

    new_node = malloc(sizeof(listint_t));
    if (!new_node)
        return NULL;

    new_node->n = number;
    new_node->next = NULL;

    if (!*head)
    {
        *head = new_node;
        return new_node;
    }

    while (*current && number > (*current)->n)
    {
        current = &(*current)->next;
    }

    new_node->next = *current;
    *current = new_node;

    return new_node;
}
