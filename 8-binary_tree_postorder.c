#include "binary_trees.h"

/**
 * binary_tree_postorder - Performs post-order traversal on a binary tree.
 * @tree: A pointer to the root node of the tree to traverse.
 * @func: A pointer to a function to execute for each node.
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		binary_tree_postorder(tree->left, func);
		binary_tree_postorder(tree->right, func);
		func(tree->n);
	}
}
