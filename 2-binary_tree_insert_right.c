#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a node as the right-child
 * @parent: pointer to the node
 * @value: value to store in the new node
 * Return: pointer to the created node or NULL on failure
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node, *old_right;

	if (parent == NULL)
		return (NULL);

	new_node = malloc(sizeof(binary_tree_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = value;
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;

	if (parent->right != NULL)
	{
		old_right = parent->right;
		parent->right = new_node;
		new_node->right = old_right;
		old_right->parent = new_node;
	}
	else
	{
		parent->right = new_node;
	}

	return (new_node);
}
