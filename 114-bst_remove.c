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
			return ((bst_t *)tree);
		else if (tree->n > value)
			return (bst_search(tree->left, value));
		else
			return (bst_search(tree->right, value));
	}
	return (NULL);
}

/**
 * transplant - refix the binary search tree
 * @root: ponterto the root.
 * @u: subtree root.
 * @v: the child of u.
 *
 * Return: root.
 */
bst_t *transplant(bst_t *root, bst_t *u, bst_t *v)
{
	if (u->parent)
		root = v;
	else if (u->parent->left == u)
		u->parent->left = v;
	else
		u->parent->right = v;
	if (v)
		v->parent = u->parent;
	return (root);
}

/**
 * bst_remove - removes a node from a binary search tree
 * @root: pointer to the root.
 * @value: value to remove.
 *
 * Return: pointer to the new root, otherwise NULL.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *node, *min;

	node = bst_search(root, value);
	if (!node)
		return (NULL);
	if (!node->left)
	{
		root = transplant(root, node, node->right);
		free(node);
	}
	else if (!node->right)
	{
		root = transplant(root, node, node->left);
		free(node);
	}
	else
	{
		min = node->right;
		while (min->left)
			min = min->left;
		if (min->parent != node)
		{
			root = transplant(root, min, min->right);
			min->right = node->right;
			min->right->parent = min;
		}
		root = transplant(root, node, min);
		min->left = node->left;
		min->left->parent = min;
		free(node);
	}
	return (root);
}
