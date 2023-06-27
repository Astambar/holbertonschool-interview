#include <stdlib.h>
#include "binary_trees.h"

/**
 * create_node - Crée un nouveau nœud avec la valeur donnée
 * @value: La valeur à stocker dans le nouveau nœud
 *
 * Return: Un pointeur vers le nouveau nœud, ou NULL en cas d'échec
 */
avl_t *create_node(int value)
{
	avl_t *node = malloc(sizeof(avl_t));

	if (!node)
		return (NULL);

	node->n = value;
	node->parent = NULL;
	node->left = NULL;
	node->right = NULL;

	return (node);
}

/**
 * recursive_build - Construit de manière récursive un arbre AVL
 *                    à partir d'un tableau trié
 * @array: Le tableau trié pour construire l'arbre
 * @start: L'index de départ du tableau
 * @end: L'index de fin du tableau
 *
 * Return: Un pointeur vers le nœud racine de l'arbre AVL créé,
 *          ou NULL en cas d'échec
 */
avl_t *recursive_build(int *array, int start, int end)
{
	int mid;
	avl_t *root;

	if (start > end)
		return (NULL);

	mid = (start + end) / 2;
	root = create_node(array[mid]);
	if (!root)
		return (NULL);

	root->left = recursive_build(array, start, mid - 1);
	root->right = recursive_build(array, mid + 1, end);

	if (root->left)
		root->left->parent = root;
	if (root->right)
		root->right->parent = root;

	return (root);
}

/**
 * sorted_array_to_avl - Construit un arbre AVL à partir d'un tableau trié
 * @array: Le tableau trié pour construire l'arbre
 * @size: La taille du tableau
 *
 * Return: Un pointeur vers le nœud racine de l'arbre AVL créé,
 *          ou NULL en cas d'échec
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array || size < 1)
		return (NULL);

	return (recursive_build(array, 0, size - 1));
}
