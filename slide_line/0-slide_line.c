#include "slide_line.h"

/**
 * slide_line - slides and merges an array of integers
 * @line: points to an array of integers containing size elements
 * @size: size of the array
 * @direction: direction to slide and merge
 *
 * Return: 1 upon success, or 0 upon failure
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
 * slide_left - slides and merges an array of integers to the left
 * @line: points to an array of integers containing size elements
 * @size: size of the array
 */
void slide_left(int *line, size_t size)
{
	size_t i, j;

	for (i = 0; i < size; i++)
	{
		if (line[i] == 0)
			continue;

		for (j = i + 1; j < size; j++)
		{
			if (line[j] == 0)
				continue;

			if (line[i] == line[j])
			{
				line[i] *= 2;
				line[j] = 0;
				break;
			}
			else
				break;
		}
	}

	for (i = 0, j = 0; i < size; i++)
	{
		if (line[i] != 0)
		{
			line[j++] = line[i];
			if (j - 1 != i)
				line[i] = 0;
		}
	}
}

/**
 * slide_right - slides and merges an array of integers to the right
 * @line: points to an array of integers containing size elements
 * @size: size of the array
 */
void slide_right(int *line, size_t size)
{
	ssize_t i, j;

	for (i = size - 1; i >= 0; i--)
	{
		if (line[i] == 0)
			continue;

		for (j = i - 1; j >= 0; j--)
		{
			if (line[j] == 0)
				continue;

			if (line[i] == line[j])
			{
				line[i] *= 2;
				line[j] = 0;
				break;
			}
			else
				break;
		}
	}

	for (i = size - 1, j = size - 1; i >= 0; i--)
	{
		if (line[i] != 0)
		{
			line[j--] = line[i];
			if (j + 1 != i)
				line[i] = 0;
		}
	}
}
