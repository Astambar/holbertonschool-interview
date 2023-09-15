#include "sort.h"

/**
 * merge_sort - trie un tableau d'entiers par ordre croissant
 * en utilisant l'algorithme de tri par fusion descendante
 * @array: tableau d'entiers à trier
 * @size: taille du tableau d'entiers à trier
 */

void merge_sort(int *array, size_t size)
{
	int *holder = malloc(sizeof(int) * size);

	if (holder == NULL)
		return;
	if (size <= 1 || array == NULL)
	{
		free(holder);
		return;
	}
	merge_sort_holder(array, size, holder);
	free(holder);
}

/**
 * merge_sort_holder - trie un tableau d'entiers par ordre croissant
 * en utilisant l'algorithme de tri par fusion descendante
 * et inclut un tableau temporaire pour conserver
 * les informations pendant la fusion
 * @array: tableau d'entiers à trier
 * @size: taille du tableau d'entiers à trier
 * @holder: tableau temporaire pour conserver
 * les informations pendant la fusion
 */

void merge_sort_holder(int *array, size_t size, int *holder)
{
	int mid = size / 2;

	if (size <= 1)
		return;

	merge_sort_holder(array, mid, holder);
	merge_sort_holder(&array[mid], size - mid, holder);
	merge(holder, array, mid, size);
}

/**
 * merge - fusionne deux sous-tableaux triés en un seul tableau trié
 * @holder: tableau temporaire pour conserver les informations
 * pendant la fusion
 * @array: tableau à fusionner
 * @mid: indice du point médian
 * @size: taille du tableau à fusionner
 */

void merge(int *holder, int *array, int mid, size_t size)
{
	int left = 0, right = mid, index = 0;

	printf("Merging...\n[left]: ");
	print_array(array, mid);
	printf("[right]: ");
	print_array(&array[mid], size - mid);
	while (left < mid && right < (int)size)
	{
		if (array[left] <= array[right])
		{
			holder[index] = array[left];
			left++;
		}
		else
		{
			holder[index] = array[right];
			right++;
		}
		index++;
	}
	while (left < mid)
	{
		holder[index] = array[left];
		left++;
		index++;
	}
	while (right < (int)size)
	{
		holder[index] = array[right];
		right++;
		index++;
	}
	for (index = 0; index < (int)size; index++)
		array[index] = holder[index];
	printf("[Done]: ");
	print_array(array, size);
}
