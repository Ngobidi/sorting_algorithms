#include "sort.h"

void swap_ints(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swap_ints - Swap two int in an array.
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
 * lomuto_partition - Order a subset of an array of int according to
 *                    the lomuto partition scheme (last element as pivot).
 * @array: The array of int.
 * @size: array_size.
 * @left: starting_index of the subset to orders.
 * @right: ending_index of the subset to orders.
 *
 * Return: The result partition index.
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot, above, down;

	pivot = array + right;
	for (above = down = left; down < right; down++)
	{
		if (array[down] < *pivot)
		{
			if (above < down)
			{
				swap_ints(array + down, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap_ints(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}

/**
 * lomuto_sort - execute the quicksort algorithm through recursion.
 * @array: An array of int to sort.
 * @size: array_size.
 * @left: starting_index of the array partition to order.
 * @right: ending_index of the array partition to order.
 *
 * Description: adopt the Lomuto partition scheme.
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int p;

	if (right - left > 0)
	{
		p = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, p - 1);
		lomuto_sort(array, size, p + 1, right);
	}
}

/**
 * quick_sort - Sort an array of int in an increasing order
 *              adopting the quicksort algorithm.
 * @array: integers_array.
 * @size: array_size.
 *
 * Description: display the array after swapping each two elements
 *              adopting the Lomuto partition scheme.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
