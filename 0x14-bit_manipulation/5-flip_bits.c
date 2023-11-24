#include "main.h"

/**
 * flip_bits - returns the number of bits you would need to flip
 *to get from one number to another.
 * @n: first number.
 * @m: second number.
 * Return: number of bits to flip.
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int count = 0;
	unsigned long int nums = n ^ m;

	while (nums != 0)
	{
		count += nums & 1; /*check and add the last bit*/
		nums >>= 1; /*right shift to move to the next bit*/
	}

	return (count);
}
