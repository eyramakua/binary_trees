#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree
 * @tree: pointer to the root node
 * Return: pointer node of the new node
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *rotat;

	if (tree == NULL || tree->right == NULL)
	{
		return (NULL);
	}

	rotat = tree->right;
	tree->right = rotat->left;
	if (rotat->left != NULL)
	{
		rotat->left->parent = tree;
	}
	rotat->left = tree;
	rotat->parent = tree->parent;
	tree->parent = rotat;
	return (rotat);
}
