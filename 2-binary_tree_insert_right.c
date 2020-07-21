#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a node as the right-child of another node
 * @parent: parent node
 * @value: value to set
 * Return: new node
 **/

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *aux = NULL;

	if (parent == NULL)
		return (NULL);
	aux = malloc(sizeof(binary_tree_t));
	if (aux == NULL)
		return (NULL);
	aux->n = value;
	aux->parent = parent;
	aux->right = parent->right;
	aux->left = NULL;
	parent->right = aux;

	if (aux->right != NULL)
		aux->right->parent = aux;

	return (aux);
}
