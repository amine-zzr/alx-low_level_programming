#include "main.h"

/**
 *print_alphabet_x10- printing all the alphabets 10 times using _putchar
 *
*/

void print_alphabet_x10(void)
{
	int alpha, times;

	for (times = 0; times <= 9; times++)
	{

		for (alpha = 'a'; alpha <= 'z'; alpha++)
			_putchar(alpha);
		_putchar('\n');
	}
}
