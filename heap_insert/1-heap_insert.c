#include "binary_trees.h"

/**
 * swapper - échange les valeurs de deux noeuds
 * @parent: parent
 * @node: node
 * Return: void
 */
void swapper(int *parent, int *node)
{
	int temp = *parent;
	*parent = *node;
	*node = temp;
}

/**
 * size_tree - calcule la taille de l'arbre
 * @tree: arbre
 * Return: taille de l'arbre
 */
size_t size_tree(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}

	return (size_tree(tree->left) + 1 + size_tree(tree->right));
}

/**
 * childe_finder - trouve le noeud enfant à insérer
 * @root: racine de l'arbre
 * @idx: indice du noeud
 * @size: taille de l'arbre
 * Return: pointeur vers le noeud enfant
 */
heap_t *childe_finder(heap_t *root, size_t idx, size_t size)
{
	heap_t *left, *right;

	/* Vérification si l'indice est supérieur à la taille de l'arbre */
	if (idx > size)
	{
		return (NULL);
	}

	/* Vérification si l'indice est égal à la taille de l'arbre */
	if (idx == size)
	{
		return (root);
	}

	/* Recherche du noeud enfant gauche */
	left = childe_finder(root->left, 2 * idx + 1, size);

	/* Recherche du noeud enfant droit */
	right = childe_finder(root->right, 2 * idx + 2, size);

	/* Vérification si le noeud enfant gauche n'est pas vide */
	if (left != NULL)
	{
		/* Si oui, on renvoie le pointeur vers le noeud enfant gauche */
		return (left);
	}
	else if (right != NULL)
	{
		/* Sinon, on vérifie si le noeud enfant droit n'est pas vide */
		/* et on renvoie le pointeur vers le noeud enfant droit */
		return (right);
	}
	else
	{
		/* Si les deux noeuds enfants sont vides, on renvoie NULL */
		return (NULL);
	}
}

/**
 * parent_finder - trouve le noeud parent à insérer
 * @root: racine de l'arbre
 * @new: nouveau noeud à insérer
 * Return: pointeur vers le noeud parent
 */
heap_t *parent_finder(heap_t *root, heap_t *new)
{
	heap_t *parent;
	size_t size;

	/* Calcul de la taille de l'arbre */
	size = size_tree(root);

	/* Recherche du noeud enfant */
	parent = childe_finder(root, 0, (size - 1) / 2);

	/* Vérification si le noeud enfant gauche est vide */
	if (parent->left == NULL)
	{
		/* Si oui, on insère le nouveau noeud à gauche */
		parent->left = new;
	}
	else
	{
		/* Sinon, on insère le nouveau noeud à droite */
		parent->right = new;
	}

	/* Retour du pointeur vers le noeud parent */
	return (parent);
}

/**
 * heap_insert - insère un nouveau noeud dans un tas binaire
 * @root: pointeur vers la racine du tas binaire
 * @value: valeur du nouveau noeud à insérer
 * Return: pointeur vers le nouveau noeud inséré
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node, *parent;

	/* Crée un nouveau noeud */
	new_node = binary_tree_node(NULL, value);

	/* Si l'arbre est vide, le nouveau noeud devient la racine */
	if (*root == NULL)
	{
		*root = new_node;
		return (new_node);
	}

	/* Trouve le parent pour le nouveau noeud */
	parent = parent_finder(*root, new_node);

	/* Lie le nouveau noeud à son parent */
	new_node->parent = parent;

	/** Maintient la propriété du tas binaire par une série d'échanges */
	while (new_node->parent != NULL && new_node->parent->n < new_node->n)
	{
		/* Échange les valeurs des noeuds */
		swapper(&new_node->parent->n, &new_node->n);
		/* Continue avec le parent du nouveau noeud */
		new_node = new_node->parent;
	}

	/* Retourne le pointeur vers le nouveau noeud inséré */
	return (new_node);
}
