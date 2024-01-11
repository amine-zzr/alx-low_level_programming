#include "lists.h"

/**
 * insert_dnodeint_at_index - Inserts a new node at a given position in a
 *                            doubly linked list.
 * @h: A pointer to a pointer to the head of the doubly linked list.
 * @idx: The index at which the new node should be inserted.
 * @n: The integer value to be stored in the new node.
 *
 * Return: The address of the new node, or NULL if it failed.
 */

dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	unsigned int counter = 0;
	dlistint_t *temp, *new_node;

	if (h == NULL)
		return (NULL);
	if (idx == 0)
		return (add_dnodeint(h, n));

	temp = *h;
	while (temp != NULL)
	{
		if (counter == idx - 1)
		{
			if (temp->next == NULL)
				return (add_dnodeint_end(h, n));

			new_node = malloc(sizeof(dlistint_t));
			if (new_node == NULL)
				return (NULL);
			new_node->n = n;
			new_node->next = temp->next;
			new_node->prev = temp;
			temp->next->prev = new_node;
			temp->next = new_node;
			return (new_node);
		}
		counter++;
		temp = temp->next;
	}
	return (NULL);
}
