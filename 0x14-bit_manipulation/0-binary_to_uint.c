#include "main.h"

/**
 * binary_to_uint - converts a binary number to an unsigned int.
 * @b: pointer to a string.
 * Return: the converted number
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int sum = 0;
	int len, i, pos;

	len = strLen(b);

	if (b == NULL)
		return (0);


	for (i = 0; i < len; i++)
	{
		if (b[i] != '0' && b[i] != '1')
			return (0);

		pos = len - i - 1;
		sum += powerOf(b[i] - '0', pos);
	}
	return (sum);
}

/**
 * powerOf - calculate the power of a number.
 * @bin: the number to be calculated.
 * @pos: the position number.
 * Return: the result of the calculation.
 */
unsigned int powerOf(int bin, int pos)
{
	int pow = 1, i = 0;

	while (i < pos)
	{
		pow *= 2;
		pos--;
	}

	return (bin * pow);
}

/**
 * strLen - calculate the length of a string.
 * @s: the string pointer.
 * Return: the length of the string.
 */

int strLen(const char *s)
{
	int len = 0;

	while (*s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}
