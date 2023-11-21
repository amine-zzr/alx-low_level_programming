#include "lists.h"

/**
 * pop_listint -deletes the head node of a list.
 * @head: the head node.
 * Return: the head's node data n.
 */

int pop_listint(listint_t **head)
{
	int temp;
	listint_t *ptr;

	if (*head == NULL)
		return (0);
	else
	{
		ptr = *head;
		temp = (*head)->n;
		*head = ptr->next;
		free(ptr);
	}
	return (temp);
}

