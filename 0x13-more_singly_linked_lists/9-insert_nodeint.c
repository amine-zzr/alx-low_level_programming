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

	if (head == NULL)
		return (NULL);

	new = malloc(sizeof(listint_t));

	if (new == NULL)
		return (NULL);

	new->n = n;

	if (idx == 0)
	{
		new->next = *head;
		*head = new;
		return (new);
	}

	ptr = *head;

	while (idx != 1)
	{
		if (ptr == NULL)
			return (NULL);

		ptr = ptr->next;
		idx--;
	}

	new->next = ptr->next;
	ptr->next = new;
	return (new);

}
