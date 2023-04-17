#include "sandpiles.h"

/**
 * print_grids - Prints sandpiles
 * @grid: Sandpile
 */
void print_grids(int grid[3][3])
{
	int row, col;

	for (row = 0; row < 3; row++)
	{
		for (col = 0; col < 3; col++)
		{
			if (col)
				printf(" ");
			printf("%d", grid[row][col]);
		}
		printf("\n");
	}
}

/**
 * is_unstable - Vérifie si la grille est instable
 * @grid: Sandpile
 * Return: 1 si instable, 0 sinon
 */
int is_unstable(int grid[3][3])
{
	int row, column;

	for (row = 0; row < 3; row++)
	{
		for (column = 0; column < 3; column++)
		{
			if (grid[row][column] > 3)
				return (1);
		}
	}
	return (0);
}

/**
 * add_grids - Ajoute les éléments de deux grilles
 * @firstGrid: Premier sandpile
 * @secondGrid: Deuxième sandpile
 */
void add_grids(int firstGrid[3][3], int secondGrid[3][3])
{
	int row, column;

	for (row = 0; row < 3; row++)
	{
		for (column = 0; column < 3; column++)
		{
			firstGrid[row][column] += secondGrid[row][column];
		}
	}
}

/**
 * stabilize_grid - Stabilise la grille
 * @grid: Sandpile
 */
void stabilize_grid(int grid[3][3])
{
	int row, column;

	for (row = 0; row < 3; row++)
	{
		for (column = 0; column < 3; column++)
		{
			if (grid[row][column] > 3)
			{
				grid[row][column] -= 4;
				if (row > 0)
					grid[row - 1][column]++;
				if (column > 0)
					grid[row][column - 1]++;
				if (row < 2)
					grid[row + 1][column]++;
				if (column < 2)
					grid[row][column + 1]++;
			}
		}
	}
}

/**
 * sandpiles_sum - Ajoute des sandpiles et vérifie si c'est bon
 * @firstGrid: Premier sandpile
 * @secondGrid: Deuxième sandpile
 */
void sandpiles_sum(int firstGrid[3][3], int secondGrid[3][3])
{
	add_grids(firstGrid, secondGrid);

	while (is_unstable(firstGrid))
	{
		printf("=\n");
		print_grids(firstGrid);
		stabilize_grid(firstGrid);
	}
}
