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
	if (first == NULL || second == NULL)
		return (NULL);

	if (first->parent == second)
		return (first->parent);
	if (second->parent == first)
		return (second->parent);
	if (binary_tree_depth(first) > binary_tree_depth(second))
		first = first->parent;
	else
		second = second->parent;

	return (binary_trees_ancestor(first, second));
}
