#include "binary_trees.h"

/**
 * binary_tree_balance - Computes the balance factor of a binary tree.
 * @tree: A pointer to the root node of the tree to measure.
 *
 * Return: If @tree is NULL, the function
 *			returns 0; otherwise, it returns the balance factor.
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree)
		return (binary_tree_height(tree->left) - binary_tree_height(tree->right));

	return (0);
}

/**
 * binary_tree_height - Computes the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure.
 *
 * Return: If @tree is NULL, the functios
 *			returns 0; otherwise, it returns the height.
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t i = 0, j = 0;

		i = tree->left ? 1 + binary_tree_height(tree->left) : 1;
		j = tree->right ? 1 + binary_tree_height(tree->right) : 1;
		return ((i > j) ? i : j);
	}

	return (0);
}
