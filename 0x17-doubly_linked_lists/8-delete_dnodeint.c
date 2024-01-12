#include "lists.h"

/**
 * delete_dnodeint_at_index - Deletes a node at a
 * given index in a doubly linked list.
 * @head: A pointer to a pointer to the head of the doubly linked list.
 * @index: The index of the node to be deleted. Indexing starts at 0.
 *
 * Return: 1 if the deletion is successful, -1 otherwise.
 */

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	unsigned int counter = 0;
	dlistint_t *temp = *head;

	if (head == NULL || *head == NULL)
		return (-1);

	while (temp != NULL && counter != index)
	{
		temp = temp->next;
		counter++;
	}
	if (temp == NULL)
		return (-1);

	if (temp->prev == NULL)
	{
		*head = temp->next;
		if (*head != NULL)
			(*head)->prev = NULL;
		free(temp);
		return (1);
	}
	else if (temp->next == NULL)
	{
		temp->prev->next = NULL;
		free(temp);
		return (1);
	}
	else
	{
		temp->next->prev = temp->prev;
		temp->prev->next = temp->next;
		free(temp);
		return (1);
	}

}
