#include "main.h"

/**
 * _isalpha - Checks wether c is an alphabetic character.
 * @c: The character to be checked.
 *
 * Return: 1 if c is an alphabet, 0 otherwise.
*/

int _isalpha(int c)
{
	if ((c >= 'a' || c >= 'A') && (c <= 'z' || c <= 'Z'))
		return (1);
	return (0);
}
