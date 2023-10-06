#ifndef LIST_H
#define LIST_H

/**
 * struct List - Structure pour un nœud de liste doublement chaînée circulaire
 * @str: Chaîne de caractères (allouée dynamiquement)
 * @prev: Pointe vers le nœud précédent
 * @next: Pointe vers le nœud suivant
 *
 * Description : Structure d'un nœud de liste doublement chaînée circulaire
 */
typedef struct List
{
    char *str;
    struct List *prev;
    struct List *next;
} List;

/* Prototypes de fonctions */
List *create_new_node(char *str);

/* Ajoute un nouveau nœud à la fin de la liste */
List *add_node_end(List **list, char *str);

/* Ajoute un nouveau nœud au début de la liste */
List *add_node_begin(List **list, char *str);

#endif /* LIST_H */
