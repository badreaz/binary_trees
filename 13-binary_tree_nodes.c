#include "binary_tree.h"

/**
 * binary_tree_nodes - counts the nodes with at least 1 child
 * @tree: tree to count the number of nodes.
 *
 * Return: number of nodes, otherwise 0.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t ans = 0;

	if (tree)
	{
		if (!binary_tree_is_leaf(tree))
			ans += 1;
		ans += binary_tree_nodes(tree->left);
		ans += binary_tree_nodes(tree->right);
	}
	return (ans);
}
