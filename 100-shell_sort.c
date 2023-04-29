#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order using the
 * shell sort algorithm, using the Knuth sequence
 * @array: array to be sorted
 * @size: the size of the array
 */
void shell_sort(int *array, size_t size)
{
	int value;
	size_t inner, outer, interval;

	interval = 1;
	while (interval < size / 3)
		interval = interval * 3 + 1;


	while (interval > 0)
	{
		for (outer = interval; outer < size; outer++)
		{
			value = array[outer];
			inner = outer;
			while ((inner > interval - 1) && (array[inner - interval] >= value))
			{
				array[inner] = array[inner - interval];
				inner = inner - interval;
			}
			array[inner] = value;
		}
		interval = (interval - 1) / 3;
		print_array(array, size);
	}
}
