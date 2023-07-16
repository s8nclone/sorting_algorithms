#include "sort.h"

/**
 * swap - Function
 *
 * @array: array
 * @item1: array element
 * @item2: array element
 *
 * Description: Swaps the position of two elements in an array
*/

void swap(int *array, ssize_t item1, ssize_t item2)
{
	int tmp;

	tmp = array[item1];
	array[item1] = array[item2];
	array[item2] = tmp;
}

/**
 * hoare_partition - Function
 *
 * @array: array
 * @first: first array element
 * @last: last array element
 * @size: size array
 *
 * Return: Position of the last element sorted
 *
 * Description: Implementation of the Hoare partition sorting scheme
 */

int hoare_partition(int *array, int first, int last, int size)
{
	int current = first - 1, finder = last + 1;
	int pivot = array[last];

	while (1)
	{

		do {
			current++;
		} while (array[current] < pivot);
		do {
			finder--;
		} while (array[finder] > pivot);
		if (current >= finder)
			return (current);
		swap(array, current, finder);
		print_array(array, size);
	}
}

/**
 * qs - Function
 *
 * @array: array
 * @first: first array element
 * @last: last array element
 * @size: array size
 *
 * Description: Implementation of quicksort algorithm
 */

void qs(int *array, ssize_t first, ssize_t last, int size)
{
	ssize_t position = 0;

	if (first < last)
	{
		position = hoare_partition(array, first, last, size);
		qs(array, first, position - 1, size);
		qs(array, position, last, size);
	}
}

/**
 * quick_sort_hoare - Function
 *
 * @array: array
 * @size: array size
 *
 * Description: Prepares the terrain to quicksort algorithm
 */

void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	qs(array, 0, size - 1, size);
}
