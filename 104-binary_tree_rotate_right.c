#include "binary_trees.h"

/**
 * binary_tree_rotate_right - performs a right rotation on binary tree
 * @tree: pointer to the root node
 * Return: pointer node of the new node
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *rotat;

	if (tree == NULL || tree->left == NULL)
	{
		return (NULL);
	}
	rotat = tree->left;
	tree->left = rotat->right;
	if (rotat->right != NULL)
	{
		rotat->right->parent = tree;
	}
	rotat->right = tree;
	rotat->parent = tree->parent;
	tree->parent = rotat;
	return (rotat);
}
