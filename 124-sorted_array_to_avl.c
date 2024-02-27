#include "binary_trees.h"

/**
 * _array_to_avl - Helper function for building AVL tree from sorted array.
 * @array: Pointer to the input array.
 * @start: Starting index of the subarray.
 * @end: Ending index of the subarray.
 * @parent: Pointer to the parent node.
 * Return: A pointer to the newly created node.
 */
avl_t *_array_to_avl(int *array, int start, int end, avl_t *parent)
{
	avl_t *iNew;
	int iNum;

	if (start > end)
		return (NULL);

	iNum = (start + end) / 2;
	iNew = calloc(1, sizeof(avl_t));

	if (!iNew)
		return (NULL);

	iNew->n = array[iNum];
	iNew->parent = parent;
	iNew->left = _array_to_avl(array, start, iNum - 1, iNew);
	iNew->right = _array_to_avl(array, iNum + 1, end, iNew);

	return (iNew);
}

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array.
 * @array: Pointer to the input array.
 * @size: Size of the array.
 * Return: A pointer to the root node of the created AVL tree,
 * or NULL on failure.
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array)
		return (NULL);

	return (_array_to_avl(array, 0, size - 1, NULL));
}
