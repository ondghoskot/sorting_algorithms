#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 * @array: the array to sort
 * @size: size of the array
 * Return: Nothing
 */
void bubble_sort(int *array, size_t size)
{
	int i = size - 1;
	int temp;

	if (!array || size < 2)
		return;

	while (i >= 1)
	{
		int j = 0;

		while (j < i)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
			}
			j++;
		}
		i--;
	}
}
