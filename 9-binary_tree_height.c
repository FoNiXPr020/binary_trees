#include "binary_trees.h"

/**
 * binary_tree_height - Determines the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure.
 *
 * Return: If @tree is NULL, the function
 *			returns 0; otherwise, it returns the height.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t i = 0, j = 0;

		i = tree->left ? 1 + binary_tree_height(tree->left) : 0;
		j = tree->right ? 1 + binary_tree_height(tree->right) : 0;
		return ((i > j) ? i : j);
	}
	return (0);
}
