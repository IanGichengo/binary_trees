#include "binary_trees.h"

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 * Return: If tree is NULL or not complete - 0. Otherwise - 1.
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	if (tree->left != NULL && tree->right != NULL)
		return (binary_tree_is_complete(tree->left) &&
				binary_tree_is_complete(tree->right));

	return (0);
}
