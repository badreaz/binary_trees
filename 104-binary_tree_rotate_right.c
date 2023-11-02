#include "binary_trees.h"

/**
 * binary_tree_rotate_right - performs a right-rotation on a binary tree
 * @tree: rooot node of the tree.
 *
 * Return: poointer to the new root of the node.
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *x, *y;

	if (!tree || !tree->left)
		return (NULL);
	x = tree;
	y = x->left;
	x->left = y->right;
	if (y->right)
		y->right->parent = x;
	y->parent = x->parent;
	if (y->parent && x == x->parent->left)
		x->parent->left = y;
	else if (y->parent)
		x->parent->right = y;
	x->parent = y;
	y->right = x;
	return (y);
}
