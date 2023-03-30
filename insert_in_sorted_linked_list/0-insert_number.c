#include <stdio.h>
#include <stdlib.h>
#include "lists.h"


/**
 * find_insertion_point - Trouve le point d'insertion
 * pour un nouveau noeud dans une liste chaînée triée
 * @head: Pointeur vers la tête de la liste chaînée
 * @number: La valeur à insérer dans le nouveau noeud
 * Return: un double pointeur vers le nœud précédent
 * où le nouveau nœud doit être inséré
 */
listint_t **find_insertion_point(listint_t **head, int number)
{
	listint_t **current_node = head;

	while (*current_node && number > (*current_node)->n)
	{
		current_node = &(*current_node)->next;
	}

	return (current_node);
}

/**
 * insert_node - Insère un nouveau noeud dans une liste chaînée triée
 * @head: Pointeur vers la tête de la liste chaînée
 * @number: La valeur à insérer dans le nouveau noeud
 * Return: un pointeur vers le nouveau noeud créé, ou NULL en cas d'échec
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new_node;
	listint_t **insertion_point;

	new_node = malloc(sizeof(listint_t));
	if (!new_node)
		return (NULL);

	new_node->n = number;
	new_node->next = NULL;

	if (!*head)
	{
		*head = new_node;
		return (new_node);
	}

	insertion_point = find_insertion_point(head, number);
	insert_node_at_point(insertion_point, new_node);

	return (new_node);
}

/**
 * insert_node_at_point - Insère un nouveau noeud
 * dans une liste chaînée à l'emplacement spécifié
 * @insertion_point: Double pointeur vers le nœud précédent
 * où le nouveau nœud doit être inséré
 * @new_node: Pointeur vers le nouveau noeud à insérer
 */
void insert_node_at_point(listint_t **insertion_point, listint_t *new_node)
{
	new_node->next = *insertion_point;
	*insertion_point = new_node;
}
