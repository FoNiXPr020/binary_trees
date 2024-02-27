#include "binary_trees.h"

/**
 * binary_tree_insert_left - Adds a node as a left child
 *                           of another node in a binary tree.
 * @parent: A pointer to the node to insert the left child.
 * @value: The value to store in the new node.
 *
 * Return: If node is NULL or an error occurs - NULL.
 *         Otherwise - a pointer to the new node.
 *
 * Description: If the node already has a left child, the new node
 *              takes its place and the old left child becomes
 *              the left child of the new node.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *iNew;

	if (parent == NULL)
		return (NULL);

	iNew = binary_tree_node(parent, value);

	if (iNew == NULL)
		return (NULL);

	if (parent->left != NULL)
	{
		iNew->left = parent->left;
		parent->left->parent = iNew;
	}

	parent->left = iNew;

	return (iNew);
}
