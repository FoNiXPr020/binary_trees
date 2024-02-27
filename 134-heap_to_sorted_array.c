#include "binary_trees.h"
#include <stdlib.h>

/**
 * heap_to_sorted_array - Converts a Binary Max Heap
 * to a sorted array of integers.
 * @heap: Pointer to the root node of the heap to convert.
 * @size: Address to store the size of the array.
 * Return: Sorted array of integers.
 */
 
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int iExtract, i = 0;
	size_t szHeap;
	int *iArray;

	if (!heap)
		return (NULL);

	szHeap = binary_tree_size(heap);
	*size = szHeap;
	iArray = malloc(szHeap * sizeof(int));

	if (!iArray)
		return (NULL);

	while (heap)
	{
		iExtract = heap_extract(&heap);
		iArray[i] = iExtract;
		i++;
	}

	return (iArray);
}
