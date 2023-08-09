#include "binary_trees.h"

/**
 * binary_tree_uncle - finds the uncle of a node.
 * @node: pointer to the node to find the uncle.
 *
 * Return: a pointer to the uncle node, Otherwise NULL
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *grandParent, *parent;

	if (!node || !node->parent || !node->parent->parent)
		return (NULL);

	parent = node->parent;
	grandParent = node->parent->parent;
	if (grandParent->left == parent && grandParent->right)
		return (grandParent->right);
	else if (grandParent->right == parent && grandParent->left)
		return (grandParent->left);

	return (NULL);
}
