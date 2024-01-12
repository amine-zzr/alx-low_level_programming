#include <stdio.h>

/**
 * is_palindrome - Checks if a given number is a palindrome.
 * @number: The number to be checked.
 *
 * Return: 1 if the number is a palindrome, 0 otherwise.
 */

int is_palindrome(int number)
{
	int original = number;
	int reverse = 0;

	while (number > 0)
	{
		reverse = reverse * 10 + number % 10;
		number /= 10;
	}
	return (reverse == original);
}

/**
 * largest_palindrome - Finds the largest palindrome made from the product
 *                           of two 3-digit numbers.
 *
 * Return: The largest palindrome.
 */

int largest_palindrome(void)
{
	int largest = 0;
	int i, j, product;

	for (i = 100; i < 1000; i++)
	{
		for (j = i; j < 1000; j++)
		{
			product = i * j;
			if (is_palindrome(product) && product > largest)
				largest = product;
		}
	}

	return (largest);
}

/**
 * main - Entry point of the program.
 *
 * Return: Always 0 (success).
 */

int main(void)
{
	int result = largest_palindrome();

	FILE *file = fopen("102-result", "w");

	if (file != NULL)
	{
		fprintf(file, "%d", result);
		fclose(file);
	}

	return (0);
}
