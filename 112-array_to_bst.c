#include "binary_trees.h"

/**
 * array_to_bst - builds a binary search tree from an array
 * @array: pointer to the array.
 * @size: number of elements.
 *
 * Return: pointer to the root, otherwise NULL.
 */
bst_t *array_to_bst(int *array, size_t size)
{
	size_t i, j;
	bst_t *root, *node;

	root = NULL;
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < i; j++)
		{
			if (array[i] == array[j])
				break;
		}
		if (i == j)
		{
			node = bst_insert(&root, array[i]);
			if (!node)
				return (NULL);
		}
	}
	return (root);
}
