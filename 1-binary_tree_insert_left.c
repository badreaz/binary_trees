#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts node as the left-child of another node
 * @parent: node parent.
 * @value: node value.
 *
 * Return: pointer to the node, otherwise NULL.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *node;

	if (!parent)
		return (NULL);
	node = malloc(sizeof(binary_tree_t));
	if (!node)
		return (NULL);
	node->n = value;
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;
	if (parent->left)
	{
		node->left = parent->left;
		parent->left = node;
		node->left->parent = node;
		return (node);
	}
	parent->left = node;
	return (node);
}
