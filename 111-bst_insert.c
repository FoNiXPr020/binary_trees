#include "binary_trees.h"

/**
 * bst_insert - Inserts a value into a Binary Search Tree.
 * @tree: A double pointer to the root node of the BST to insert the value.
 * @value: The value to store in the node to be inserted.
 *
 * Return: A pointer to the created node, or NULL on failure.
 */

bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *iCurrent, *iNew;

	if (tree != NULL)
	{
		iCurrent = *tree;

		if (iCurrent == NULL)
		{
			iNew = binary_tree_node(iCurrent, value);
			if (iNew == NULL)
				return (NULL);
			return (*tree = iNew);
		}

		if (value < iCurrent->n)
		{
			if (iCurrent->left != NULL)
				return (bst_insert(&iCurrent->left, value));

			iNew = binary_tree_node(iCurrent, value);
			if (iNew == NULL)
				return (NULL);
			return (iCurrent->left = iNew);
		}
		if (value > iCurrent->n)
		{
			if (iCurrent->right != NULL)
				return (bst_insert(&iCurrent->right, value));

			iNew = binary_tree_node(iCurrent, value);
			if (iNew == NULL)
				return (NULL);
			return (iCurrent->right = iNew);
		}
	}

	return (NULL);
}
