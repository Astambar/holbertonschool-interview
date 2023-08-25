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
 * main - Point d'entrée du programme.
 * @argc: Le nombre d'arguments en ligne de commande.
 * @argv: Un tableau contenant les arguments en ligne de commande.
 * Return: 0 en cas de réussite, 1 en cas d'erreur.
 */
int main(int argc, char **argv)
{
    int i, j, length_num1, length_num2, total_length,
	multiplication, addition, carry_multiply, carry_addition,
	result_index, leading_zeros = 0;
    char *result;

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

    length_num1 = strlen(argv[1]);
    length_num2 = strlen(argv[2]);
    total_length = length_num1 + length_num2;
    result = _callocX(total_length);

    for (i = length_num2 - 1; i >= 0; i--)
    {
        carry_multiply = 0, carry_addition = 0;
        for (j = length_num1 - 1; j >= 0; j--)
        {
            result_index = i + j + 1;
            multiplication = (argv[1][j] - '0') * (argv[2][i] - '0') + carry_multiply;
            carry_multiply = multiplication / 10;
            addition = (result[result_index] - '0') + (multiplication % 10) + carry_addition;
            carry_addition = addition / 10;
            result[result_index] = (addition % 10) + '0';
        }
        result[result_index - 1] = (carry_multiply + carry_addition) + '0';
    }

    if (result[0] == '0')
        leading_zeros = 1;

    for (; leading_zeros < total_length; leading_zeros++)
    {
        printf("%c", result[leading_zeros]);
    }
    printf("\n");

    free(result);
    return 0;
}

