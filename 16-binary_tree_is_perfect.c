#include "binary_trees.h"
#include <math.h>

/**
 * max - returns the greater of two values.
 *
 * @val_1: the first value.
 * @val_2: the second value.
 *
 * Return: the greater of the two values.
 */
size_t max(size_t val_1, size_t val_2)
{
	if (val_1 > val_2)
		return (val_1);
	else
		return (val_2);
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
 * binary_tree_height - measures the height of a binary tree.
 *
 * @tree: pointer to the root node of the tree to measure the
 *		  height.
 *
 * Return: The height of the tree or 0 if tree is NULL.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree == NULL || binary_tree_is_leaf(tree))
		return (0);

	return (max(binary_tree_height(tree->left),
			binary_tree_height(tree->right)) + 1);
}

/**
 * binary_tree_size - measures the size of a binary tree.
 *
 * @tree: pointer to the root node of the tree to measure the size.
 *
 * Return: the size of the tree, 0 if the tree is NULL.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_tree_size(tree->left) +
			binary_tree_size(tree->right) + 1);
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect.
 *
 * @tree: pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is perfect, Otherwise 0.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int size_if_perfect, height;

	if (tree == NULL)
		return (0);
	height = binary_tree_height(tree);
	size_if_perfect = (int) pow(2, (double) height) + 1;

	return ((int) binary_tree_size(tree) == size_if_perfect ?
			1 : 0);
}
