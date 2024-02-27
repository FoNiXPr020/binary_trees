#include "binary_trees.h"
#include<stdlib.h>
#include<string.h>

#define INIT_NODE {0, NULL, NULL, NULL}

/**
 * heap_swap - Swaps two nodes in a binary tree.
 * @a: Pointer to the first node.
 * @b: Pointer to the second node.
 * Return: Pointer to the root node after swapping.
 */
bst_t *heap_swap(bst_t *a, bst_t *b)
{
	bst_t iCopy = INIT_NODE;

	iCopy.n = a->n;
	iCopy.parent = a->parent;
	iCopy.left = a->left;
	iCopy.right = a->right;
	a->parent = b;
	a->left = b->left;
	a->right = b->right;
	if (b->left)
		b->left->parent = a;
	if (b->right)
		b->right->parent = a;

	b->parent = iCopy.parent;
	if (iCopy.parent)
	{
		if (a == iCopy.parent->left)
			iCopy.parent->left = b;
		else
			iCopy.parent->right = b;
	}
	if (b == iCopy.left)
	{
		b->left = a;
		b->right = iCopy.right;
		if (iCopy.right)
			iCopy.right->parent = b;
	}
	else if (b == iCopy.right)
	{
		b->right = a;
		b->left = iCopy.left;
		if (iCopy.left)
			iCopy.left->parent = b;
	}
	while (b->parent)
		b = b->parent;
	return (b);
}

/**
 * heap_convert - Converts a number into a string
 * representation with a specified base.
 * @num: The input number.
 * @base: The input base.
 * @lowercase: Flag to determine if hexadecimal values should be lowercase.
 * Return: The resulting string representation.
 */
char *heap_convert(unsigned long int num, int base, int lowercase)
{
	static char *iRep;
	static char iBuffer[50];
	char *ptr;

	iRep = (lowercase)
		? "0123456789abcdef"
		: "0123456789ABCDEF";
	ptr = &iBuffer[49];
	*ptr = 0;
	do {
		*--ptr = iRep[num % base];
		num /= base;
	} while (num);

	return (ptr);
}

/**
 * binary_tree_size - Measures the size of a binary tree.
 * @tree: Pointer to the root of the binary tree.
 * Return: The number of descendant child nodes.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * _insert - Helper function to insert a node
 * into the correct location of a binary tree.
 * @root: Double pointer to the root of the max heap.
 * @node: Node to insert.
 */
void _insert(heap_t **root, heap_t *node)
{
	heap_t *iTemp;
	int iSize;
	unsigned int i;
	char *iBinary;
	char iChar;

	iTemp = *root;
	iSize = binary_tree_size(iTemp) + 1;
	iBinary = heap_convert(iSize, 2, 1);
	for (i = 1; i < strlen(iBinary); i++)
	{
		iChar = iBinary[i];
		if (i == strlen(iBinary) - 1)
		{
			if (iChar == '1')
			{
				node->parent = iTemp;
				iTemp->right = node;
				break;
			}
			else if (iChar == '0')
			{
				node->parent = iTemp;
				iTemp->left = node;
				break;
			}
		}
		if (iChar == '1')
			iTemp = iTemp->right;
		else if (iChar == '0')
			iTemp = iTemp->left;
	}
}

/**
 * heap_insert - inserts a value in Max Binary Heap
 * @root: double pointer to root of tree
 * @value: input value
 * Return: pointer to the created node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *heap = NULL, *reet;

	if (!root)
		return (NULL);
	heap = calloc(1, sizeof(heap_t));
	heap->n = value;
	if (!*root)
	{
		*root = heap;
		return (heap);
	}
	_insert(root, heap);
	while (heap->parent && heap->n > heap->parent->n)
	{
		reet = heap_swap(heap->parent, heap);
		if (reet)
			*root = reet;
	}
	return (heap);
}
