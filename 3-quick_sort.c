#include "sort.h"

/**
 * swap - swaps 2 integer values
 * @a: address of first value
 * @b: address of second value
 *
 * Return: void
 */

void swap1(int *a, int *b, int *array, size_t size )
{
		int temp = *a;
		*a = *b;
		*b = temp;
		print_array(array, size);
}

/**
 * lomuto_partition - partitions the array using lomuto partition
 * @array: the integer array to sort
 * @low: low index of the sort range
 * @high: high index of the sort range
 *
 * Return: void
 */

size_t lomuto_partition(int *array, int low, int high)
{
	int pivot = array[high];
	int i = low - 1;
	int j = low + 1;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(&array[i], &array[j]);
		}
	}
	swap(&array[i + 1], &array[high]);

	return (i + 1);
}

/**
 * quicksort - quicksorts using Lomuto partitioning scheme
 * @array: the integer array to sort
 * @low: the low index of the sort range
 * @high: the high index of the sort range
 *
 * Return: void
 */

void quicksort(int *array, int low, int high)
{
	if (low < high)
	{
		int partition = lomuto_partition(array, low, high);

		quicksort(array, low, partition - 1);
		quicksort(array, partition + 1, high);
	}
}

/**
 * quick_sort - sort an array in ascending order
 * @array: the integer array to sort
 * @size: the size of the array
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size == 2)
		return;

	quicksort(array, 0, size - 1);
}
