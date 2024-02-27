#include "binary_trees.h"
#include <stdlib.h>


/**
 * sorted_size_binary - Measures the size of a binary tree.
 * @tree: Pointer to the input binary tree.
 * Return: Number of descendant child nodes.
 */
size_t sorted_size_binary(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 + sorted_size_binary(tree->left) + sorted_size_binary(tree->right));
}

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

	szHeap = sorted_size_binary(heap);
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
