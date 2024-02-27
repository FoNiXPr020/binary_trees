#include "binary_trees.h"

/**
 * array_to_avl - Builds an AVL tree from a sorted array.
 * @array: A pointer to the first element of the sorted array to be converted.
 * @size: The number of elements in @array.
 *
 * Return: A pointer to the root node
 * of the created AVL tree, or NULL upon failure.
 */
avl_t *array_to_avl(int *array, size_t size)
{
	size_t i, j;
	avl_t *iTree = NULL;

	if (array == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < i; j++)
		{
			if (array[j] == array[i])
				break;
		}
		if (j == i)
		{
			if (avl_insert(&iTree, array[i]) == NULL)
				return (NULL);
		}
	}

	return (iTree);
}
