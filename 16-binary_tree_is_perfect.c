#include "binary_trees.h"

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: tree to check.
 *
 * Return: 1 if perfect, otherwise 0.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t height, size;

	if (tree)
	{
		height = binary_tree_height(tree);
		size = (1 << (h + 1)) - 1;
		if (size == binary_tree_size(tree))
			return (1);
	}
	return (0);
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
		if (tree->left)
			left = binary_tree_height(tree->left) + 1;
		if (tree->right)
			right = binary_tree_height(tree->right) + 1;
		return (right > left ? right : left);
	}
	return (0);
}

/**
 * binary_tree_size - measure the size of a binary tree
 * @tree: tree to measure size of.
 *
 * Return: size of the tree, otherwise 0.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t ans = 0;

	if (tree)
	{
		ans += 1;
		ans += binary_tree_size(tree->left);
		ans += binary_tree_size(tree->right);
	}
	return (ans);
}
