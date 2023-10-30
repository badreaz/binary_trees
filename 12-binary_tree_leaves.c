#include "binary_trees.h"

/**
 * binary_tree_leaves - ounts the leaves in  binary tree
 * @tree: tree to count the number of leaves of.
 *
 * Return: number of leaves, otherwise 0.
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t ans = 0;

	if (tree)
	{
		if (binary_tree_is_leaf(tree))
			ans += 1;
		ans += binary_tree_leaves(tree->left);
		ans += binary_tree_leaves(tree->right);
	}
	return (ans);
}
