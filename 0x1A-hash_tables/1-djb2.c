#include "hash_tables.h"

/**
 * hash_djb2 - Hash function using the djb2 algorithm
 * @str: The string to be hashed
 *
 * Return: The hash value for the given string
 */
unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long int hash = 5381;
	int c;

	while ((c = *str++))
		hash = ((hash << 5) + hash) + c;

	return (hash);
}
