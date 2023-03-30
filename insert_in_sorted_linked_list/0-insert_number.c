#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * get_previous_node_for_insertion - Trouve le point d'insertion
 * pour un nouveau noeud dans une liste chaînée triée
 * @head: Pointeur vers la tête de la liste chaînée
 * @number: La valeur à insérer dans le nouveau noeud
 * Return: un double pointeur vers le nœud précédent
 * où le nouveau nœud doit être inséré
 */
listint_t **get_previous_node_for_insertion(listint_t **head, int number)
{
	/* Pointe vers la tête de la liste chaînée */
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
	/* Alloue de l'espace pour le nouveau noeud */
	listint_t *new_node;
	/* Pointe vers l'endroit où insérer le nouveau noeud */
	listint_t **insertion_point;

	new_node = malloc(sizeof(listint_t));
	if (!new_node)
		return (NULL);

	/* Initialise le nouveau noeud */
	new_node->n = number;
	new_node->next = NULL;

	/* Si la liste est vide, ajoute le nouveau noeud en tant que tête */
	if (!*head)
	{
		*head = new_node;
		return (new_node);
	}

	/* Trouve l'endroit où insérer le nouveau noeud */
	insertion_point = get_previous_node_for_insertion(head, number);

	/* Insère le nouveau noeud avant le point d'insertion */
	insert_node_before(insertion_point, new_node);

	/* Retourne le pointeur vers le nouveau noeud créé */
	return (new_node);
}

/**
 * insert_node_before - Insère un nouveau noeud
 * dans une liste chaînée à l'emplacement spécifié
 * @insertion_point: Double pointeur vers le nœud précédent
 * où le nouveau nœud doit être inséré
 * @new_node: Pointeur vers le nouveau noeud à insérer
 */
void insert_node_before(listint_t **insertion_point, listint_t *new_node)
{
	/* Insère le nouveau noeud avant le point d'insertion */
	new_node->next = *insertion_point;
	*insertion_point = new_node;
}
