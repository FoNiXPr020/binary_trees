#include "binary_trees.h"

/**
 * array_to_heap - Builds a Max Binary Heap tree from an array.
 * @array: Pointer to the input array.
 * @size: Size of the array.
 * Return: Pointer to the root node of the created Max Binary Heap,
 * or NULL on failure.
 */
heap_t *array_to_heap(int *array, size_t size)
{
	size_t iNum = 0;
	bst_t *core = NULL;

	if (!array)
		return (NULL);
	while (iNum < size)
	{
		heap_insert(&core, array[iNum]);
		iNum++;
	}

	return (core);
}
