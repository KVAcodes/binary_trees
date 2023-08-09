#include "binary_trees.h"
#include <math.h>

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
	if (tree)
	{
		size_t l = 0, r = 0;

		l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
		r = tree->right ? 1 + binary_tree_height(tree->right) : 0;
		return ((l > r) ? l : r);
	}
	return (0);
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
 * power - basic power function.
 *
 * @base: value
 * @index: power
 *
 * Return: the base to the power of index
 */
int power(int base, int index)
{
	int tmp = base;

	while (index != 0)
	{
		base *= tmp;
		index--;
	}
	return (base);
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
	size_if_perfect = power(2, (int) height) - 1;

	return ((int) binary_tree_size(tree) == size_if_perfect ?
			1 : 0);
}
