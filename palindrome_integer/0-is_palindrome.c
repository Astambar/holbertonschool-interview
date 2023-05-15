#include "palindrome.h"

/**
 * reverse_number - Inverse un nombre
 * @n: Le nombre à inverser
 *
 * Return: Le nombre inversé
 */
unsigned long reverse_number(unsigned long n)
{
	unsigned long reversed_n = 0;

	while (n > 0)
	{
		reversed_n *= 10;
		reversed_n += n % 10;
		n /= 10;
	}

	return (reversed_n);
}

/**
 * is_palindrome - Vérifie si un nombre est un palindrome
 * @n: Le nombre à vérifier
 *
 * Return: 1 si n est un palindrome, 0 sinon
 */
int is_palindrome(unsigned long n)
{
	unsigned long reversed_n = reverse_number(n);

	if (n == reversed_n)
		return (1);
	else
		return (0);
}
