#include "lists.h"

/**
 * get_nodeint_at_index -returns the nth node of a list.
 * @head: head of the list.
 * @index: the index of the node.
 * Return: a pointer to the nth node of a list.
 */

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int counter = 0;

	while (head != NULL)
	{
		if (counter == index)
			return (head);

		counter++;
		head = head->next;
	}

	return (NULL);
}
