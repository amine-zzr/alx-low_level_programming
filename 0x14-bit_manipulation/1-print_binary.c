#include "main.h"

/**
 * print_binary - prints the binary represantation of a number.
 * @n: the nubmer to print.
 */

void print_binary(unsigned long int n)
{
	/* using recursion to shift the bits to the right*/
	if (n > 1)
		print_binary(n >> 1);

	/* using the bitwise AND to ectract the first bit*/
	_putchar((n & 1) + '0');
}
