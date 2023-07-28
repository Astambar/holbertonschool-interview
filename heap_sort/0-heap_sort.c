/* Fichier : 0-heap_sort.c */
#include "sort.h"

/**
 * sift_down - Effectue l'opération de "sift-down" sur le tas
 * @array: Le tableau à trier
 * @start: Indice de l'élément de départ
 * @end: Indice de l'élément de fin
 * @size: Taille du tableau
 */
void sift_down(int *array, size_t start, size_t end, size_t size)
{
	size_t root = start;
	size_t swap, left, right;

	while ((left = 2 * root + 1) <= end)
	{
		right = left + 1;
		swap = root;
		if (right <= end && array[right] > array[swap])
			swap = right;
		if (array[left] > array[swap])
			swap = left;
		if (swap == root)
			return;
		array[root] ^= array[swap];
		array[swap] ^= array[root];
		array[root] ^= array[swap];
		root = swap;
		print_array(array, size);
	}
}

/**
 * heap_sort - Trie un tableau d'entiers par ordre croissant
 * en utilisant l'algorithme Heap sort
 * @array: Le tableau à trier
 * @size: Taille du tableau
 */
void heap_sort(int *array, size_t size)
{
	size_t start = (size - 2) / 2;
	size_t end = size - 1;

	while (start > 0)
	{
		sift_down(array, start, end, size);
		start--;
	}

	sift_down(array, start, end, size);

	while (end > 0)
	{
		array[end] ^= array[0];
		array[0] ^= array[end];
		array[end] ^= array[0];
		print_array(array, size);
		end--;
		sift_down(array, 0, end, size);
	}
}
