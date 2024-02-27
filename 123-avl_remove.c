#include "binary_trees.h"

void rm_balance_avl(avl_t **tree);
int avl_successor(bst_t *node);
int type_remove(bst_t *root);
bst_t *remove_avl(bst_t *root, int value);

/**
 * rm_balance_avl - Computes the balance factor of an AVL tree.
 * @tree: Pointer to the AVL tree to measure the balance factor.
 * Return: The balance factor of the AVL tree.
 */
void rm_balance_avl(avl_t **tree)
{
	int iNum;

	if (tree == NULL || *tree == NULL)
		return;

	if ((*tree)->left == NULL && (*tree)->right == NULL)
		return;

	rm_balance_avl(&(*tree)->left);
	rm_balance_avl(&(*tree)->right);

	iNum = binary_tree_balance((const binary_tree_t *)*tree);

	if (iNum > 1)
		*tree = binary_tree_rotate_right((binary_tree_t *)*tree);
	else if (iNum < -1)
		*tree = binary_tree_rotate_left((binary_tree_t *)*tree);
}

/**
 * avl_successor - Finds the successor of a node in an AVL tree.
 * @node: Pointer to the node to find the successor of.
 * Return: Pointer to the minimum value node in the right subtree of @node.
 */
int avl_successor(bst_t *node)
{
	int iLeft = 0;

	if (node == NULL)
	{
		return (0);
	}
	else
	{
		iLeft = avl_successor(node->left);
		if (iLeft == 0)
		{
			return (node->n);
		}
		return (iLeft);
	}

}
/**
 * type_remove - Removes a node from an AVL tree depending on its children.
 * @root: Pointer to the node to remove.
 * Return: 0 if the node has no children, or another value if it has children.
 */
int type_remove(bst_t *root)
{
	int iValue = 0;

	if (!root->left && !root->right)
	{
		if (root->parent->right == root)
			root->parent->right = NULL;
		else
			root->parent->left = NULL;
		free(root);
		return (0);
	}
	else if ((!root->left && root->right) || (!root->right && root->left))
	{
		if (!root->left)
		{
			if (root->parent->right == root)
				root->parent->right = root->right;
			else
				root->parent->left = root->right;
			root->right->parent = root->parent;
		}
		if (!root->right)
		{
			if (root->parent->right == root)
				root->parent->right = root->left;
			else
				root->parent->left = root->left;
			root->left->parent = root->parent;
		}
		free(root);
		return (0);
	}
	else
	{
		iValue = avl_successor(root->right);
		root->n = iValue;
		return (iValue);
	}
}
/**
 * remove_avl - remove a node from a BST tree
 * @root: root of the tree
 * @value: node with this value to remove
 * Return: the tree changed
 */
bst_t *remove_avl(bst_t *root, int value)
{
	int iType = 0;

	if (root == NULL)
		return (NULL);
	if (value < root->n)
		remove_avl(root->left, value);
	else if (value > root->n)
		remove_avl(root->right, value);
	else if (value == root->n)
	{
		iType = type_remove(root);
		if (iType != 0)
			remove_avl(root->right, iType);
	}
	else
		return (NULL);
	return (root);
}

/**
 * avl_remove - remove a node from a AVL tree
 * @root: root of the tree
 * @value: node with this value to remove
 * Return: the tree changed
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *Tmp_root = (avl_t *) remove_avl((bst_t *) root, value);

	if (Tmp_root == NULL)
		return (NULL);
	rm_balance_avl(&Tmp_root);
	return (Tmp_root);
}
