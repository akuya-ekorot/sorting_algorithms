#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * lomuto - lomuto partition algo for qs
 * @array: the array to sort
 * @size: size of the array
 * @lo: the lo boundary
 * @hi: the hi boundary
 *
 * Return: the index of the pivot
 */
static int lomuto(int *array, size_t size, int lo, int hi)
{
	int i, j, pivot, tmp;

	i = lo - 1;
	pivot = array[hi];

	for (j = lo; j < hi; j++)
	{
		if (array[j] <= pivot)
		{
			++i;
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
			print_array(array, size);
		}
	}

	++i;
	tmp = array[i];
	array[i] = array[hi];
	array[hi] = tmp;
	print_array(array, size);

	return (i);
}

/**
 * qs - recursive quicksort algo
 * @array: the array to sort
 * @size: the size of the array
 * @lo: the lo boundary
 * @hi: the hi boundary
 */
static void qs(int *array, size_t size, int lo, int hi)
{
	int p;

	if (lo < hi)
	{
		p = lomuto(array, size, lo, hi);

		qs(array, size, lo, p - 1);
		qs(array, size, p + 1, hi);
	}
}

/**
 * quick_sort - sorts an array using the quicksort algo
 * @array: the array to sort
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	qs(array, size, 0, size - 1);
}
