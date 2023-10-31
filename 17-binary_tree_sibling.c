#include "binary_trees.h"

/**
 * binary_tree_sibling - finds the sibling of a node
 * @node: node to find the sibling.
 *
 * Return: sibling node, otherwise NULL.
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *parent;

	if (node)
	{
		parent = node->parent;
		if (parent && parent->left == node)
			return (parent->right);
		else
			return (parent->left);
	}
	return (NULL);
}
