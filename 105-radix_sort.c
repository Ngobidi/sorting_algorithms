#include "sort.h"

int get_max(int *array, int size);
void radix_counting_sort(int *array, size_t size, int sig, int *buff);
void radix_sort(int *array, size_t size);

/**
 * get_max - Obtain the max_value in an array of int.
 * @array: An array of int.
 * @size: The size of the array.
 *
 * Return: The maximum_integer in the array.
 */
int get_max(int *array, int size)
{
	int max, j;

	for (max = array[0], j = 1; j < size; j++)
	{
		if (array[j] > max)
			max = array[j];
	}

	return (max);
}

/**
 * radix_counting_sort - Sort the significant digits of an array of integers
 *                       in ascending order using the counting sort algorithm.
 * @array: An array of int.
 * @size: The size of the array.
 * @sig: The significant-digit to sort on.
 * @buff: A buffer to store the sorted_array.
 */
void radix_counting_sort(int *array, size_t size, int sig, int *buff)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t J;

	for (J = 0; J < size; J++)
		count[(array[J] / sig) % 10] += 1;

	for (J = 0; J < 10; J++)
		count[J] += count[J - 1];

	for (J = size - 1; (int)J >= 0; J--)
	{
		buff[count[(array[J] / sig) % 10] - 1] = array[J];
		count[(array[J] / sig) % 10] -= 1;
	}

	for (J = 0; J < size; J++)
		array[J] = buff[J];
}

/**
 * radix_sort - Sort an array of integers in ascending
 *              order using the radix sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the LSD radix sort algorithm. Prints
 * the array after each significant digit increase.
 */
void radix_sort(int *array, size_t size)
{
	int max, sig, *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	max = get_max(array, size);
	for (sig = 1; max / sig > 0; sig *= 10)
	{
		radix_counting_sort(array, size, sig, buff);
		print_array(array, size);
	}

	free(buff);
}
