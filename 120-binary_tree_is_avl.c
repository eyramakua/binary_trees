#include "binary_trees.h"

/**
 * binary_tree_height - Func that measures height of binary tree
 * @tree: tree to go through
 * Return: the height
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t i = 0;
	size_t j = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		if (tree)
		{
			i = tree->left ? 1 + binary_tree_height(tree->left) : 1;
			j = tree->right ? 1 + binary_tree_height(tree->right) : 1;
		}
		return ((i > j) ? i : j);
	}
}

/**
 * bal_avl - func to compare each subtree is AVL
 * @tree: pointer node to the root
 * @high: node that point to higher node selected
 * @lower: node that point to the lower node selected
 * Return: 1 if the tree is AVL, 0 if it is not
 */
int bal_avl(const binary_tree_t *tree, int lower, int high)
{
	size_t height_i, height_j, balance;

	if (tree != NULL)
	{
		if (tree->n > high || tree->n < lower)
		{
			return (0);
		}
		height_i = binary_tree_height(tree->left);
		height_j = binary_tree_height(tree->right);
		balance = height_i > height_j ? height_i - height_j : height_j - height_i;
		if (balance > 1)
		{
			return (0);
		}
		return (bal_avl(tree->left, lower, tree->n - 1) &&
				bal_avl(tree->right, tree->n + 1, high));
	}
	return (1);
}



/**
 * binary_tree_is_avl - checks if the binary is a valid AVL Tree
 * @tree: pointer to the root node
 * Return: 1 if tree is valid and 0 if otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}
	return (bal_avl(tree, INT_MIN, INT_MAX));
}
