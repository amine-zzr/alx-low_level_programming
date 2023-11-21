#include "lists.h"

/**
 * free_listint - frees a list malloced space.
 * @head: the head of the list.
 */

void free_listint(listint_t *head)
{
	listint_t *temp;

	temp = head;

	while (temp != NULL)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
