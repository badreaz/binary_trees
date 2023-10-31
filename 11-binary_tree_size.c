#include "binary_trees.h"

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
