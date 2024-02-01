#include "binary_trees.h"

/**
 * r_insert_node - node value insertion in a AVL
 * @tree: type double pointer of root node
 * @parent: parent node of struct AVL
 * @new: type double pointer left or right insertion
 * @nval: insertion value of the AVL
 * Return: pointer to the new root after insertion, otherwise NULL
 */
avl_t *r_insert_node(avl_t **tree, avl_t *parent, avl_t **new, int nval)
{
	int bval;

	if (*tree == NULL)
		return (*new = binary_tree_node(parent, nval));
	if (nval < (*tree)->n)
	{
		(*tree)->left = r_insert_node(&(*tree)->left, *tree, new, nval);
		if ((*tree)->left == NULL)
			return (NULL);
	}
	else if (nval > (*tree)->n)
	{
		(*tree)->right = r_insert_node(&(*tree)->right, *tree, new, nval);
		if ((*tree)->right == NULL)
			return (NULL);
	}
	else
	{
		return (NULL);
	}
	bval = binary_tree_balance(*tree);
	if (bval > 1 && nval < (*tree)->left->n)
	{
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (bval > 1 && nval > (*tree)->left->n)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (bval < -1 && nval > (*tree)->right->n)
	{
		*tree = binary_tree_rotate_left(*tree);
	}
	else if (bval < -1 && nval < (*tree)->right->n)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}
	return (*tree);
}

/**
 * avl_insert - inserts a value into an AVL
 * @tree: type double pointer to the root
 * @value: value to store in the node
 * Return: inserted node, or NULL if fails
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new = NULL;

	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	r_insert_node(tree, *tree, &new, value);
	return (new);
}
