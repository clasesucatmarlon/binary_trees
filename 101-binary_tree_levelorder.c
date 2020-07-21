#include "binary_trees.h"

/**
 * binary_tree_height - function that return heigh of the tree
 * @tree: is a pointer to the root node
 * Return: heigth of the tree
 **/

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_left, height_right;

	if (tree == NULL)
		return (0);

	height_left = 0;
	height_right = 0;

	if (tree->left != NULL)
		height_left = binary_tree_height(tree->left) + 1;

	if (tree->right != NULL)
		height_right = binary_tree_height(tree->right) + 1;

	if (height_left > height_right)
		return (height_left);
	else
		return (height_right);
}

/**
 * print_level - prints a given tree level recursively
 * @tree: pointer to root of tree
 * @func: function to be called on each node
 * @level: the tree depth level to print
 */

void print_level(const binary_tree_t *tree, void (*func)(int), size_t level)
{
	if (!level)
		func(tree->n);
	else
	{
		print_level(tree->left, func, level - 1);
		print_level(tree->right, func, level - 1);
	}
}

/**
 * binary_tree_levelorder - binary tree using level-order traversal
 * @tree: pointer to root of tree
 * @func: function to be called on each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t aux_height, iterator_level;

	if (!tree || !func)
		return;

	aux_height = binary_tree_height(tree);

	for (iterator_level = 0; iterator_level <= aux_height; iterator_level++)
		print_level(tree, func, iterator_level);
}
