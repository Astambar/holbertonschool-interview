# sandpiles

# Sandpiles

Ce projet implémente une solution au problème des tas de sable en C.

## Description

Le problème des tas de sable consiste à ajouter deux grilles de nombres entiers de taille 3x3 et à stabiliser le résultat en répartissant les valeurs supérieures à 3 dans les cellules adjacentes jusqu'à ce que toutes les cellules aient une valeur inférieure ou égale à 3.

Ce projet fournit une implémentation en C pour résoudre ce problème.

## Utilisation

Pour utiliser ce code, compilez-le avec `gcc` et exécutez-le avec deux grilles de nombres entiers de taille 3x3 comme arguments.

```bash
$ gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-sandpiles.c -o 0-sandpiles
$ ./0-sandpiles
3 3 3   1 3 1
3 3 3 + 3 3 3
3 3 3   1 3 1
=
4 6 4
6 6 6
4 6 4
=
2 5 2
5 6 5
2 5 2
=
4 2 4
2 6 2
4 2 4
=
0 5 0
5 2 5
0 5 0
=
2 1 2
1 6 1
2 1 2
=
2 2 2
2 2 2
2 2 2
$ gcc -Wall -Wextra -Werror -pedantic 1-main.c 0-sandpiles.c -o 0-sandpiles
$ ./0-sandpiles 
0 0 0   3 3 3
0 0 0 + 3 3 3
0 0 0   3 3 3
=
3 3 3
3 3 3
3 3 3
```
## Fonctionnalités

Ce projet fournit les fonctions suivantes pour résoudre le problème des tas de sable :

- `void print_grids(int grid[3][3])` : affiche une grille de nombres entiers de taille 3x3.
- `int is_unstable(int grid[3][3])` : vérifie si une grille est instable (c'est-à-dire si elle contient des valeurs supérieures à 3).
- `void add_grids(int firstGrid[3][3], int secondGrid[3][3])` : ajoute deux grilles de nombres entiers de taille 3x3.
- `void stabilize_grid(int grid[3][3])` : stabilise une grille en répartissant les valeurs supérieures à 3 dans les cellules adjacentes.
- `void sandpiles_sum(int firstGrid[3][3], int secondGrid[3][3])` : ajoute deux grilles de nombres entiers de taille 3x3 et stabilise le résultat.
