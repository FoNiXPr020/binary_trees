#include "binary_trees.h"

size_t computes_height(const binary_tree_t *tree);
int computes_balance(const binary_tree_t *tree);
avl_t *avl_recursive(avl_t **tree, avl_t *parent,
		avl_t **new, int value);
avl_t *avl_insert(avl_t **tree, int value);

/**
 * computes_height - Computes the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: If @tree is NULL, the function
 * returns 0; otherwise, it returns the height.
 */
size_t computes_height(const binary_tree_t *tree)
{
	if (tree != NULL)
	{
		size_t i = 0, j = 0;

		i = tree->left ? 1 + binary_tree_height(tree->left) : 1;
		j = tree->right ? 1 + binary_tree_height(tree->right) : 1;
		return ((i > j) ? i : j);
	}
	return (0);
}

/**
 * computes_balance - Computes the balance factor of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the balance factor.
 *
 * Return: If @tree is NULL, the function
 * returns 0; otherwise, it returns the balance factor.
 */
int computes_balance(const binary_tree_t *tree)
{
	return (tree != NULL ? computes_height(tree->left)
	- computes_height(tree->right) : 0);
}

/**
 * avl_recursive - Inserts a value into an AVL tree recursively.
 * @tree: A double pointer to the root node of the AVL tree to insert into.
 * @parent: The parent node of the current working node.
 * @new: A double pointer to store the new node.
 * @value: The value to insert into the AVL tree.
 *
 * Return: A pointer to the new root node after insertion, or NULL on failure.
 */
avl_t *avl_recursive(avl_t **tree, avl_t *parent,
		avl_t **new, int value)
{
	int manager;

	if (*tree == NULL)
		return (*new = binary_tree_node(parent, value));

	if ((*tree)->n > value)
	{
		(*tree)->left = avl_recursive(&(*tree)->left, *tree, new, value);
		if ((*tree)->left == NULL)
			return (NULL);
	}
	else if ((*tree)->n < value)
	{
		(*tree)->right = avl_recursive(&(*tree)->right, *tree, new, value);
		if ((*tree)->right == NULL)
			return (NULL);
	}
	else
		return (*tree);

	manager = computes_balance(*tree);
	if (manager > 1 && (*tree)->left->n > value)
		*tree = binary_tree_rotate_right(*tree);
	else if (manager < -1 && (*tree)->right->n < value)
		*tree = binary_tree_rotate_left(*tree);
	else if (manager > 1 && (*tree)->left->n < value)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (manager < -1 && (*tree)->right->n > value)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}

	return (*tree);
}

/**
 * avl_insert - Inserts a value into an AVL tree.
 * @tree: A double pointer to the root node of the AVL tree to insert into.
 * @value: The value to insert into the AVL tree.
 *
 * Return: A pointer to the inserted node, or NULL on failure.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *iNew = NULL;

	if (tree == NULL)
		return (NULL);
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	avl_recursive(tree, *tree, &iNew, value);
	return (iNew);
}
