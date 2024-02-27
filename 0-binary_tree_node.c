#include "binary_trees.h"

/**
 * binary_tree_node - Creates a binary tree node.
 * @parent: A pointer to the parent of the node to create.
 * @value: The value to put in the new node.
 *
 * Return: If memory allocation fails or if @parent is NULL - NULL.
 *         Otherwise - a pointer to the new node.
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *iNew;

	iNew = malloc(sizeof(binary_tree_t));

	if (iNew == NULL)
		return (NULL);

	iNew->n = value;
	iNew->parent = parent;
	iNew->left = NULL;
	iNew->right = NULL;

	return (iNew);
}
