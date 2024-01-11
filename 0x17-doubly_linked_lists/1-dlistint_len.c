#include "lists.h"

/**
 * dlistint_len - counts the number of elements in a linked list.
 * @h: the head of the linked list.
 * Return: the number of elements in the list.
 */

size_t dlistint_len(const dlistint_t *h)
{
	size_t counter = 0;

	while (h != NULL)
	{
		counter++;
		h = h->next;
	}

	return (counter);
}
