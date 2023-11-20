#include "lists.h"

/**
 * add_nodeint - adds a new node at beginning of a list.
 *
 * @head: the head pointe of the linked list
 * @n: the node element
 * Return: the address of the new element.
 */

listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *ptr;

	ptr = malloc(sizeof(listint_t));

	if (ptr == NULL)
		return (NULL);

	ptr->n = n;
	ptr->next = NULL;

	if (*head == NULL)
		*head = ptr;

	else
	{
		ptr->next = *head;
		*head = ptr;
	}

	return (ptr);
}
