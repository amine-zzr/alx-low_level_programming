#include <stdio.h>

/**
 *main - entry point to the program
 *
 * Description: print letters in reverse
 *
 * Return: always return 0
*/

int main(void)
{
	char letter;

	for (letter = 'z'; letter >= 'a'; letter--)
	{
		putchar (letter);
	}
	putchar('\n');

	return (0);
}
