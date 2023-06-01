#include "slide_line.h"

/**
 * slide_line - fait glisser et fusionne un tableau d'entiers
 * @line: pointe vers un tableau d'entiers contenant des éléments de taille
 * @size: taille du tableau
 * @direction: direction pour faire glisser et fusionner
 *
 * Return: 1 en cas de succès, ou 0 en cas d'échec
 */
int slide_line(int *line, size_t size, int direction)
{
	if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
		return (0);

	if (direction == SLIDE_LEFT)
		slide_left(line, size);
	else
		slide_right(line, size);

	return (1);
}

/**
 * slide_left - fait glisser et fusionne un tableau d'entiers vers la gauche
 * @line: pointe vers un tableau d'entiers contenant des éléments de taille
 * @size: taille du tableau
 */
void slide_left(int *line, size_t size)
{
	size_t current_index, next_index;

	for (current_index = 0; current_index < size; current_index++)
	{
		if (line[current_index] == 0)
			continue;

		for (next_index = current_index + 1; next_index < size; next_index++)
		{
			if (line[next_index] == 0)
				continue;

			if (line[current_index] == line[next_index])
			{
				line[current_index] *= 2;
				line[next_index] = 0;
				break;
			}
			else
				break;
		}
	}

	for (current_index = 0, next_index = 0; current_index < size; current_index++)
	{
		if (line[current_index] != 0)
		{
			line[next_index++] = line[current_index];
			if (next_index - 1 != current_index)
				line[current_index] = 0;
		}
	}
}

/**
 * slide_right - fait glisser et fusionne un tableau d'entiers vers la droite
 * @line: pointe vers un tableau d'entiers contenant des éléments de taille
 * @size: taille du tableau
 */
void slide_right(int *line, size_t size)
{
	ssize_t current_index, next_index;

	for (current_index = size - 1; current_index >= 0; current_index--)
	{
		if (line[current_index] == 0)
			continue;

		for (next_index = current_index - 1; next_index >= 0; next_index--)
		{
			if (line[next_index] == 0)
				continue;

			if (line[current_index] == line[next_index])
			{
				line[current_index] *= 2;
				line[next_index] = 0;
				break;
			}
			else
				break;
		}
	}

	for (current_index = size - 1, next_index = size - 1; current_index >= 0; current_index--)
	{
		if (line[current_index] != 0)
		{
			line[next_index--] = line[current_index];
			if (next_index + 1 != current_index)
				line[current_index] = 0;
		}
	}
}
