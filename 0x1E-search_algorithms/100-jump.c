#include "search_algos.h"

/**
 * jump_search - Search for a value in a sorted array using Jump search
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in the array
 * @value: Value to search for
 *
 * Return: Index of value in array, or -1 if not found
 */

int jump_search(int *array, size_t size, int value)
{
	size_t step = sqrt(size), start = 0, end = start + step, i;

	if (array == NULL)
		return (-1);

	while (start < size)
	{
		printf("Value checked array[%ld] = [%d]\n", start, array[start]);

		if (end >= size || array[end] >= value)
		{
			printf("Value found between indexes [%ld] and [%ld]\n", start, end);
			if (end >= size)
				end = size - 1;
			for (i = start; i <= end; i++)
			{
				printf("Value checked array[%ld] = [%d]\n", i, array[i]);
				if (array[i] == value)
					return (i);
			}
			break;
		}

		start = end;
		end += step;
	}

	return (-1);
}
