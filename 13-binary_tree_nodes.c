#include "binary_trees.h"

/**
 * binary_tree_nodes - function that return count the child
 * @tree: is a pointer to the root node
 * Return: count of child
 **/

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t count_aux = 0;

	if (tree == NULL)
		return (0);

	if (tree->left != NULL || tree->right != NULL)
		count_aux++;

	if (tree->right != NULL)
		count_aux += binary_tree_nodes(tree->right);

	if (tree->left != NULL)
		count_aux += binary_tree_nodes(tree->left);

	return (count_aux);
}
