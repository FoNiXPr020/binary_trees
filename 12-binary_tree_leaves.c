#include "binary_trees.h"

/**
 * binary_tree_leaves - Computes the number of leaves in a binary tree.
 * @tree: A pointer to the root node of the tree to count the leaves.
 *
 * Return: The number of leaves in the tree.
 */

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t iLeaver = 0;

	if (tree)
	{
		iLeaver += (!tree->left && !tree->right) ? 1 : 0;
		iLeaver += binary_tree_leaves(tree->left);
		iLeaver += binary_tree_leaves(tree->right);
	}

	return (iLeaver);
}
