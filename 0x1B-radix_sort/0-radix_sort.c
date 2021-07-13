#include <stdio.h>
#include "sort.h"

/**
 * getMax - get maximum number of an array
 * @array: array to be sorted contains only numbers >= 0
 * @size: array size
 * Return: max
 */
int getMax(int *array, int size)
{
	int i = 0, max = array[0];

	for (i = 1; i < size; i++)
	{
		if (max < array[i])
			max =  array[i];
	}
	return (max);
}
/**
 * addElemEnd - add element at the ent of the array
 * @array: array to be sorted contains only numbers >= 0
 * @n: integer to be added
 * Return: nothing
 */
int *addElemEnd(int *array, int n)
{
	size_t i = 0, k = 0;

	while (array[i] != -1)
		i++;
	if (k == 0)
		array[i] = n;
	else
		array[i - 1] = n;
	return (array);
}
/**
 * sort - add element at the ent of the array
 * @array: array to be sorted contains only numbers >= 0
 * @size: integer to be added
 * @buckets: 2d array of collected numbers
 * @indx: sizes of each bucket
 * @dev: for division
 * @mul: for mode
 * Return: nothing
 */
void sort(int *array, size_t size, int **buckets, int *indx, int dev, int mul)
{
	int i, N = size, k = 0, j, l;

	for (i = 0; i < mul; i++)
	{
		buckets[i] = malloc(sizeof(int) * ((N + 1)));
		if (!buckets[i])
			return;
		for (j = 0; j < N; j++)
			buckets[i][j] = -1;
		indx[i] = 0;
	}
	for (i = 0; i < N; i++)
	{
		k = (array[i] / dev) % mul;
		if (!*(buckets[k]))
			return;
		addElemEnd(*(&buckets[k]), array[i]);
		indx[k] += 1;
	}
	k = size - 1, j = 0;
	for (i = 0; i < mul; i++)
	{
		l = indx[i] - 1;
		while (l > 0)
			array[j] = (*buckets[i]), j++, l--, k--;
	}
	k = 0;
	for (i = 0; i < mul; i++)
	{
		l = indx[i];
		if (l > 0)
			for (j = 0; j < l; j++)
				array[k] = buckets[i][j], k++;
	}
	dev *= 10;
}
/**
 * radix_sort - sorts an array of integers in ascending
 * ***********  order using the LSD Radix sort algorithm
 * @array: array to be sorted contains only numbers >= 0
 * @size: array size
 * Return: nothing
 */
void radix_sort(int *array, size_t size)
{
	int i, N = size, max, dev = 1, mul = 10, **buckets, *indx;

	if (!array || size < 2)
		return;
	max = getMax(array, size);

	while (max > 0)
	{
		buckets = (int **) malloc(sizeof(int) * (mul * (N + 1)));
		indx = (int *) malloc(sizeof(int) * ((N + 1)));
		if (!buckets || !indx)
			return;
		sort(array, size, buckets, indx, dev, mul);
		print_array(array, size);
		free(indx);
		for (i = 0; i < mul; i++)
			if (buckets[i])
				free(buckets[i]);
		free(buckets);
		dev *= 10;
		max /= 10;
	}
}
