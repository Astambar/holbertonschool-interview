#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"

/**
 * advanced_binary - Recherche une valeur dans un tableau trié d'entiers
 *
 * @array: Un pointeur vers le premier élément du tableau dans
 * lequel effectuer la recherche.
 * @size: Le nombre d'éléments dans le tableau.
 * @value: La valeur à rechercher.
 *
 * Return: L'index où se trouve la valeur, ou -1 s'il n'est pas trouvé.
 */
int advanced_binary(int *array, size_t size, int value)
{
    size_t left, right, mid;

    if (array == NULL || size == 0)
        return (-1);

    left = 0;
    right = size - 1;

    while (left <= right)
    {
        print_array(array, left, right); // Print the array (no loop)

        mid = (left + right) / 2;

        if (array[mid] == value)
        {
            if (mid == 0 || array[mid - 1] != value)
                return (mid);
            right = mid - 1;
        }
        else if (array[mid] < value)
            left = mid + 1;
        else
            right = mid;
    }

    return (-1);
}

/* Recursive function to print the array */
void print_array(int *array, size_t left, size_t right)
{
    printf("Searching in array: ");
    if (left < right)
    {
        for (size_t i = left; i < right; i++)
            printf("%d, ", array[i]);
        printf("%d\n", array[right]);
    }
    else if (left == right)
    {
        printf("%d\n", array[left]);
    }
}
