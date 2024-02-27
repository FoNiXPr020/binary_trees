#include "binary_trees.h"
#include "limits.h"

size_t computes_height(const binary_tree_t *tree);
int is_avl(const binary_tree_t *tree, int lo, int hi);
int binary_tree_is_avl(const binary_tree_t *tree);

/**
 * computes_height - Computes the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: If @tree is NULL, the function
 * returns 0; otherwise, it returns the height.
 */

size_t computes_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t i = 0, j = 0;

		i = tree->left ? 1 + computes_height(tree->left) : 1;
		j = tree->right ? 1 + computes_height(tree->right) : 1;
		return ((i > j) ? i : j);
	}
	return (0);
}

/**
 * is_avl - Helper function to check if a binary tree is a valid AVL tree.
 * @tree: A pointer to the root node of the tree to check.
 * @lo: The value of the smallest node visited thus far.
 * @hi: The value of the largest node visited thus far.
 *
 * Return: If the tree is a valid AVL tree,
 * the function returns 1; otherwise, it returns 0.
 */

int is_avl(const binary_tree_t *tree, int lo, int hi)
{
	size_t left, right, diff;

	if (tree != NULL)
	{
		if (tree->n < lo || tree->n > hi)
			return (0);
		left = computes_height(tree->left);
		right = computes_height(tree->right);
		diff = left > right ? left - right : right - left;
		if (diff > 1)
			return (0);
		return (is_avl(tree->left, lo, tree->n - 1) &&
			is_avl(tree->right, tree->n + 1, hi));
	}
	return (1);
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if @tree is a valid AVL tree, and 0 otherwise.
 */

int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_avl(tree, INT_MIN, INT_MAX));
}
