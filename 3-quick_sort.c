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
 *lomuto_partition - order a subset of ints according to the lomuto partition
 *@array: array of ints
 *@size: size of integers
 *@left: starting index of subset to order
 *@right: ending index of subset
 *Return: final partition index
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	/* set pivot pointer to the right most of the range */
	int *pivot = array + right;
	int i, j;

	for (i = j = left; j < right; j++)
	{
	/* check if current elemet is smaller than pivot */
		if (array[j] < *pivot)
		{
			if (i < j)
			{
				swap_ints(array + j, array + i);
				print_array(array, size);
			}
			i++;
		}
	}
	/* if element @ current pivot posi is greater than pivot */
	if (array[i] > *pivot)
	{
		swap_ints(array + i, pivot);
		print_array(array, size);
	}
	return (i);
}



/**
 *lomuto_quicksort - order a subset of ints according to the lomuto partition
 *@array: array of ints
 *@size: size of integers
 *@left: starting index of subset to order
 *@right: ending index of subset
 */
void lomuto_quicksort(int *array, size_t size, int left, int right)
{
	if (left < right)
	{
		int partition = lomuto_partition(array, size, left, right);

		lomuto_quicksort(array, size, left, partition - 1);
		lomuto_quicksort(array, size, partition + 1, right);
	}
}

/**
 *quick_sort - order a subset of ints according to the lomuto partition
 *@array: array of ints
 *@size: size of integers
 *Description: use lomuto partition scheme to print array in ascending order
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_quicksort(array, size, 0, size - 1);
}
