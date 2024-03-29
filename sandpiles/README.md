# Sandpiles

Ce projet implémente une solution au problème des tas de sable en C.

## Description

Le problème des tas de sable consiste à ajouter deux grilles de nombres entiers de taille 3x3 et à stabiliser le résultat en répartissant les valeurs supérieures à 3 dans les cellules adjacentes jusqu'à ce que toutes les cellules aient une valeur inférieure ou égale à 3.

Ce projet fournit une implémentation en C pour résoudre ce problème.

## Installation

Pour installer ce projet, clonez le dépôt et accédez au répertoire du projet :

Tout d'abord clone le repository à l'emplacement souhaiter:
```bash
$ git clone https://github.com/Astambar/holbertonschool-interview.git
```
puis accède au projet :
```bash
$ cd holbertonschool-interview/sandpiles/
```

## Utilisation

Pour utiliser ce code, compilez-le avec `gcc` et exécutez-le avec deux grilles de nombres entiers de taille 3x3 comme arguments.

Voici un exemple avec le fichier [0-main.c](./0-main.c) actuel:
```bash
$ gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-sandpiles.c -o 0-sandpiles
```
puis exécuter le code compilé ainsi:
```bash
$ ./0-sandpiles
```
retour de la commande pour cet exemple :
```txt
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
```

Voici un autre exemple avec le fichier [1-main.c](./1-main.c) actuel:
```bash
$ gcc -Wall -Wextra -Werror -pedantic 1-main.c 0-sandpiles.c -o 0-sandpiles
```
puis exécuter le code compilé ainsi:
```bash
$ ./0-sandpiles
```
retour de la commande pour cet exemple :
```txt
0 0 0   3 3 3
0 0 0 + 3 3 3
0 0 0   3 3 3
=
3 3 3
3 3 3
3 3 3
```
## Fonctionnalités

Ce projet fournit les fonctions suivantes pour résoudre le problème des tas de sable, disponibles dans le fichier [0-sandpiles.c](./0-sandpiles.c) :

- `void print_grids(int grid[3][3])` : affiche une grille de nombres entiers de taille 3x3.
- `int is_unstable(int grid[3][3])` : vérifie si une grille est instable (c'est-à-dire si elle contient des valeurs supérieures à 3).
- `void add_grids(int firstGrid[3][3], int secondGrid[3][3])` : ajoute deux grilles de nombres entiers de taille 3x3.
- `void stabilize_grid(int grid[3][3])` : stabilise une grille en répartissant les valeurs supérieures à 3 dans les cellules adjacentes.
- `void sandpiles_sum(int firstGrid[3][3], int secondGrid[3][3])` : ajoute deux grilles de nombres entiers de taille 3x3 et stabilise le résultat.

Ce projet fournit les fonctions suivantes pour résoudre le problème des tas de sable, disponibles dans le fichier [imagine_newfile.c](./imagine_newfile.c) :
