#include "binary_trees.h"

/**
 * height - measure the height of a tree
 * @tree: pointer to the root.
 *
 * Return: height, otherwise 0.
 */
size_t height(const avl_t *tree)
{
	size_t left = 0, right = 0;

	if (tree)
	{
		if (tree->left)
			left = binary_tree_height(tree->left) + 1;
		if (tree->right)
			right = binary_tree_height(tree->right) + 1;
	}
	return (left > right ? left : right);
}

/**
 * balance - return the balance factor
 * @node: node to check balance.
 *
 * Return: balance, otherwise 0.
 */
int balance(avl_t *node)
{
	if (!node)
		return (0);
	return (height(node->left) - height(node->right));
}

/**
 * avl_insert - inserts a value in an AVL tree
 * @tree: pointer to the root.
 * @value: value to insert.
 *
 * Return: new node, otherwise NULL.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new, *y, *x, *tmp;
	int h;

	if (!tree)
		return (NULL);
	tmp = *tree;
	while (tmp && tmp->left)
	{
		if (value < tmp->n)
			tmp = tmp->left;
		else
			tmp = tmp->right;
	}
	if (!tmp)
		*tree = binary_tree_node(y, value);
	else if (value < tmp->n)
		tmp->left = binary_tree_node(y, value);
	else
		tmp->right = binary_tree_node(y, value);
	y = tmp, tmp = new;
	while (y)
	{
		h = height(y->left) > height(y->right) ? height(y->left) : hight(y->right);
		x = y->parent;
		if (balance(x) <= -2 || balance(x) >= 2)
		{
			if (y == x->left && tmp == x->left->left)
				binary_tree_rotate_right(x);
			else if (y == x->left && tmp == x->left->right)
				binary_tree_rotate_left(y), binary_tree_rotate_right(x);

			else if (y == x->right && tmp == x->right->right)
				binary_tree_rotate_left(x);
			else if (y == x->right && tmp == x->right->left)
				binary_tree_rotate_right(y), binary_tree_rotate_left(x);
			break;
		}
		y = y->parent, tmp = tmp->parent;
	}
	return (new);
}
