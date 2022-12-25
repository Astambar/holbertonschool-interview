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

/* Vérifie que le nouveau noeud respecte la propriété de tas binaire */
heap_t *current = node;
check_heap_property(current);

return (node);
}

/**
 * check_heap_property - Check that the value of a node
 * is greater than or equal to its parent
 *
 * @current: Pointer to the node to check
 *
 * If the value of the node
 * is greater than that of its parent, swap the two nodes.
 * Repeat until the heap property is satisfied.
 */

void check_heap_property(heap_t *current)
{
while (current->parent && current->n > current->parent->n)
{
	int temp = current->n;

	current->n = current->parent->n;
	current->parent->n = temp;
	current = current->parent;
}
}
