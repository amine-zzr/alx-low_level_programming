#include <stdio.h>

/**
 * main - Entry point of the program
 *
 * Description: Prints the lowercase alphabet except letter e and q
 * followed by a newline using the putchar function.
 *
 * Return: Always returns 0.
 */

int main(void)
{
	char letter;

	for (letter = 'a'; letter <= 'z'; letter++)
	{
		if (letter == 'e' || letter == 'q')
			letter++;
		putchar(letter);
	}
	putchar('\n');

	return (0);
}

