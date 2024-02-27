#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Performs a left rotation on a binary tree.
 * @tree: A pointer to the root node of the tree to rotate.
 *
 * Return: A pointer to the new root node after rotation.
 */

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *iTemp, *iTemp2;

	if (tree == NULL || tree->right == NULL)
		return (NULL);

	iTemp = tree->right;
	iTemp2 = iTemp->left;
	iTemp->left = tree;
	tree->right = iTemp2;

	if (iTemp2 != NULL)
		iTemp2->parent = tree;

	iTemp2 = tree->parent;
	tree->parent = iTemp;
	iTemp->parent = iTemp2;

	if (iTemp2 != NULL)
	{
		if (iTemp2->left == tree)
			iTemp2->left = iTemp;
		else
			iTemp2->right = iTemp;
	}

	return (iTemp);
}
