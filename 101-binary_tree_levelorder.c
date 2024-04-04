#include "binary_trees.h"

/**
 * binary_tree_levelorder - Goes through a binary tree using level-order
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t h, i;

	if (tree == NULL || func == NULL)
		return;

	h = binary_tree_height(tree) + 1;
	for (i = 0; i < h; i++)
		binary_tree_print_level(tree, func, i);
}

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height
 * Return: The height of the tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height = 0, right_height = 0;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	return ((left_height > right_height ? left_height : right_height) + 1);
}

/**
 * binary_tree_print_level - Prints a level of a binary tree
 * @tree: Pointer to the node of the tree to print
 * @func: Pointer to a function to call for each node
 * @level: The level to print
 */

void binary_tree_print_level(const binary_tree_t *tree,
		void (*func)(int), size_t level)
{
	if (tree == NULL)
		return;

	if (level == 0)
		func(tree->n);
	else if (level > 0)
	{
		binary_tree_print_level(tree->left, func, level - 1);
		binary_tree_print_level(tree->right, func, level - 1);
	}
}
