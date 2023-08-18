#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stddef.h>
#include <stdlib.h>

/* Structure for binary tree nodes */
struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;

/* Structure for binary heap nodes */
typedef struct binary_tree_s heap_t;

/* Function to extract the root node of a Max Binary Heap */
int heap_extract(heap_t **root);
void swap_values(int *a, int *b);
void heapify_after_extract(binary_tree_t *root);
void replace_root_with_last(binary_tree_t **root, binary_tree_t *last);
binary_tree_t *get_last_node(binary_tree_t *root);
#endif /* BINARY_TREES_H */
