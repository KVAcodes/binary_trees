#include "binary_trees.h"

/**
 * check_if_node_exists - checks if a node is on a tree.
 * @tree: a pointer to the tree.
 * @node: a pointer to the tree.
 *
 * Return: 1 if node exists within the tree, Otherwise 0.
 */

size_t check_if_node_exists(const binary_tree_t *tree,
							const binary_tree_t *node)
{
	if (tree == NULL)
		return (0);
	if (tree == node)
		return (1);
	return (check_if_node_exists(tree->left, node) +
			check_if_node_exists(tree->right, node) >= 1 ? 1 : 0);
}
/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes.
 *
 * @first: pointer to the first node.
 * @second: pointer to the second node.
 *
 * Return: pointer to the lowest common ancestor node or NULL if no
 *		   common ancestor was found.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
									 const binary_tree_t *second)
{
	while (first)
	{
		if (check_if_node_exists(first, second))
			return ((binary_tree_t *)first);
		first = first->parent;
	}
	return (NULL);
}
