#include "binary_trees.h"

/**
 * binary_tree_leaves - function that return levels of the tree
 * @tree: is a pointer to the root node
 * Return: levels of the tree
 **/

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t levels = 0;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
	levels++;


	if (tree->left != NULL)
		levels += binary_tree_leaves(tree->left);
	if (tree->right != NULL)
		levels += binary_tree_leaves(tree->right);
	return (levels);
}
