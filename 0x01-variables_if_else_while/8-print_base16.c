#include <stdio.h>

/**
 *main - entry point of the program
 *
 * Description: printing the hexadicimal digits
 *
 * Return: always return 0
*/

int main(void)
{
	char digit;

	for (digit = '0'; digit <= '9'; digit++)
	{
		putchar(digit);
	}
	for (digit = 'a'; digit <= 'f'; digit++)
	{
		putchar(digit);
	}

	putchar('\n');
	return (0);
}
