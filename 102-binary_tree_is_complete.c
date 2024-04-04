#include "binary_trees.h"

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	/* A queue to perform level-order traversal */
	const binary_tree_t *queue[10000]; /* Assuming maximum 10000 nodes */
	int front = 0, rear = 0;
	int flag = 0; /* Flag to check if a non-complete node is encountered */

	queue[rear++] = tree;

	while (front < rear)
	{
		const binary_tree_t *current = queue[front++];

		/* If a non-complete node is encountered, set the flag */
		if (!current->left && current->right)
			return (0);
		if (flag && (current->left || current->right))
			return (0);
		if (current->left)
			queue[rear++] = current->left;
		else
			flag = 1;

		if (current->right)
			queue[rear++] = current->right;
		else
			flag = 1;
	}
	return (1);
}
