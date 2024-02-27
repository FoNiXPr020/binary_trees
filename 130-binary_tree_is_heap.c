#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree.
 *
 * @tree: Pointer to the root of the tree.
 * Return: Size of the tree or 0 if @tree is NULL.
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}

/**
 * tree_complete - Checks if a tree is complete.
 *
 * @tree: Pointer to the root of the tree.
 * @i: Node index.
 * @cnodes: Number of nodes.
 * Return: 1 if the tree is complete, 0 otherwise.
 */

int tree_complete(const binary_tree_t *tree, int i, int cnodes)
{
	if (tree == NULL)
		return (1);

	if (i >= cnodes)
		return (0);

	return (tree_complete(tree->left, (2 * i) + 1, cnodes) &&
		tree_complete(tree->right, (2 * i) + 2, cnodes));
}

/**
 * binary_is_complete - Calls the tree_complete function.
 *
 * @tree: Pointer to the root of the tree.
 * Return: 1 if the tree is complete, 0 otherwise.
 */

int binary_is_complete(const binary_tree_t *tree)
{
	size_t cnodes;

	if (tree == NULL)
		return (0);

	cnodes = binary_tree_size(tree);

	return (tree_complete(tree, 0, cnodes));
}

/**
 * check_parent - Checks if a parent node has a greater value than its children
 *
 * @tree: Pointer to the node.
 * Return: 1 if the parent has a greater value, 0 otherwise.
 */

int check_parent(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);

	if (tree->n > tree->parent->n)
		return (0);

	return (check_parent(tree->left) && check_parent(tree->right));
}

/**
 * binary_tree_is_heap - Checks if a tree is a Max Binary Heap.
 *
 * @tree: Pointer to the root of the tree.
 * Return: 1 if the tree is a Max Binary Heap, 0 otherwise.
 */

int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (!binary_is_complete(tree))
		return (0);

	return (check_parent(tree->left) && check_parent(tree->right));
}
