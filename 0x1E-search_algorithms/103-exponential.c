#include "search_algos.h"

/**
 * exponential_search - Searches for a value in a sorted
 * array using Exponential search algorithm.
 *
 * @array: Pointer to the first element of the array.
 * @size: Number of elements in the array.
 * @value: Value to search for in the array.
 *
 * Return: Index of the value in the array, or -1 if not found.
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t bound = 1, left = bound / 2, right;

	if (!array)
		return (-1);

	if (array[0] == value)
	{
		printf("Value checked array[0] = [%d]\n", array[0]);
		return (0);
	}

	while (bound < size && array[bound] <= value)
	{
		printf("Value checked array[%lu] = [%d]\n", bound, array[bound]);
		bound *= 2;
	}

	right = (bound < size) ? bound : size - 1;

	printf("Value found between indexes [%lu] and [%lu]\n", left, right);

	return (Binary_search(array, left, right, value));
}

/**
 * Binary_search - Searches for a value in a sorted
 * array using Binary search algorithm.
 *
 * @array: Pointer to the first element of the array.
 * @left: Index of the left bound in the array.
 * @right: Index of the right bound in the array.
 * @value: Value to search for in the array.
 *
 * Return: Index of the value in the array, or -1 if not found.
 */
int Binary_search(int *array, size_t left, size_t right, int value)
{
	size_t mid, i;

	while (left <= right)
	{
		mid = left + (right - left) / 2;
		printf("Searching in array:");
		for (i = left; i <= right; ++i)
			printf(" %d,", array[i]);
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
