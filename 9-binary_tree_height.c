#include "binary_trees.h"

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
		if (tree->left)
			left = binary_tree_height(tree->left) + 1;
		if (tree->right)
			right = binary_tree_height(tree->right) + 1;
		return (right > left ? right : left);
	}
	return (0);
}
