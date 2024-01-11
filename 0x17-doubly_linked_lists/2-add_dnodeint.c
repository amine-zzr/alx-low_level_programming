#include "lists.h"

/**
 * add_dnodeint - Adds a new node at the beginning of a doubly linked list.
 * @head: A pointer to a pointer to the head of the list.
 * @n: The integer value to be stored in the new node.
 *
 * Return: A pointer to the newly added node,
 * or NULL if memory allocation fails.
 */

dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new_node;

	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	if (*head == NULL)
		new_node->next = NULL;
	else
	{
		(*head)->prev = new_node;
		new_node->next = *head;
	}

	new_node->prev = NULL;
	*head = new_node;

	return (new_node);
}
