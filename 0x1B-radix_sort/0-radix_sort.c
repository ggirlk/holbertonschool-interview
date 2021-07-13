#include <stdio.h>
#include "sort.h"

/**
 * isSorted - check if the array is sorted
 * @array: array to be sorted contains only numbers >= 0
 * @size: array size
 * Return: nothing
 */
int isSorted(int *array, size_t size)
{
	size_t i;

	for (i = 0; i < size - 1; i++)
	{
		if (array[i] > array[i + 1])
		return (0);
	}
	return (1);
}
/**
 * addElemEnd - add element at the ent of the array
 * @array: array to be sorted contains only numbers >= 0
 * @size: array size
 * @n: integer to be added
 * Return: nothing
 */
int *addElemEnd(int *array, size_t size, int n)
{
	size_t i = 0, k = 0;

	size++;
	while (array[i] != -1)
		i++;
	if (k == 0)
		array[i] = n;
	else
		array[i - 1] = n;
	return (array);
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
	int i, N = size, k = 0, j;
	int dev = 1, mul = 10;
    
    if (!array || !size)
        return;

	while (!isSorted(array, size))
	{
		int **buckets, *indx;

		buckets = (int **) malloc(sizeof(int) * (mul * (N + 1)));
		indx = (int *) malloc(sizeof(int) * (mul * (N + 1)));

		if (!buckets || !indx)
			return;
        
		for (i = 0; i < mul; i++)
		{
			buckets[i] = malloc(sizeof(int) * (mul * (N + 1)));
			if (!buckets[i])
				return;
			for (j = 0; j < N - 1; j++)
				buckets[i][j] = -1;
			indx[i] = 0;
		}

		for (i = 0; i < N; i++)
		{
			k = (array[i] / dev) % mul;

			buckets[k] = addElemEnd(*(&buckets[k]),
						size, array[i]);
			indx[k] += 1;
		}

		k = size - 1;
		j = 0;
		for (i = 0; i < mul; i++)
		{
			int l = indx[i] - 1;

			while (l > 0)
			{
				array[j] = (*buckets[i]);
				j++, l--, k--;
			}

		}
		k = 0;
		for (i = 0; i < mul; i++)
		{
			int l = indx[i];
			if (l > 0)
				for (j = 0; j < l; j++)
					array[k] = buckets[i][j], k++;
		}

		print_array(array, size);
        
		free(indx);
        for (i = 0; i < mul; i++)
        {
            if (buckets[i])
                free(buckets[i]);
        }
		free(buckets);
        dev *= 10;
		mul *= 10;
	}

}