#include "binary_trees.h"

/**
 * binary_tree_uncle - finds the uncle of a node
 * @node: node to finde the uncle.
 *
 * Return: uncle node, otherwise NULL.
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *parent;

	if (node)
	{
		if (node->parent)
			parent = node->parent->parent;
		if (parent && parent->left == node->parent)
			return (parent->right);
		else if (parent)
			return (parent->left);
	}
	return (NULL);
}
