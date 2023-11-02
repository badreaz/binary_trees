#include "binary_trees.h"

/**
 * print_level - print a level of a binary tree
 * @tree: tree to print level.
 * @level: level number.
 * @func: function to call.
 */
void print_level(const binary_tree_t *tree, int level, void (*func)(int))
{
	if (tree)
	{
		if (level == 1)
			func(tree->n);
		print_level(tree->left, level - 1, func);
		print_level(tree->right, level - 1, func);
	}
}

/**
 * binary_tree_levelorder - goes through a binary tree using
 * level-order traversal
 * @tree: tree to traverse.
 * @func: function to call for each node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int len, i;

	len = binary_tree_height(tree);
	for (i = 0; i < len; i++)
		print_level(tree, i + 1, func);
}

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: tree to measure height of.
 *
 * Return: tree size, otherwise NULL.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left = 0, right = 0;

	if (tree)
	{
		if (tree->left)
			left = binary_tree_height(tree->left) + 1;
		if (tree->right)
			right = binary_tree_height(tree->right) + 1;
		return (right > left ? right : left);
	}
	return (0);
}
