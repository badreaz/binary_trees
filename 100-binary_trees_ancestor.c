#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: first node.
 * @second: second node.
 *
 * Return: ancestor, otherwise NULL.
 */
binary_tree_t *binary_trees_ancestor(
		const binary_tree_t *first, const binary_tree_t *second)
{
	binary_tree_t *ans = NULL;

	if (first && second)
	{
		if (first == second)
			ans = first;
		binary_trees_ancestor(first->parent, second);
		binary_trees_ancestor(first, second->parent);
	}
	return (ans);
}
