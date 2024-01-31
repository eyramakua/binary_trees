#include "binary_trees.h"

/**
 * binary_tree_nodes - counts the nodes with 1 child in binary tree
 * @tree: pointer to the root node
 * Return: NULL
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t count = 0;

	if (tree == NULL)
		return (0);

	if (tree->right != NULL || tree->left != NULL)
		count += binary_tree_nodes(tree->left) + 1
			+ binary_tree_nodes(tree->right);
	return (count);
}
