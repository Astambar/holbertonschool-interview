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
 * is_unstable - Checks if the grid is unstable
 * @grid: Sandpile
 * Return: 1 if unstable, 0 otherwise
 */
int is_unstable(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
				return (1);
		}
	}
	return (0);
}

/**
 * sandpiles_sum - Adds sandpiles and checks if good
 * @firstGrid: First sandpile
 * @secondGrid: Second sandpile
 */
void sandpiles_sum(int firstGrid[3][3], int secondGrid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			firstGrid[i][j] += secondGrid[i][j];
		}
	}

	while (is_unstable(firstGrid))
	{
		printf("=\n");
		print_grids(firstGrid);
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (firstGrid[i][j] > 3)
				{
					firstGrid[i][j] -= 4;
					if (i > 0)
						firstGrid[i - 1][j]++;
					if (j > 0)
						firstGrid[i][j - 1]++;
					if (i < 2)
						firstGrid[i + 1][j]++;
					if (j < 2)
						firstGrid[i][j + 1]++;
				}
			}
		}
	}
}
