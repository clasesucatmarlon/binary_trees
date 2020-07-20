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
