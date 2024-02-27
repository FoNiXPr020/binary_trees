#include "binary_trees.h"

/**
 * binary_tree_size - Computes the size of a binary tree.
 * @tree: A pointer to the root node of the tree to measure.
 *
 * Return: The size of the tree.
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t iSize = 0;

	if (tree)
	{
		iSize += 1;
		iSize += binary_tree_size(tree->left);
		iSize += binary_tree_size(tree->right);
	}

	return (iSize);
}
