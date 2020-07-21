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
	const binary_tree_t *aux_first, *aux_second;
	int depth_first, depth_second;

	if (!first || !second)
		return (NULL);

	aux_first = first;
	aux_second = second;

	depth_first = (int)binary_tree_depth(aux_first);
	depth_second = (int)binary_tree_depth(aux_second);

	if (depth_first > depth_second)
	{
		aux_first = aux_first->parent;
		depth_first--;
	}
	else if (depth_second > depth_first)
	{
		aux_second = aux_second->parent;
		depth_second--;
	}
	while (aux_first != aux_second)
	{
		if (aux_first == aux_second)
		{
			break;
		}
		aux_first = aux_first->parent;
		aux_second = aux_second->parent;
	}
	if (depth_first >= 0 && depth_second >= 0 && aux_first == aux_second)
		return ((binary_tree_t *) aux_first);
	return (NULL);
}
