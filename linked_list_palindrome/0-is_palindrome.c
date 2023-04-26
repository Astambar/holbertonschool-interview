#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * is_palindrome - Vérifie si la liste chainée est un palindrome
 * @head: Pointeur double vers le type de noeud listint_s
 * Return: 1 si c'est un palindrome, 0 sinon
 */

int is_palindrome(listint_t **head)
{
	if (head == NULL || *head == NULL)
		return (1);
	else
		return (palindrome_recursif(head, *head));
}

/**
 * palindrome_recursif - Fonction récursive qui parcourt chaque noeud en parallèle
 * @head: Pointeur double vers le type de noeud listint_s (aka tête)
 * @queue: Pointeur vers le type de noeud listint_s (aka queue)
 * Return: 1 si c'est un palindrome, sinon 0
 */
int palindrome_recursif(listint_t **head, listint_t *queue)
{
	if (queue == NULL)
		return (1);

	if (palindrome_recursif(head, queue->next) && (*head)->n == queue->n)
	{
		*head = (*head)->next;
		return (1);
	}
	else
		return (0);
}
