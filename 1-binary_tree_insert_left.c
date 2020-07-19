#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a node as the left-child of another node
 * @parent: parent node
 * @value: value to set
 * Return: new node
 **/

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *aux = NULL;

	if (parent == NULL)
		return (NULL);
	aux = malloc(sizeof(*aux));
	if (aux == NULL)
		return (NULL);
	aux->n = value;
	aux->parent = parent;
	aux->left = parent->left;
	aux->right = NULL;
	parent->left = aux;

	if (aux->left != NULL)
		aux->left->parent = aux;

	return (aux);
}
