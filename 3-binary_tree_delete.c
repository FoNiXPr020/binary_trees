#include "binary_trees.h"

/**
 * binary_tree_delete - Removes a binary tree and frees its memory.
 * @tree: A pointer to the root node of the tree to remove.
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree != NULL)
	{
		binary_tree_delete(tree->left);
		binary_tree_delete(tree->right);
		free(tree);
	}
}
