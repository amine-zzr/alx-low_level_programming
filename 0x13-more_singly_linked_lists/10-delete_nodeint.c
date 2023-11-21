#include "lists.h"

/**
 * delete_nodeint_at_index - deletes the node at index of a list.
 * @head: the head of the list.
 * @index: the index of the node that should be deleted.
 * Return: 1 if is succeeded, -1 if it fails.
 */

int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *current, *previous;

	current = *head;
	previous = *head;

	if (*head == NULL)
		return (-1);

	if (index == 0)
	{
		*head = current->next;
		free(current);
		current = NULL;
	}

	else
	{
		while (index != 0)
		{
			if (current == NULL)
				return (-1);

			previous = current;
			current = current->next;
			index--;
		}
		previous->next = current->next;
		free(current);
		current = NULL;
	}
	return (1);
}
