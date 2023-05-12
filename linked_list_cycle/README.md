# linked_list_cycle
# Check Cycle

## Description

Ce projet contient une fonction `check_cycle` qui vérifie si une liste chaînée a un cycle.

## Installation

Pour installer ce projet, suivez les étapes suivantes:

1. Clonez le dépôt sur votre machine locale
2. Incluez le fichier `lists.h` dans votre code source
3. Utilisez la fonction `check_cycle` dans votre code pour vérifier si une liste chaînée a un cycle

## Utilisation

Pour utiliser la fonction `check_cycle`, passez en argument une liste chaînée de type `listint_t`. La fonction renverra 0 si la liste n'a pas de cycle, et 1 sinon.

Exemple d'utilisation:

```c
#include "lists.h"

int main(void)
{
    listint_t *list;

    /* Création de la liste chaînée */

    if (check_cycle(list))
        printf("La liste a un cycle\n");
    else
        printf("La liste n'a pas de cycle\n");

    return (0);
}
```