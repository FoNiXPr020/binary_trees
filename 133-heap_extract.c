#include "binary_trees.h"

#define INIT_NODE {0, NULL, NULL, NULL}

#define CONVERT "0123456789ABCDEF"

#define SETUP_NODE_BLOC { \
	iTemp = *root; \
	iSize = binary_tree_size(*root); \
	iBinary = &iBuffer[49]; \
	*iBinary = 0; \
}

#define FREE_NODE_BLOC { \
		iRes = iTemp->n; \
		free(iTemp); \
		*root = NULL; \
	}

#define SWAP_HEAD_BLOC {  \
		iHead = *root; \
		iHead = swap_node(iHead, iTemp); \
		iRes = iHead->n; \
		free(iHead); \
		*root = iTemp; \
		iTemp = percolates_down(iTemp); \
		*root = iTemp; \
}

#define CONVERT_LOOP { \
		*--iBinary = CONVERT[iSize % 2]; \
		iSize /= 2; \
}

/**
 * h_swap - Swaps two nodes in a binary tree.
 * @a: Pointer to the first node.
 * @b: Pointer to the second node.
 * Return: Pointer to the root node after swapping.
 */
bst_t *h_swap(bst_t *a, bst_t *b)
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
 * swap_node - Helper function to swap head and node in a binary tree.
 * @head: Pointer to the head node.
 * @node: Pointer to the node.
 * Return: Pointer to the severed head of the tree.
 */

heap_t *swap_node(heap_t *head, heap_t *node)
{
	if (node->parent->left == node)
	{
		node->parent->left = NULL;
	} else
		node->parent->right = NULL;
	node->parent = NULL;
	node->left = head->left;
	node->right = head->right;
	if (head->left)
		head->left->parent = node;
	if (head->right)
		head->right->parent = node;
	return (head);
}

/**
 * percolates_down - Percolates head into
 * the correct position in a binary tree.
 * @node: Pointer to the head node.
 * Return: Pointer to the head of the tree.
 */
heap_t *percolates_down(heap_t *node)
{
	int iMax;
	heap_t *next = node;

	if (!node)
		return (NULL);
	iMax = node->n;
	if (node->left)
		iMax = MAX(node->left->n, iMax);
	if (node->right)
		iMax = MAX(node->right->n, iMax);
	if (node->left && iMax == node->left->n)
		next = node->left;
	else if (node->right && iMax == node->right->n)
		next = node->right;
	if (next != node)
	{
		h_swap(node, next);
		percolates_down(node);
	}
	return (next);
}

/**
 * heap_extract - Extracts the root node of a Max Binary Heap.
 * @root: Double pointer to the root of the tree.
 * Return: Value stored in the root node.
 */
int heap_extract(heap_t **root)
{
	size_t iSize, i;
	char *iBinary, c, iBuffer[50];
	int iRes;
	heap_t *iTemp, *iHead;

	if (!root || !*root)
		return (0);
	SETUP_NODE_BLOC;
	if (iSize == 1)
	{
		FREE_NODE_BLOC;
		return (iRes);
	}
	do {
		CONVERT_LOOP;
	} while (iSize);
	for (i = 1; i < strlen(iBinary); i++)
	{
		c = iBinary[i];
		if (i == strlen(iBinary) - 1)
		{
			if (c == '1')
			{
				iTemp = iTemp->right;
				break;
			}
			else if (c == '0')
			{
				iTemp = iTemp->left;
				break;
			}
		}
		if (c == '1')
			iTemp = iTemp->right;
		else if (c == '0')
			iTemp = iTemp->left;
	}
	SWAP_HEAD_BLOC;
	return (iRes);
}
