#include "lists.h"

/**
 * reverse_listint - reverses a linked list.
 * @head: the head pointer of the list.
 * Return: a pointer to the first node of the reversed list.
 */

listint_t *reverse_listint(listint_t **head)
{
	listint_t *cur, *prev;

	cur = NULL;
	prev = NULL;

	while (*head != NULL)
	{
		cur = (*head)->next;
		(*head)->next = prev;
		prev = *head;
		*head = cur;
	}
	*head = prev;
	return (*head);
}
