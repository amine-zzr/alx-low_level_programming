#include <stdio.h>

/**
 * main - entry point of the program
 *
 * Description: prints single numbers of base 10
 *
 * Return: always return 0
*/

int main(void)
{
	int number;

	for (number = 0; number < 10; number++)
	{
		putchar (number + '0');
	}

	putchar('\n');

	return (0);
}
