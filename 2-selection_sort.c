#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order
 * @array: the array to sort
 * @size: size of the array
 * Return: Nothing
 */
void selection_sort(int *array, size_t size)
{
	size_t i = 0, j = 0, first = 0;
	int temp;

	if (!array || size < 2)
		return;

	while (i < size)
	{
		first = i;
		j = i + 1;
		while (j < size)
		{
			if (array[j] < array[first])
				first = j;
			j++;
		}
		if (first != i)
		{
			temp = array[i];
			array[i] = array[first];
			array[first] = temp;
			print_array(array, size);
		}
		i++;
	}
}
