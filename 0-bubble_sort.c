#include "sort.h"

/**
 * bubble_sort - sort an array using bubble sort algorithm
 * @array: array to sort
 * @size: size of the array
 * Return: nothing
*/

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;
	int swap = 1;

	while (swap == 1)
	{
		swap = 0;
		for (i = 0, j = 1; i < size - 1; i++, j++)
		{
			if (array[j] < array[i])
			{
				temp = array[j];
				array[j] = array[i];
				array[i] = temp;
				print_array(array, size);
				swap = 1;
			}
		}
	}
}
