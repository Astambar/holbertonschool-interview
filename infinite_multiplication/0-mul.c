#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

/**
 * _isnumber - checks if string is number
 * @s: string
 * Return: 1 if number, 0 if not
 */
int _isnumber(char *s)
{
	int i, check, d;

	d = 0, check = 1;
	for (i = 0; *(s + i) != 0; i++)
	{
		d = isdigit(*(s + i));
		if (d == 0)
		{
			check = 0;
			break;
		}
	}
	return (check);
}

/**
 * _callocX - reserves memory initialized to 0
 * @nmemb: # of bytes
 * Return: pointer
 */
char *_callocX(unsigned int nmemb)
{
	unsigned int i;
	char *p;

	p = malloc(nmemb + 1);
	if (p == 0)
		return (0);
	for (i = 0; i < nmemb; i++)
		p[i] = '0';
	p[i] = '\0';
	return (p);
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
 * calculateAndPrintResult - Calcule et affiche le résultat final.
 * @num1: Le premier nombre.
 * @num2: Le deuxième nombre.
 */
void calculateAndPrintResult(const char *num1, const char *num2)
{
	int length_num1 = strlen(num1);
	int length_num2 = strlen(num2);
	int total_length = length_num1 + length_num2;
	char *result = _callocX(total_length);
	int i, j, multiplication, carry_multiply,
	addition, carry_addition, result_index;
	int leading_zeros;

	for (i = length_num2 - 1; i >= 0; i--)
	{
		carry_multiply = 0, carry_addition = 0;
		for (j = length_num1 - 1; j >= 0; j--)
		{
			result_index = i + j + 1;
			multiplication = (num1[j] - '0') * (num2[i] - '0') + carry_multiply;
			carry_multiply = multiplication / 10;
			addition = (result[result_index] - '0') + (multiplication % 10);
			addition += carry_addition;
			carry_addition = addition / 10;
			result[result_index] = (addition % 10) + '0';
		}
		result[result_index - 1] = (carry_multiply + carry_addition) + '0';
	}

	leading_zeros = 0;
	while (result[leading_zeros] == '0' && leading_zeros < total_length - 1)
	{
		leading_zeros++;
	}

	for (i = leading_zeros; i < total_length; i++)
	{
		printf("%c", result[i]);
	}
	printf("\n");

	free(result);
}

/**
 * main - Point d'entrée du programme.
 * @argc: Le nombre d'arguments en ligne de commande.
 * @argv: Un tableau contenant les arguments en ligne de commande.
 * Return: 0 en cas de réussite, 1 en cas d'erreur.
 */
int main(int argc, char **argv)
{
	if (argc != 3 || !_isnumber(argv[1]) || !_isnumber(argv[2]))
	{
		printf("Error\n");
		exit(98);
	}

	if (atoi(argv[1]) == 0 || atoi(argv[2]) == 0)
	{
		printf("0\n");
		exit(0);
	}

	calculateAndPrintResult(argv[1], argv[2]);

	return (0);
}
