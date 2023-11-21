#include "lists.h"

/**
 * insert_nodeint_at_index - inserts a new node at a given position.
 * @head: the head of the list.
 * @idx: the index of the list where the new node should be added.
 * @n: the new node data (n).
 * Return: the address of the new node, or NULL if it failed.
 */

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *new, *ptr;
	unsigned int counter = 0;

	new = malloc(sizeof(listint_t));
	new->n = n;
	new->next = NULL;
	ptr = *head;

	if (new == NULL)
		return (NULL);
	while (ptr != NULL && counter != idx)
	{
		counter++;
		ptr = ptr->next;
	}

	if (counter > idx)
		return (NULL);

	new->next = ptr->next;
	ptr->next = new;

	return (new);
}
