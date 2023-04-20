#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * bubble_sort - implements the bubble sort algorithm
 *
 * @array: array of integers
 * @size: size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j, loops;
	int tmp, swapped;

	for (i = 0; i < size - 1; i++)
	{
		swapped = 0;

		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				swapped = 1;
				print_array(array, size);
			}
		}

		if (!swapped)
			break;
	}
}
