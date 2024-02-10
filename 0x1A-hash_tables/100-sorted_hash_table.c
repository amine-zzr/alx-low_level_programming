#include "hash_tables.h"

/**
 * shash_table_create - Creates a sorted hash table
 * @size: The size of the array
 *
 * Return: A pointer to the newly created sorted hash table
 * or NULL if something went wrong
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *new_table = NULL;

	new_table = malloc(sizeof(shash_table_t));
	if (new_table == NULL)
		return (NULL);

	new_table->size = size;
	new_table->array = calloc(size, sizeof(shash_node_t *));
	if (new_table->array == NULL)
	{
		free(new_table);
		return (NULL);
	}

	new_table->shead = NULL;
	new_table->stail = NULL;

	return (new_table);
}

/**
 * shash_table_set - Inserts a key/value pair into a sorted hash table
 * @ht: The sorted hash table
 * @key: The key, string
 * @value: The value corresponding to a key
 *
 * Return: 1 if the insertion is successful, 0 otherwise
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *new_node;

	/* Check if the hash table or key is NULL or empty */
	if (ht == NULL || key == NULL || *key == '\0')
		return (0);

	/* Create a new node and allocate memory for it */
	new_node = malloc(sizeof(shash_node_t));
	if (new_node == NULL)
		return (0);

	/* Initialize the key/value and next pointers of the new node */
	new_node->key = strdup(key);
	new_node->value = strdup(value);
	new_node->next = NULL;

	/* Check if memory allocation for key/value failed */
	if (new_node->key == NULL || new_node->value == NULL)
	{
		free(new_node->key);
		free(new_node->value);
		free(new_node);
		return (0);
	}

	/* Insert the new node into the sorted linked list */
	if (ht->shead == NULL || strcmp(key, ht->shead->key) <= 0)
	{
		insert_at_head(ht, new_node); /* Insert at the head of the list */
	}
	else
	{
		insert_in_middle(ht, new_node); /* Insert in the middle of the list */
	}

	/* Check if insertion was successful by verifying if the key exists */
	if (shash_table_get(ht, key) == NULL)
		return (0);

	return (1); /* Insertion successful */
}

/**
 * insert_at_head - Inserts a node at the head of a sorted linked list.
 * @ht: A pointer to the sorted hash table.
 * @new_node: The new node to insert.
 *
 * Description: This function inserts a new node at the head of the sorted
 *              linked list in the given sorted hash table.
 */
void insert_at_head(shash_table_t *ht, shash_node_t *new_node)
{
	if (ht->shead == NULL)
	{
		ht->shead = new_node;
		ht->stail = new_node;
	}
	else
	{
		new_node->snext = ht->shead;
		ht->shead->sprev = new_node;
		ht->shead = new_node;
	}
}

/**
 * insert_in_middle - Inserts a node into the middle of a sorted linked list.
 * @ht: A pointer to the sorted hash table.
 * @new_node: The new node to insert.
 *
 * Description: This function inserts a new node into the middle of the sorted
 *              linked list in the given sorted hash table, maintaining the
 *              sorted order.
 */
void insert_in_middle(shash_table_t *ht, shash_node_t *new_node)
{
	shash_node_t *current = ht->shead;

	while (current->snext != NULL && strcmp(
				current->snext->key, new_node->key) < 0)
	{
		current = current->snext;
	}

	new_node->sprev = current;
	new_node->snext = current->snext;
	if (current->snext != NULL)
	{
		current->snext->sprev = new_node;
	}
	else
	{
		ht->stail = new_node;
	}
	current->snext = new_node;
}


/**
 * shash_table_get - Retrieves a value associated with
 * a key in a sorted hash table
 * @ht: The sorted hash table
 * @key: The key to search for
 *
 * Return: The value associated with the element,
 * or NULL if key couldn’t be found
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index;
	shash_node_t *current;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);

	/* Search for the key in the linked list at the computed index */
	current = ht->array[index];
	while (current != NULL)
	{
		if (strcmp(current->key, key) == 0)
			return (current->value); /* Key found, return the associated value */
		current = current->next;
	}

	return (NULL); /* Key not found */
}

/**
 * shash_table_print - Prints a sorted hash table
 * @ht: The sorted hash table to print
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *current;

	if (ht == NULL)
		return;

	printf("{");
	current = ht->shead;
	while (current != NULL)
	{
		printf("'%s': '%s'", current->key, current->value);
		if (current->snext != NULL)
			printf(", ");
		current = current->snext;
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - Prints a sorted hash table in reverse order
 * @ht: The sorted hash table to print
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *current;

	if (ht == NULL)
		return;

	printf("{");
	current = ht->stail;
	while (current != NULL)
	{
		printf("'%s': '%s'", current->key, current->value);
		if (current->sprev != NULL)
			printf(", ");
		current = current->sprev;
	}
	printf("}\n");
}

/**
 * shash_table_delete - Deletes a sorted hash table
 * @ht: The sorted hash table to delete
 */
void shash_table_delete(shash_table_t *ht)
{
	unsigned long int i;
	shash_node_t *current, *temp;

	if (ht == NULL)
		return;

	for (i = 0; i < ht->size; i++)
	{
		current = ht->array[i];
		while (current != NULL)
		{
			temp = current->next;
			free(current->key);
			free(current->value);
			free(current);
			current = temp;
		}
	}

	free(ht->array);
	free(ht);
}
