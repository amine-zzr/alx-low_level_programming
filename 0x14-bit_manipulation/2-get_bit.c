#include "main.h"

/**
 * get_bit - returns the value of a bit at a given index.
 * @n: the number to evaluate.
 * @index: the index of the bit you want to get.
 * Return: the value of the bit at the given index or -1.
 */

int get_bit(unsigned long int n, unsigned int index)
{
	if (index >= sizeof(unsigned long int) * 8)
		return (-1);

	/* right shifting the desired bit and extract it using bitwise AND*/
	return (((n >> index) & 1));
}
