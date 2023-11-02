#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree
 * @tree: node of the tree to rotate.
 *
 * Return pointer to the new root node of the tree.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *x, *y;

	if (!tree || !tree->right)
		return (NULL);
	x = tree;
	y = x->right;
	x->right = y->left;
	if (y->left)
		y->left->parent = x;
	y->parent = x->parent;
	if (y->parent && x == x->parent->left)
		x->parent->left = y;
	else if (y->parent)
		x->parent->right = y;
	y->left = x;
	x->parent = y;
	return (y);
}
