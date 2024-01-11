#include "lists.h"


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
		new_node->next = *head;

	new_node->prev = NULL;
	*head = new_node;

	return (new_node);
}
