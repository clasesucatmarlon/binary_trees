#include "binary_trees.h"

/**
 * binary_tree_balance - function that determine balance in tree
 * @tree: is a pointer to the root node
 * Return: balance of tree
 **/

int binary_tree_balance(const binary_tree_t *tree)
{
	int tree_left = 0, tree_right = 0;

	if (tree == NULL)
		return (0);

	if (tree->left)
		tree_left = binary_tree_height(tree->left) + 1;
	else
		tree_left = 0;

	if (tree->right)
		tree_right = binary_tree_height(tree->right) + 1;
	else
		tree_right = 0;

	return (tree_left - tree_right);
}

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
 * binary_tree_is_perfect - check if a tree is perfect
 * @tree: is a pointer to the root node
 * Return: return 1 if is perfect and 0 otherwise
 **/

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (binary_tree_balance(tree) == 0)
	{
		if (binary_tree_height(tree->left) == 0 &&
			binary_tree_height(tree->right) == 0)
			return (1);
		return (binary_tree_is_perfect(tree->left) &&
			binary_tree_is_perfect(tree->right));
	}
	return (0);
}
