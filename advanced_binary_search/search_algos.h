#ifndef SEARCH_ALGOS_H
#define SEARCH_ALGOS_H

#include <stddef.h>

/* Function prototype for recursive array printing */
void recursive_print_array(int *array, size_t left, size_t right);
int advanced_binary_recursive(int *array, size_t left, size_t right, int value);
/* Function prototype */
int advanced_binary(int *array, size_t size, int value);

#endif /* SEARCH_ALGOS_H */
