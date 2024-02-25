#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order
 * @array: the array to sort
 * @size: size of the array
 * Return: Nothing
 */
void shell_sort(int *array, size_t size)
{
	size_t diff = 1, i, j;
	int temp;

	if (!array || size < 2)
		return;

	while (diff < size / 3)
		diff = diff * 3 + 1;
	while (diff >= 1)
	{
		i = diff ;
		while (i < size)
		{
			j = i;
			while (j >= diff && array[j] < array[j - diff])
			{
				temp = array[j];
				array[j] = array[j - diff];
				array[j - diff] = temp;
				j -= diff;
			}
			i++;
		}
		print_array(array, size);
		diff /= 3;
	}
}
