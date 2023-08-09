#include "binary_trees.h"

/**
 * binary_tree_sibling - finds the sibling of node.
 * @node: pointer to the node to find the sibling.
 *
 * Return: a pointer to the sibling node, Otherwise NULL
 *		   if the parent is NULL or node has no sibling i.e
 *		   node->parent->other_child is NULL.
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *parent = node->parent;

	if (!parent || !node)
		return (NULL);

	if (parent->left == node && parent->right)
		return (parent->right);
	else if (parent->right == node && parent->left)
		return (parent->left);

	return (NULL);
}
