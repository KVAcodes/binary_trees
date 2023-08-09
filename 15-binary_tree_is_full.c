#include "binary_trees.h"

/**
 * check_subtree_not_full - checks if a subtree is not full.
 *
 * @tree: the pointer to the subtree.
 *
 * Return: 1 is it is not full <has exactly only child>
 *
 */
int check_subtree_not_full(const binary_tree_t *tree)
{
	if ((tree->right == NULL && tree->left) ||
		(tree->right && tree->left == NULL))
		return (1);
	return (0);
}

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
 * binary_tree_is_full - checks if a binary tree is full.
 *
 * @tree: pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is full, otherwise 0.
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL || check_subtree_not_full(tree))
		return (0);
	if (binary_tree_is_leaf(tree))
		return (1);

	return ((binary_tree_is_full(tree->left) +
			binary_tree_is_full(tree->right)) > 1 ? 1 : 0);

}
