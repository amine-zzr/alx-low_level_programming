#include "search_algos.h"


/**
 * binary_search - Search for a value in a sorted array using binary search
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in the array
 * @value: Value to search for
 *
 * Return: Index of value in array, or -1 if not found
 */

int binary_search(int *array, size_t size, int value)
{
	size_t left = 0, right = size - 1, mid, i;
	if (array == NULL)
		return (-1);

	while (left <= right)
	{
		mid = left + (right - left) / 2;
		printf("Searching in array: ");

		for (i = left; i <= right; i++)
		{
			if (i != left)
				printf(", ");
			printf("%d", array[i]);
		}

		printf("\n");

		if (array[mid] == value)
			return (mid);
		else if (array[mid] < value)
			left = mid + 1;
		else
			right = mid - 1;
	}

	return (-1);
}
