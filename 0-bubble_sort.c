#include "sort.h"

/**
 * swap_ints - Swap two int in an array.
 * @a: The first_integer to swap.
 * @b: The second_integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int x;

	x = *a;
	*a = *b;
	*b = x;
}

/**
 * bubble_sort - Sort an array of int in ascending_order.
 * @array: An array of int to sort.
 * @size: The size of the array.
 *
 * Description: display the array_after_each_swap.
 */
void bubble_sort(int *array, size_t size)
{
	size_t j, len = size;
	bool bubbly = false;

	if (array == NULL || size < 2)
		return;

	while (bubbly == false)
	{
		bubbly = true;
		for (j = 0; j < len - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap_ints(array + j, array + j + 1);
				print_array(array, size);
				bubbly = false;
			}
		}
		len--;
	}
}
