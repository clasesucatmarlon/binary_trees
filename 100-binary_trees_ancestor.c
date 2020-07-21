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

/**
 * binary_trees_ancestor - finds common ancestor of two nodes
 * @first: is a pointer to the first node
 * @second: is a pointer to the second node
 * Return: return a pointer to the lowest common ancestor
 **/

binary_tree_t *binary_trees_ancestor(const
binary_tree_t *first, const binary_tree_t *second)
{
	int depth_first, depth_second;

	if (!first || !second)
		return (NULL);

	depth_first = (int)binary_tree_depth(first);
	depth_second = (int)binary_tree_depth(second);

	while (depth_first < depth_second)
	{
		second = second->parent;
		depth_second--;
	}

	while (depth_first > depth_second)
	{
		first = first->parent;
		depth_first--;
	}

	for ( ; first != second && depth_first >= 0 && depth_second >= 0;
	depth_first--, depth_second--)
	{
		first = first->parent;
		second = second->parent;
	}
	if (depth_first >= 0 && depth_second >= 0 && first == second)
		return ((binary_tree_t *)first);
	return (NULL);
}
