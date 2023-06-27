#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stddef.h>

/* Basic Binary Tree */
struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;

/* AVL Tree */
typedef struct binary_tree_s avl_t;

/* untile Function */
void binary_tree_print(const binary_tree_t *tree);

/* Function prototypes */
avl_t *sorted_array_to_avl(int *array, size_t size);

/*Secondaire Function */
avl_t *recursive_build(int *array, int start, int end);
avl_t *create_node(int value);

#endif /* BINARY_TREES_H */
