#include "binary_trees.h"

/**
 * binary_tree_node - function that creates a binary node.
 * @parent: pointer to the parent node of the node to create.
 * @value: the value to put in the new node
 * Return: pointer to the new node or NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	new_node = malloc(sizeof(binary_tree_t));
	if (new_node == NULL)
		return (NULL);
	if (parent != NULL)
	{
		if (parent->left == NULL)
			parent->left = new_node;
		else if (parent->right == NULL)
			parent->right = new_node;
		else
			return (NULL);
	}
	new_node->parent = parent;
	new_node->n = value;
	new_node->left = NULL;
	new_node->right = NULL;

	return (new_node);
}
