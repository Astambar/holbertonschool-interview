#include <stdlib.h>
#include "binary_trees.h"

/**
 * heap_insert - Insert a value into a Max Binary Heap
 *
 * @root: Double pointer to the root node of the Heap
 * @value: Value to store in the node to be inserted
 *
 * Return: Pointer to the inserted node, or NULL on failure
 */

heap_t *heap_insert(heap_t **root, int value)
{
heap_t *node = NULL;
heap_t *temp = NULL;

if (!root)
	return (NULL);

node = malloc(sizeof(*node));
if (!node)
	return (NULL);

node->n = value;
node->left = node->right = NULL;
if (!*root)
{
	*root = node;
	return (node);
}

temp = *root;
while (temp)
{
	if (temp->left && !temp->right)
	{
		temp->right = node;
		break;
	}
	else if (!temp->left)
	{
		temp->left = node;
		break;
	}
	temp = temp->left;
}
node->parent = temp;

return (node);
}
