#include "lists.h"

/**
 * sum_dlistint - calculates the sum of all doubly linked list data.
 * @head: pointer to the head of the list.
 *
 * Return: the sum of all list data elements.
 */

int sum_dlistint(dlistint_t *head)
{
	int sum = 0;

	while (head != NULL)
	{
		sum += head->n;
		head = head->next;
	}

	return (sum);
}
