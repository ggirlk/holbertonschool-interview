#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * radix_sort - sorts an array of integers in ascending
 * ***********  order using the Radix sort algorithm
 * @array: array to be sorted contains only numbers >= 0
 * @size: array size
 * Return: nothing
 */
void radix_sort(int *array, size_t size)
{
    int R, r;
    int *aux, *count;
    size_t i;
        
    R = 256;

    aux =  malloc(sizeof(int) * size);

    count = malloc(sizeof(int) * (R+1));

    if (!array || size == 0 || !aux || !count)
        return;

    for (i=0; i < size; i++)
        count[array[i]+1]++;
    
    for (r=0; r < R; r++)
        count[r+1] += count[r];

    for (i=0; i < size; i++)
        aux[count[array[i]]++] = array[i];

    for (i=0; i < size; i++)
        array[i] = aux[i];

    print_array(array, size);

    free(count);
    free(aux);
}
