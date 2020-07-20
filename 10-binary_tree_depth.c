#include "binary_trees.h"

/**
 * binary_tree_depth - function that return depth of the tree
 * @tree: is a pointer to the root node
 * Return: depth of the tree
 **/

size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	if (tree == NULL)
		return (0);

	if (tree->parent != NULL)
	{
		depth++;
		depth += binary_tree_depth(tree->parent);
	}
	return (depth);
}
