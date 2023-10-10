#include "main.h"

/**
 *print_alphabet- printing all the alphabets using _putchar
 *
*/

void print_alphabet(void)
{
	int alpha;

	for (alpha = 'a'; alpha <= 'z'; alpha++)
		_putchar(alpha);
	_putchar('\n');
}
