#include "binary_trees.h"

/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: tree to check.
 *
 * Return: 1 if full, otherwise 0.
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int ans = 1;

	if (tree && !binary_tree_is_leaf(tree))
	{
		if (!tree->left || !tree->right)
			return (0);
		ans = binary_tree_is_full(tree->left);
		ans = binary_tree_is_full(tree->right);
	}
	return (ans);
}
