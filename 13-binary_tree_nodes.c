#include "binary_trees.h"

/**
 * binary_tree_nodes - Computes the number of nodes
 *						with at least one child in a binary tree.
 * @tree: A pointer to the root node of the tree to count the nodes.
 *
 * Return: If @tree is NULL, the function
 *			returns 0; otherwise, it returns the number of nodes.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t iNode = 0;

	if (tree)
	{
		iNode += (tree->left || tree->right) ? 1 : 0;
		iNode += binary_tree_nodes(tree->left);
		iNode += binary_tree_nodes(tree->right);
	}

	return (iNode);
}
