#include "binary_trees.h"

/**
 * bst_insert - inserts a value in a binary search tree
 * @tree: double pointer to the root of bst.
 * @value: value to store in the node.
 *
 * Return: pointer to the node, otherwise NULL.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new, *tmp = NULL, *ptr;

	if (!tree)
		return (NULL);
	ptr = *tree;
	while (ptr)
	{
		tmp = ptr;
		if (value < ptr->n)
			ptr = ptr->left;
		else
			ptr = ptr->right;
	}
	new = binary_tree_node(tmp, value);
	if (!tmp)
		*tree = new;
	else if (value < tmp->n)
		tmp->left = new;
	else
		tmp->right = new;
	return (new);
}
