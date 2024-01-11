#include "lists.h"

/**
 * add_dnodeint_end - Adds a new node with the given value at the end of a
 * doubly linked list.
 * @head: A pointer to a pointer to the head of the list.
 * @n: The integer value to be stored in the new node.
 *
 * Return: A pointer to the newly added node,
 * or NULL if memory allocation fails.
 */

dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new_node, *last;

	new_node = malloc(sizeof(dlistint_t));

	if (new_node == NULL)
		return (NULL);
	new_node->n = n;
	new_node->next = NULL;

	if (*head == NULL)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		last = *head;

		while (last->next != NULL)
			last = last->next;

		last->next = new_node;
		new_node->prev = last;
	}
	return (new_node);
}
