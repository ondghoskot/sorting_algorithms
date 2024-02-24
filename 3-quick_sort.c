#include "sort.h"

/**
 * lomuto - partition scheme
 * @arr: array to sort
 * @lowest: lowest index
 * @highest: highest index
 * @size: size of the array
 * Return: sorted value at index
 */
int lomuto(int *arr, int lowest, int highest, size_t size)
{
	int pivot = arr[highest], i = (lowest - 1);
	int j, temp;

	j = lowest;
	while (j <= highest - 1)
	{
		if (arr[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
				print_array(arr, size);
			}
		}
		j++;
	}
	if (pivot < arr[i + 1])
	{
		temp = arr[i + 1];
		arr[i + 1] = arr[highest];
		arr[highest] = temp;
		print_array(arr, size);
	}
	return (i + 1);
}

/**
 * sort_quick - sorts an array using lomuto
 * @arr: the array to sort
 * @lowest: starting index
 * @highest: finishing index
 * @size: size of the array
 * Return: nu2in
 */
void sort_quick(int *arr, int lowest, int highest, size_t size)
{
	int ptn;

	if (lowest < highest)
	{
		ptn = lomuto(arr, lowest, highest, size);
		sort_quick(arr, lowest, ptn - 1, size);
		sort_quick(arr, ptn + 1, highest, size);
	}
}

/**
 * quick_sort - sorts array of integers in ascending order
 * @array: the array to be sorted
 * @size: the size of the said array
 * Return: not a thing
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	sort_quick(array, 0, size - 1, size);
}
