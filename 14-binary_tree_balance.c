#include "binary_trees.h"

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: tree to measure the balance factor of.
 *
 * Return: balance factor, otherwise 0.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int ans = 0;

	if (tree)
	{
		ans = binary_tree_height(tree->left);
		ans -= binary_tree_height(tree->right);
	}
	return (ans);
}

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: tree to measure height of.
 *
 * Return: tree size, otherwise NULL.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left = 0, right = 0;

	if (tree)
	{
		left = binary_tree_height(tree->left) + 1;
		right = binary_tree_height(tree->right) + 1;
		return (right > left ? right : left);
	}
	return (0);
}
