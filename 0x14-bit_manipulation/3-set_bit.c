#include "main.h"

/**
 * set_bit - sets the value of a bit to 1 at a given index.
 * @n: pointer to the number to work on.
 * @index: the index of the bit you want to set.
 * Return: 1 if success or -1 if it failed.
 */

int set_bit(unsigned long int *n, unsigned int index)
{
	if (index >= sizeof(unsigned long int) * 8)
		return (-1);

	/* creating a msk to set the desired bit to 1*/
	*n |= (1 << index);

	return (1);
}
