#include "binary_trees.h"

/**
 * bst_search - searches for a value in a binary search tree
 * @tree: pointer to the root.
 * @value: value to search.
 *
 * Return: value to the node, otherwise NULL.
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree)
	{
		if (tree->n == value)
			return (tree);
		else if (tree->n > value)
			return (tree->left, value);
		else
			return (tree->right, value);
	}
	return (NULL);
}
