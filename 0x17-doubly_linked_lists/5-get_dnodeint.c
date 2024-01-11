#include "lists.h"

/**
 * get_dnodeint_at_index - Retrieves the node at a specified index in a
 *                         doubly linked list.
 * @head: A pointer to the head of the doubly linked list.
 * @index: The index of the node to retrieve.
 *
 * Return: A pointer to the node at the specified index, or NULL if the
 *         index is out of bounds.
 */

dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int counter = 0;

	while (head != NULL)
	{
		if (counter == index)
			return (head);
		counter++;
		head = head->next;
	}

	return (NULL);
}
