#include "sort.h"

/**
 * quick_sort - sort an array of int with quick sort
 * @array: array to sort
 * @size: size of the array
*/

void quick_sort(int *array, size_t size)
{
	partition(array, 0, size - 1, size);
}

/**
 * partition - partitioning an array
 * @array: array to sort
 * @low: lowest index
 * @high: highest index
 * @size: size of the array
*/

void partition(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low > high)
		return;
	pivot = lomuto(array, low, high, size);
	partition(array, low, pivot - 1, size);
	partition(array, pivot + 1, high, size);
}

/**
 * lomuto - lomuto partition
 * @array: array to sort
 * @low: low
 *@high: high
 * @size: size
 * Return: index of the pivot after swaping
*/

int lomuto(int *array, int low, int high, size_t size)
{
	int tmp;
	int pivot = array[high];
	int i, j;

	for (i = j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			if (j != i)
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
				print_array(array, size);
			}
			i++;
		}
	}
	if (i != high)
	{
		tmp = array[i];
		array[i] = array[high];
		array[high] = tmp;
		print_array(array, size);
	}
	return (i);
}
