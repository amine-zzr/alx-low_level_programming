#include "lists.h"

/**
 * free_listint2 - frees a list malloced space.
 * @head: the head of the list.
 */

void free_listint2(listint_t **head)
{
	listint_t *temp, *ptr;

	temp = *head;
	if (*head == NULL)
		return;

	while (temp != NULL)
	{
		ptr = temp->next;
		free(temp);
		temp = ptr;
	}

	*head = NULL;
}
