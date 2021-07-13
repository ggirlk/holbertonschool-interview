#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

int isEmpty(int *array, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        if (array[i] != -1)
            return 1;
    }
    return 0;
}
int isIn(int *array, size_t size, int n)
{
    for (size_t i = 0; i < size; i++)
    {
        if (array[i] != n)
            return 1;
    }
    return 0;
}
size_t len(int *array)
{
    int i = 0;
    printf("%s %d\n", "fn", array[i]);
    while(array[i] != -1)
        i++;
    return i;
}
int isSorted(int *array, size_t size)
{
    for (size_t i = 0; i < size-1; i++)
    {
        if (array[i] > array[i + 1])
            return 0;
    }
    return 1;
}
int getLastElement(int *array)
{
    int j = 0;
    while (array[j] != -1)
        j++;
    return array[j-1];
}
int *addToBucket(int *allBucket, int size, int n)
{
    int j = 0;
    while (allBucket[j])// != -1)
        j++;
    //if (j < size)
    size--;
    allBucket[j] = n;
    return allBucket;
}
int *pollFirst(int *allBuckets, size_t size)
{
    int *tmp;
    tmp = malloc(size * sizeof(int));
    tmp = allBuckets;
    
    for (size_t i = 1; i < size; i++)
    {
        tmp[i-1] = allBuckets[i];
    }
    //*allBuckets = *tmp;
    return tmp;
}
int *pollLast(int *allBuckets, size_t size)
{
    int *tmp;
    size_t i = 0;
    tmp = malloc(size * sizeof(int));
    //tmp = allBuckets;
    
    for (i = 0; i < size-1; i++)
    {
        tmp[i] = allBuckets[i];
    }
    tmp[i] = -1;
    //*allBuckets = *tmp;
    return tmp;
} 
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
int *addElemEnd(int *array, size_t size, int n)
{
	size_t i = 0, k = 0;
    size++;
	while (array[i] != -1)
		i++;
    if (k == 0)
        array[i] = n;
    return (array);
}
void delFirstElem(int *array, size_t size)
{
	size_t i;

	for (i = 0; i < size - 1; i++)
	{
		array[i] = array[i + 1];
	}

}
int isIn(int *array, size_t size, int n)
{
	size_t i;

	for (i = 0; i < size; i++)
	{
		if (array[i] == n)
            return (1);
	}
    return (0);
}
int getLastElement(int *array)
{
    int j = 0;
    while (array[j] != -1)
        j++;
    return array[j-1];
}
/**
 * radix_sort - sorts an array of integers in ascending
 * ***********  order using the LSD Radix sort algorithm
 * @array: array to be sorted contains only numbers >= 0
 * @size: array size
 * Return: nothing
 */
void radix_sort_draft(int *array, size_t size)
{
    //int R, r;
    //int *aux, *count;
    //size_t i;
        
    //R = 256;

    //aux =  malloc(sizeof(int) * size);

    //count = malloc(sizeof(int) * (R));
    int k, i, j, temp, min;
    int count = size;
    int dev = 10;
    //if (!array || size == 0 || !aux || !count)
     //   return;

    //for (k = 0; k < 3; k++)
    while (!isSorted(array, size))
      {
         for (i = 0; i < count; i++)
          {
            min = array[i] % dev;
        /* To find minimum LSD */
              k = i;
              for (j = i + 1; j < count;j++)
              {
               if (min > (array[j] % dev))
                  {
                      min = array[j] % dev;
                      k = j;
                 }              
              }
              //temp = array1[t];
              //array1[t] = array1[i];
              //array1[i] = temp;

              temp = array[k];
              array[k] = array[i];
              array[i] = temp;
          }
          //for (j = 0; j < count; j++)
        /*to find MSD */
             // array[j] = array[j] / 10;
        print_array(array, size);
        dev *= 10;
      }
    k++;
        //for (j = 0; j < count; j++)
        /*to find MSD */
              //array[j] = array[j] / 10;
        print_array(array, size);
    //print_array(array, size);

}

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
		dev *= 10;
		mul *= 10;

		free(indx);
		free(buckets);
	}

}
