#include "binary_trees.h"

/**
 * array_to_avl - builds an AVL tree from an array
 * @array: pointer to the array.
 * @size: array size.
 * Return: new tree, otherwise NULL.
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *new = NULL, *ans;
	size_t i, j;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < i; j++)
		{
			if (array[i] == array[j])
				break;
		}
		if (j == i)
		{
			ans = avl_insert(&new, array[i]);
			if (!ans)
				return (NULL);
		}
	}
	return (new);
}
