#include "sort.h"

/**
 * selection_sort - sort an array using selection sort
 * @array: array to sort
 * @size: size of the array
 */

void selection_sort(int *array, size_t size)
{
	int min;
	size_t i, j, index;

	for (i = 0; i < size; i++)
	{
		min = array[i];
		index = i;
		for (j = i; j < size; j++)
		{
			if (array[j] < min)
			{
				min = array[j];
				index = j;
			}
		}
		if (index != i)
		{
			array[index] = array[i];
			array[i] = min;
			print_array(array, size);
		}
	}
}
