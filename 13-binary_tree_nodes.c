#include "binary_trees.h"

/**
 * binary_tree_is_leaf- checks if a node is a leaf.
 *
 * @node: pointer to the node to check.
 *
 * Return: 1 if node is leaf, otherwise 0.
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);

	if (node->left  == NULL && node->right == NULL)
		return (1);

	return (0);
}
/**
 * binary_tree_nodes - counts the non-leaf nodes in a binary tree.
 *
 * @tree: pointer to the root node of the tree.
 *
 * Return: the number of non=leaf nodes or 0 if the tree is NULL.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (tree == NULL || binary_tree_is_leaf(tree))
		return (0);

	return (binary_tree_nodes(tree->left) +
			binary_tree_nodes(tree->right) + 1);
}
