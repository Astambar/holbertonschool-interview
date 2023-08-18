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

#endif /* BINARY_TREES_H */
