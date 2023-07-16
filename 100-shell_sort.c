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

void swap(int *array, int item1, int item2)
{

	int tmp;

	tmp = array[item1];
	array[item1] = array[item2];
	array[item2] = tmp;
}

/**
 * shell_sort - Function
 *
 * @size: size of the array
 * @array: list with numbers
 *
 * Description: Sorts an array of integeres in ascending order using the
 *		shell sort algorithm, using the Knuth sequence
 */

void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, index = 0;

	if (array == NULL || size < 2)
		return;
	while (gap < size / 3)
		gap = 3 * gap + 1;
	while (gap >= 1)
	{
		for (i = gap; i < size; i++)
			for (index = i; index >= gap &&
			 (array[index] < array[index - gap]); index -= gap)
				swap(array, index, index - gap);
		print_array(array, size);
		gap /= 3;
	}
}
