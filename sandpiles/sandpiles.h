#ifndef SANDPILES_H
#define SANDPILES_H
#include <stdio.h>
#include <stdlib.h>
/**
* Sandpiles_sum la fonction
*/
void sandpiles_sum(int firstGrid[3][3], int secondGrid[3][3]);

/**
* Les dépendance de sandpiles_sum
*/
void print_grids(int grid[3][3]);
int is_unstable(int grid[3][3]);
void stabilize_grid(int grid[3][3]);
void add_grids(int firstGrid[3][3], int secondGrid[3][3]);
void sandpiles_sum(int firstGrid[3][3], int secondGrid[3][3]);

#endif /* SANDPILES_H */
