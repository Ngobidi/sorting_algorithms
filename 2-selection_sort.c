#include "sort.h"

/**
 * swap_ints - Swap two int in an arrays.
 * @a: The first_int to swap.
 * @b: The second_int to swap.
 */
void swap_ints(int *a, int *b)
{
	int t;

	t = *a;
	*a = *b;
	*b = t;
}

/**
 * selection_sort - Sort an arrays of int in increasing order
 *                  using the selection sort_algorithm.
 * @array: int array.
 * @size: array_size.
 *
 * Description: display the array after each swap.
 */
void selection_sort(int *array, size_t size)
{
	int *min;
	size_t j, k;

	if (array == NULL || size < 2)
		return;

	for (j = 0; j < size - 1; j++)
	{
		min = array + j;
		for (k = j + 1; k < size; k++)
			min = (array[k] < *min) ? (array + k) : min;

		if ((array + j) != min)
		{
			swap_ints(array + j, min);
			print_array(array, size);
		}
	}
}
