#include "binary_trees.h"

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

/**
 * binary_tree_is_leaf - checks if a noe is a leaf
 * @node: node to check.
 *
 * Return: 1 if node is leaf, otherwise 0.
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node && !node->left && !node->right)
		return (1);
	return (0);
}
