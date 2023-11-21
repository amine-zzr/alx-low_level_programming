#include "lists.h"

/**
 * free_listint2 - frees a list malloced space.
 * @head: the head of the list.
 */

void free_listint2(listint_t **head)
{
	listint_t *temp;

	if (head == NULL || *head == NULL)
		return;

	temp = *head;
	while (temp != NULL)
	{
		temp = (*head)->next;
		free(*head);
		*head = temp->next;
	}

	*head = NULL;
}
