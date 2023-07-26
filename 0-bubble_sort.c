#include "sort.h"
#include <stdbool.h>

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
 *bubble_sort - Sort an array on int in ascending oder
 *@array: An array of integers
 *@size: the size of array
 *Dsecription: prints an array after each swap
 */
void bubble_sort(int *array, size_t size)
{
	ssize_t i, len = size;
	bool bubbly = false;

	if (array == NULL || size < 2)
		return;
	while (!bubbly)
	{
		bubbly = true;
		for (i = 0; i < len - 1; i++)
		{
		 /* check if current element is greater than next elements */
			if (array[i] > array[i + 1])
			{
				swap_ints(&array[i], &array[i + 1]);
				bubbly = false;
			/* it calls the func 'print_array' to print the current state of array */
				print_array(array, size);
			}
		}
		len--;
	}
}
