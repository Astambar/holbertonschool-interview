# sorted_array_to_avl

Ce projet consiste à écrire une fonction qui construit un arbre AVL à partir d'un tableau trié.

## Exigences

- Les éditeurs autorisés sont vi, vim et emacs.
- Tous vos fichiers seront compilés sur Ubuntu 14.04 LTS.
- Vos programmes et fonctions seront compilés avec gcc 4.8.4 en utilisant les flags -Wall -Werror -Wextra et -pedantic.
- Tous vos fichiers doivent se terminer par une nouvelle ligne.
- Un fichier README.md, à la racine du dossier du projet, est obligatoire.
- Votre code doit utiliser le style Betty. Il sera vérifié à l'aide de betty-style.pl et betty-doc.pl
- Vous n'êtes pas autorisé à utiliser des variables globales.
- Pas plus de 5 fonctions par fichier.
- Vous êtes autorisé à utiliser la bibliothèque standard.

## Décisions de conception

Pour construire un arbre AVL à partir d'un tableau trié, nous avons décidé d'utiliser l'approche récursive. Cette approche garantit que l'arbre résultant sera équilibré car elle utilise la valeur médiane comme nœud racine à chaque étape de la construction de l'arbre.

Nous avons défini trois fonctions pour implémenter cette approche:

1. `avl_t *sorted_array_to_avl(int *array, size_t size);`
    - Cette fonction est la fonction principale qui prend en entrée un tableau trié et sa taille et renvoie un pointeur vers le nœud racine de l'arbre AVL créé.
2. `avl_t *recursive_build(int *array, int start, int end);`
    - Cette fonction est une fonction récursive qui construit l'arbre AVL en divisant le tableau en deux moitiés égales et en utilisant la valeur médiane comme nœud racine à chaque étape de la construction de l'arbre.
3. `avl_t *create_node(int value);`
    - Cette fonction crée un nouveau nœud avec la valeur donnée et renvoie un pointeur vers le nœud créé.

## Utilisation

Pour utiliser cette fonction pour construire un arbre AVL à partir d'un tableau trié, vous devez inclure le fichier d'en-tête `binary_trees.h` dans votre code source et lier votre programme avec les fichiers source contenant les définitions des fonctions `sorted_array_to_avl`, `recursive_build` et `create_node`.

Voici un exemple d'utilisation de la fonction `sorted_array_to_avl` pour construire un arbre AVL à partir d'un tableau trié:

```c
#include <stdio.h>
#include "binary_trees.h"

int main(void)
{
    avl_t *tree;
    int array[] = {1, 2, 3, 4, 5};
    size_t size = sizeof(array) / sizeof(array[0]);

    tree = sorted_array_to_avl(array, size);
    if (!tree)
    {
        fprintf(stderr, "Failed to create AVL tree\n");
        return (1);
    }

    /* Use the tree */
    /* ... */

    /* Free the tree */
    /* ... */

    return (0);
}
```
Ce code crée un arbre AVL équilibré à partir du tableau trié array en utilisant la fonction `sorted_array_to_avl`. Vous pouvez ensuite utiliser l’arbre comme vous le souhaitez.

## Conclusion
Nous espérons que ce projet vous aidera à comprendre comment construire un arbre AVL équilibré à partir d’un tableau trié en utilisant l’approche récursive. Si vous avez des questions ou des commentaires, n’hésitez pas à nous contacter.

