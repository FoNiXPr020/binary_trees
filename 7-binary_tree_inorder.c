#include "binary_trees.h"

/**
 * binary_tree_inorder - Performs in-order traversal on a binary tree.
 * @tree: A pointer to the root node of the tree to traverse.
 * @func: A pointer to a function to execute for each node.
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		binary_tree_inorder(tree->left, func);
		func(tree->n);
		binary_tree_inorder(tree->right, func);
	}
}
