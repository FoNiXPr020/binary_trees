#include "binary_trees.h"
#include "limits.h"

/**
 * bst_checker - Helper function to check if a binary
 * tree is a valid binary search tree.
 * @tree: A pointer to the root node of the tree to check.
 * @lo: The value of the smallest node visited thus far.
 * @hi: The value of the largest node visited thus far.
 *
 * Return: If the tree is a valid binary search tree,
 * the function returns 1; otherwise, it returns 0.
 */
int bst_checker(const binary_tree_t *tree, int lo, int hi)
{
	if (tree != NULL)
	{
		if (tree->n < lo || tree->n > hi)
			return (0);
		return (bst_checker(tree->left, lo, tree->n - 1) &&
			bst_checker(tree->right, tree->n + 1, hi));
	}

	return (1);
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid binary search tree.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if @tree is a valid binary search tree, and 0 otherwise.
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (bst_checker(tree, INT_MIN, INT_MAX));
}
