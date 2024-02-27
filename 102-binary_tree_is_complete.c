#include "binary_trees.h"
#include <stdio.h>

/**
 * binary_is_leaf - Determines if a node is a leaf in a binary tree.
 * @node: Pointer to the node to check.
 *
 * Return: 1 if @node is a leaf, and 0 otherwise. If @node is NULL, return 0.
 */
int binary_is_leaf(const binary_tree_t *node)
{
	if (node != NULL && node->left == NULL && node->right == NULL)
		return (1);

	return (0);
}

/**
 * binary_height - Measures the height of a binary tree.
 * @tree: Pointer to the root node of the tree to measure the height of.
 *
 * Return: The height of the tree. If @tree is NULL, return 0.
 */
size_t binary_height(const binary_tree_t *tree)
{
	size_t leftside, rightside;

	if (tree == NULL)
		return (0);

	leftside = binary_height(tree->left);
	rightside = binary_height(tree->right);

	if (leftside >= rightside)
		return (1 + leftside);

	return (1 + rightside);
}

/**
 * binary_perfect - Checks if a binary tree is perfect.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is perfect, 0 otherwise. If @tree is NULL, return 0.
 */
int binary_perfect(const binary_tree_t *tree)
{
	binary_tree_t *i, *j;

	if (tree == NULL)
		return (1);

	i = tree->left;
	j = tree->right;

	if (binary_is_leaf(tree))
		return (1);

	if (i == NULL || j == NULL)
		return (0);

	if (binary_height(i) == binary_height(j))
	{
		if (binary_perfect(i) && binary_perfect(j))
			return (1);
	}

	return (0);
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is complete, 0 otherwise. If @tree is NULL, return 0.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t iSize, jSize;
	binary_tree_t *i, *j;

	if (tree == NULL)
		return (0);

	if (binary_is_leaf(tree))
		return (1);

	i = tree->left;
	j = tree->right;
	iSize = binary_height(i);
	jSize = binary_height(j);
	if (iSize == jSize)
	{
		if (binary_perfect(i) && binary_tree_is_complete(j))
			return (1);
	}
	else if (iSize == jSize + 1)
	{
		if (binary_tree_is_complete(i) && binary_perfect(j))
			return (1);
	}

	return (0);
}
