#include "sort.h"

/**
 *swap_ints - swaps two integers
 *@a: first int
 *@b: second int
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 *selection_sort - sort an array of integers in ascending order
 *@array: array of int
 *@size: size of array
 *Description: prints the array after each swap
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int *min;

	if (array == NULL)
		return;
	for (i = 0; i < size - 1; i++)
	{
		min = array + i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < *min)
			{
				min = array + j;
			}
		}
		if ((array + i) != min)
		{
			swap_ints(array + i, min);
			print_array(array, size);
		}
	}
}
