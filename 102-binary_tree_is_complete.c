#include "binary_trees.h"

/**
 * struct queue_s - binary tree queue
 *
 * @node: pointer to binary_tree_t.
 * @next: pointer to the next node.
 */
struct queue_s
{
	binary_tree_t *node;
	struct queue_s *next;
};
typedef struct queue_s queue_t;

/**
 * create - create a new node in queque.
 * @node: node to create.
 *
 * Return: new node, otherwise NULL.
 */
queue_t *create(binary_tree_t *node)
{
	queue_t *new;

	new = malloc(sizeof(queue_t));
	if (!new)
		return (NULL);
	new->node = node;
	new->next = NULL;
	return (new);
}

/**
 * push - push a node to the end of a queue.
 * @node: binary tree node.
 * @queue: pointer to queue end.
 * 
 * Return: new node, otherwise NULL.
 */
queue_t *push(binary_tree_t *node, queue_t *queue)
{
	queue_t *new;

	new = create(node);
	if (!new)
		return (NULL);
	queue->next = new;
	queue = new;
}

/**
 * pop - delete the node at the start.
 * @queue: start of a queue.
 */
void pop(queue_t *queue)
{
	queue_t *tmp;

	tmp = queue->next;
	free(queue);
	queue = tmp;
}

/**
 * free_q - frees a queue.
 * @queue: start of a queue.
 */
void free_q(queue_t *queue)
{
	queue_t *tmp;

	while (queue)
	{
		pop(queue);
	}
}

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: tree to check.
 *
 * Return: 1 if complete, otherwise 0.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	queue_t *hqueue, *tqueue, *tmp;
	int flag = 0;

	hqueue = tqueue = create((binary_tree_t *)tree);
	while (hqueue)
	{
		if (hqueue->node->left)
		{
			if (flag)
			{
				free_q(hqueue);
				return (0);
			}
			tmp = push(hqueue->node->left, tqueue);
			if (!tmp)
			{
				free_q(hqueue);
				return (0);
			}
		}

		else
			flag = 1;
		if (hqueue->node->right)
		{
			if (flag)
			{
				free_q(hqueue);
				return (0);
			}
			tmp = push(hqueue->node->left, tqueue);
			if (!tmp)
			{
				free_q(hqueue);
				return (0);
			}
		}
		else
			flag = 1;
		pop(hqueue);
	}
	return (1);
}
