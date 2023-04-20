#include <stdbool.h>
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
	size_t i;
	int tmp;
	bool swapped;

	while(true)
	{
		swapped = false;
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
				swapped = true;
				print_array(array, size);
			}
		}
		if (!swapped)
			break;
	}
}
