#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"

/**
 * recursive_print_array - Fonction récursive pour afficher le tableau.
 *
 * @array: Un pointeur vers le premier élément du tableau.
 * @left: L'index de gauche du sous-tableau actuel à afficher.
 * @right: L'index de droite du sous-tableau actuel à afficher.
 */
void recursive_print_array(int *array, size_t left, size_t right)
{
	if (left <= right)
	{
		printf("%d", array[left]);
		if (left < right)
			printf(", ");
		recursive_print_array(array, left + 1, right);
	}
}

/**
 * advanced_binary_recursive - Fonction auxiliaire récursive
 * pour advanced_binary.
 *
 * @array: Un pointeur vers le premier élément du tableau.
 * @left: L'index de gauche du sous-tableau actuel
 * dans lequel effectuer la recherche.
 * @right: L'index de droite du sous-tableau actuel
 * dans lequel effectuer la recherche.
 * @value: La valeur à rechercher.
 *
 * Return: L'index où se trouve la valeur, ou -1 s'il n'est pas trouvé.
 */
int advanced_binary_recursive(int *array, size_t left, size_t right, int value)
{
	size_t mid;

	if (array == NULL || left > right)
		return (-1);

	printf("Searching in array: ");
	recursive_print_array(array, left, right);
	printf("\n");

	mid = (left + right) / 2;

	if (array[mid] == value)
	{
		if (mid == 0 || array[mid - 1] != value)
			return (mid);
		return (advanced_binary_recursive(array, left, mid, value));
	}
	else if (array[mid] < value)
	{
		return (advanced_binary_recursive(array, mid + 1, right, value));
	}
	else
	{
		return (advanced_binary_recursive(array, left, mid, value));
	}
}

/**
 * advanced_binary - Recherche une valeur dans un tableau trié d'entiers.
 *
 * @array: Un pointeur vers le premier élément du tableau
 * dans lequel effectuer la recherche.
 * @size: Le nombre d'éléments dans le tableau.
 * @value: La valeur à rechercher.
 *
 * Return: L'index où se trouve la valeur, ou -1 s'il n'est pas trouvé.
 */
int advanced_binary(int *array, size_t size, int value)
{
	return (advanced_binary_recursive(array, 0, size - 1, value));
}
