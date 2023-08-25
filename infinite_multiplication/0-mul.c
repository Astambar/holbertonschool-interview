#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

/**
 * _isnumber - Vérifie si une chaîne représente un nombre.
 * @string: La chaîne d'entrée à vérifier.
 * Return: 1 si la chaîne est un nombre, 0 sinon.
 */
int _isnumber(char *string)
{
	int i;

	for (i = 0; string[i] != '\0'; i++)
	{
		if (!isdigit(string[i]))
		{
			return (0);
		}
	}
	return (1);
}

/**
 * allocate_and_initialize_memory - Alloue de la mémoire
 * et l'initialise avec '0'.
 * @num_members: Le nombre de membres mémoire à allouer.
 * Return: Un pointeur vers la mémoire allouée.
 */

char *allocate_and_initialize_memory(unsigned int num_members)
{
	char *pointer = malloc(num_members + 1);
	unsigned int i;

	if (pointer == NULL)
	{
		printf("Erreur d'allocation mémoire\n");
		exit(1);
	}
	for (i = 0; i < num_members; i++)
	{
		pointer[i] = '0';
	}
	pointer[num_members] = '\0';
	return (pointer);
}

/**
 * multiply_strings - Multiplie deux chaînes de caractères en entrée.
 * @number1: La première chaîne de caractères
 * en entrée (le multiplicateur).
 *
 * @number2: La deuxième chaîne de caractères
 * en entrée (le multiplicande).
 *
 * Return: Un pointeur vers la chaîne de caractères résultante.
 */
char *multiply_strings(char *number1, char *number2)
{
	char *result;
	int length_number1, length_number2, total_length, i, j;
	int carry_product = 0, carry_sum = 0;
	int result_index, product, sum;

	length_number1 = strlen(number1);
	length_number2 = strlen(number2);
	total_length = length_number1 + length_number2;
	result = allocate_and_initialize_memory(total_length);

	for (i = length_number2 - 1; i >= 0; i--)
	{
		

		for (j = length_number1 - 1; j >= 0; j--)
		{
			result_index = i + j + 1;
			product = (number1[j] - '0') * (number2[i] - '0') + carry_product;

			carry_product = product / 10;
			sum = (result[result_index] - '0') + (product % 10) + carry_sum;

			carry_sum = sum / 10;
			result[result_index] = (sum % 10) + '0';
		}
		result[i] = (carry_product + carry_sum) + '0';
	}

	return (result);
}

/**
 * print_result - Affiche la chaîne de caractères résultante
 * après avoir supprimé les zéros non significatifs.
 * @result: La chaîne de caractères résultante à afficher.
 */
void print_result(char *result)
{
	int leading_zeros = 0;

	while (result[leading_zeros] == '0')
	{
		leading_zeros++;
	}

	if (result[leading_zeros] == '\0')
	{
		printf("0\n");
	}
	else
	{
		for (; result[leading_zeros] != '\0'; leading_zeros++)
		{
			printf("%c", result[leading_zeros]);
		}
		printf("\n");
	}
}

/**
 * main - Point d'entrée du programme.
 * @argc: Le nombre d'arguments en ligne de commande.
 * @argv: Un tableau contenant les arguments en ligne de commande.
 * Return: 0 en cas de réussite, 1 en cas d'erreur.
 */
int main(int argc, char **argv)
{
	char *num1, *num2, *result;

	if (argc != 3 || !_isnumber(argv[1]) || !_isnumber(argv[2]))
	{
		printf("Erreur : Entrée invalide\n");
		return (1);
	}

	num1 = argv[1];
	num2 = argv[2];

	if (atoi(num1) == 0 || atoi(num2) == 0)
	{
		printf("0\n");
		return (0);
	}

	result = multiply_strings(num1, num2);
	print_result(result);

	free(result);

	return (0);
}
