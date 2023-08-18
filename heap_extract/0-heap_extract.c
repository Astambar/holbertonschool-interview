#include "binary_trees.h"

/**
 * heap_extract - Extracts the root node of a Max Binary Heap
 * @root: Double pointer to the root node of the heap
 * Return: Value stored in the root node, or 0 on failure
 */
int heap_extract(heap_t **root)
{
	if (root == NULL || *root == NULL)
		return (0);

	int value = (*root)->n;
	binary_tree_t *last_node = get_last_node(*root);

	if (last_node != *root)
		replace_root_with_last(root, last_node);
	else
	{
		free(*root);
		*root = NULL;
		return (value);
	}

	heapify_after_extract(*root);

	return (value);
}

/**
 * get_last_node - Finds the last node of a binary tree
 * @root: Root node of the tree
 * Return: Pointer to the last node
 */
binary_tree_t *get_last_node(binary_tree_t *root)
{
	binary_tree_t *last_node = root;

	while (last_node->right)
		last_node = last_node->right;

	return (last_node);
}

/**
 * replace_root_with_last - Replaces the root node with the last node
 * @root: Double pointer to the root node
 * @last: Pointer to the last node
 */
void replace_root_with_last(binary_tree_t **root, binary_tree_t *last)
{
	if (last->parent->right == last)
		last->parent->right = NULL;
	else
		last->parent->left = NULL;

	(*root)->n = last->n;
	free(last);
}

/**
 * heapify_after_extract - Rebuilds the Max Binary Heap after extraction
 * @root: Pointer to the root node
 */
void heapify_after_extract(binary_tree_t *root)
{
	binary_tree_t *temp = root;

	while (temp->left)
	{
		binary_tree_t *largest = temp->left;

		if (temp->right && temp->right->n > temp->left->n)
			largest = temp->right;

		if (temp->n >= largest->n)
			break;

		swap_values(&(temp->n), &(largest->n));

		temp = largest;
	}
}

/**
 * swap_values - Swaps two integer values
 * @a: Pointer to the first value
 * @b: Pointer to the second value
 */
void swap_values(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
