#include "binary_trees.h"

/**
 * binary_tree_is_bst - checks if a binary tree is a valid
 *  binary search tree
 * @tree: tree to check.
 *
 * Return: 1 if tree is bst, otherwise 0.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree && tree->parent)
	{
		if (!binary_tree_is_bst(tree->left))
			return (0);
		if (tree->n <= tree->parent->n)
			return (0);
		return (binary_tree_is_bst(tree->right));
	}
	return (0);
}
