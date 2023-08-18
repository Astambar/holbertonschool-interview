#include "binary_trees.h"

/**
 * heap_extract - Extracts the root node of a Max Binary Heap
 * @root: Double pointer to the root node of the heap
 * Return: Value stored in the root node, or 0 on failure
 */
int heap_extract(heap_t **root)
{
    if (root == NULL || *root == NULL)
        return 0;

    int value = (*root)->n;
    binary_tree_t *last_node = *root;
    binary_tree_t *temp = *root;

    /* Find the last node of the heap */
    while (last_node->right)
        last_node = last_node->right;

    /* Swap root value with last node value */
    (*root)->n = last_node->n;

    /* Remove last node */
    if (last_node->parent->right == last_node)
        last_node->parent->right = NULL;
    else
        last_node->parent->left = NULL;

    free(last_node);

    /* Rebuild the heap */
    while (temp->left)
    {
        binary_tree_t *largest = temp->left;

        if (temp->right && temp->right->n > temp->left->n)
            largest = temp->right;

        if (temp->n >= largest->n)
            break;

        int temp_value = temp->n;
        temp->n = largest->n;
        largest->n = temp_value;

        temp = largest;
    }

    return value;
}
