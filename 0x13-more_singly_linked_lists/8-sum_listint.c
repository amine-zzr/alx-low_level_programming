#include "lists.h"

/**
 * sum_listint - calculate the sum of all the data (n) of a list.
 * @head: the head of te list.
 * Return: the sum of all data of a list.
 */

int sum_listint(listint_t *head)
{
	int sum = 0;

	if (head == NULL)
		return (0);

	else
	{
		while (head != NULL)
		{
			sum += head->n;
			head = head->next;
		}
	}

	return (sum);
}
