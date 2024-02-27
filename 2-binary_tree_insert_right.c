#include "binary_trees.h"

/**
 * binary_tree_insert_right - Inserts a node as the right child
 *                            of another node in a binary tree.
 * @parent: A pointer to the node to insert the right child.
 * @value: The value to store in the new node.
 *
 * Return: If node is NULL or an error occurs - NULL.
 *         Otherwise - a pointer to the new node.
 *
 * Description: If the node already has a right child, the new node
 *              takes its place and the old right child becomes
 *              the right child of the new node.
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *iNew;

	if (parent == NULL)
		return (NULL);

	iNew = binary_tree_node(parent, value);

	if (iNew == NULL)
		return (NULL);

	if (parent->right != NULL)
	{
		iNew->right = parent->right;
		parent->right->parent = iNew;
	}

	parent->right = iNew;

	return (iNew);
}
