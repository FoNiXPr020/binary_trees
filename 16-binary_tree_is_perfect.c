#include "binary_trees.h"

unsigned char has_leaf(const binary_tree_t *node);
size_t is_depth(const binary_tree_t *tree);
const binary_tree_t *take_leaf(const binary_tree_t *tree);
int is_recursive(const binary_tree_t *tree,
		size_t leaf_depth, size_t level);
int binary_tree_is_perfect(const binary_tree_t *tree);

/**
 * has_leaf - Determines whether a node is a leaf of a binary tree.
 * @node: A pointer to the node to check.
 *
 * Return: If the @node is a leaf, the function
 *			returns 1; otherwise, it returns 0.
 */

unsigned char has_leaf(const binary_tree_t *node)
{
	return ((node->left == NULL && node->right == NULL) ? 1 : 0);
}

/**
 * is_depth - Computes the depth of a given node in a binary tree.
 * @tree: A pointer to the node to measure the depth of.
 *
 * Return: The depth of the node.
 */

size_t is_depth(const binary_tree_t *tree)
{
	return (tree->parent != NULL ? 1 + is_depth(tree->parent) : 0);
}

/**
 * take_leaf - Finds and returns a leaf of a binary tree.
 * @tree: A pointer to the root node of the tree to find a leaf in.
 *
 * Return: A pointer to the first encountered leaf node.
 */

const binary_tree_t *take_leaf(const binary_tree_t *tree)
{
	if (has_leaf(tree) == 1)
		return (tree);
	return (tree->left ? take_leaf(tree->left) : take_leaf(tree->right));
}

/**
 * is_recursive - Determines whether a binary tree is
 *					perfect recursively.
 * @tree: A pointer to the root node of the tree to check.
 * @leaf_depth: The depth of one leaf in the binary tree.
 * @level: The level of the current node.
 *
 * Return: If the tree is perfect, the function
 *			returns 1; otherwise, it returns 0.
 */

int is_recursive(const binary_tree_t *tree,
		size_t leaf_depth, size_t level)
{
	if (has_leaf(tree))
		return (level == leaf_depth ? 1 : 0);
	if (tree->left == NULL || tree->right == NULL)
		return (0);
	return (is_recursive(tree->left, leaf_depth, level + 1) &&
		is_recursive(tree->right, leaf_depth, level + 1));
}

/**
 * binary_tree_is_perfect - Determines whether a binary tree is perfect.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: If @tree is NULL or not perfect, the function
 *			returns 0; otherwise, it returns 1.
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_recursive(tree, is_depth(take_leaf(tree)), 0));
}
