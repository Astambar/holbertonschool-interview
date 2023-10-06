#include "list.h"
#include <stdlib.h>
#include <string.h>

/**
 * create_new_node - Crée un nouveau nœud de liste et copie
 * la chaîne de caractères dedans
 * @str: La chaîne de caractères à copier dans le nouveau nœud
 * Return: L'adresse du nouveau nœud, ou NULL en cas d'échec
 */
List *create_new_node(char *str)
{
	List *new_node = malloc(sizeof(List));

	if (new_node == NULL)
		return (NULL);

	new_node->str = strdup(str);
	if (new_node->str == NULL)
	{
		free(new_node);
		return (NULL);
	}

	return (new_node);
}

/**
 * add_node_end - Ajoute un nouveau nœud à la fin d'une liste
 * doublement chaînée circulaire
 * @list: Pointeur vers la liste à modifier
 * @str: La chaîne de caractères à copier dans le nouveau nœud
 * Return: L'adresse du nouveau nœud, ou NULL en cas d'échec
 */
List *add_node_end(List **list, char *str)
{
	List *new_node = create_new_node(str);

	if (new_node == NULL)
		return (NULL);

	if (*list == NULL)
	{
		new_node->prev = new_node;
		new_node->next = new_node;
		*list = new_node;
	}
	else
	{
		List *last_node = (*list)->prev;

		new_node->prev = last_node;
		new_node->next = *list;
		(*list)->prev = new_node;
		last_node->next = new_node;
	}

	return (new_node);
}

/**
 * add_node_begin - Ajoute un nouveau nœud au début d'une liste
 * doublement chaînée circulaire
 * @list: Pointeur vers la liste à modifier
 * @str: La chaîne de caractères à copier dans le nouveau nœud
 * Return: L'adresse du nouveau nœud, ou NULL en cas d'échec
 */
List *add_node_begin(List **list, char *str)
{
	List *new_node = create_new_node(str);

	if (new_node == NULL)
		return (NULL);

	if (*list == NULL)
	{
		new_node->prev = new_node;
		new_node->next = new_node;
		*list = new_node;
	}
	else
	{
		List *first_node = *list;

		new_node->prev = first_node->prev;
		new_node->next = first_node;
		first_node->prev->next = new_node;
		first_node->prev = new_node;
		*list = new_node;
	}

	return (new_node);
}
