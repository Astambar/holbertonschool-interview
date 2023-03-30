# insert_in_sorted_linked_list

# Documentation du projet

Le projet consiste en l'implémentation de deux fonctions pour insérer des noeuds dans une liste chaînée triée en ordre croissant.

## Fonctionnalités

Le projet comprend les fonctionnalités suivantes :

- `get_previous_node_for_insertion` : trouve le point d'insertion pour un nouveau noeud dans une liste chaînée triée.
- `insert_node` : insère un nouveau noeud dans une liste chaînée triée.

## Fonction get_previous_node_for_insertion

La fonction `get_previous_node_for_insertion` prend deux paramètres en entrée :

- `head` : un pointeur vers la tête de la liste chaînée.
- `number` : la valeur à insérer dans le nouveau noeud.

La fonction renvoie un double pointeur vers le nœud précédent où le nouveau nœud doit être inséré.

## Fonction insert_node

La fonction `insert_node` prend deux paramètres en entrée :

- `head` : un pointeur vers la tête de la liste chaînée.
- `number` : la valeur à insérer dans le nouveau noeud.

La fonction alloue de l'espace pour le nouveau noeud, l'initialise avec la valeur `number` et l'insère dans la liste chaînée triée. La fonction renvoie un pointeur vers le nouveau noeud créé, ou NULL en cas d'échec.

## Fonction insert_node_before

La fonction `insert_node_before` prend deux paramètres en entrée :

- `insertion_point` : un double pointeur vers le nœud précédent où le nouveau nœud doit être inséré.
- `new_node` : un pointeur vers le nouveau noeud à insérer.

La fonction insère le nouveau noeud à l'emplacement spécifié.
