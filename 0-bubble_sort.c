#include "sort.h"

/**
  * bubble_sort - sort array of ints in ascending order
  * @array: The array of integers to sort
  * @size: The size of the array of integers
  *
  * Return: void
  */
void bubble_sort(int *array, size_t size)
{
	int i = 0, aux = 0, max = 0, temp = 1;

	if (!array || size < 2)
		return;

	max = size - 1;

	for (; i < max; ++i)
	{
		if (array[i] > array[i + 1])
		{
			aux = array[i];
			array[i] = array[i + 1];
			array[i + 1] = aux;
			temp = 1;
			print_array(array, size);
		}

		if (temp == 1 && i == max - 1)
			i = -1, temp = 0, --max;
	}
}
