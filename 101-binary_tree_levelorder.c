#include "binary_trees.h"

/**
 * tree_height - Computes the height of a binary tree.
 * @tree: Pointer to the root node of the tree to measure the height of.
 *
 * Return: The height of the tree. If @tree is NULL, the function returns 0.
 */
size_t tree_height(const binary_tree_t *tree)
{
	size_t leftside, rightside;

	if (tree == NULL)
		return (0);

	leftside = tree_height(tree->left);
	rightside = tree_height(tree->right);

	if (leftside >= rightside)
		return (1 + leftside);

	return (1 + rightside);
}

/**
 * binary_level - Performs a function on nodes at a
 * specific level of a binary tree.
 * @tree: Pointer to the root of the tree.
 * @l: Level of the tree to perform a function on.
 * @func: Function to perform.
 *
 * Return: Void.
 */
void binary_level(const binary_tree_t *tree, size_t l, void (*func)(int))
{
	if (tree == NULL)
		return;

	if (l == 1)
		func(tree->n);
	else if (l > 1)
	{
		binary_level(tree->left, l - 1, func);
		binary_level(tree->right, l - 1, func);
	}
}

/**
 * binary_tree_levelorder - Traverses a binary tree
 * using level-order traversal.
 * @tree: Pointer to the root node of the tree to traverse.
 * @func: Pointer to a function to call for each node.
 * The value in the node must be passed as a parameter to this function.
 *
 * Return: Void.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t iSize, i;

	if (tree == NULL || func == NULL)
		return;

	iSize = tree_height(tree);

	for (i = 1; i <= iSize; i++)
		binary_level(tree, i, func);
}
