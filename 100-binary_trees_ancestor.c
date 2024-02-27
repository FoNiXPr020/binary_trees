#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest
 * common ancestor of two nodes in a binary tree.
 * @first: Pointer to the first node.
 * @second: Pointer to the second node.
 *
 * Return: If there are no common ancestors, the function returns NULL;
 *         otherwise, it returns a pointer to the common ancestor node.
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *iTemp, *iTemp2;

	if (!first || !second)
		return (NULL);

	if (first == second)
		return ((binary_tree_t *)first);

	iTemp = first->parent, iTemp2 = second->parent;

	if (first == iTemp2 || !iTemp || (!iTemp->parent && iTemp2))
		return (binary_trees_ancestor(first, iTemp2));

	else if (iTemp == second || !iTemp2 || (!iTemp2->parent && iTemp))
		return (binary_trees_ancestor(iTemp, second));

	return (binary_trees_ancestor(iTemp, iTemp2));
}
