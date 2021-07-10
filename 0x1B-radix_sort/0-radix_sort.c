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
    int R = 256, i, r;
    int N = size-1;
    int *aux, *count;

    aux =  malloc(sizeof(int) * size);
    
    count = malloc(sizeof(int) * (R+1));

    for (i=0; i <= N; i++)
        count[array[i]+1]++;

    for (r=0; r < R; r++)
        count[r+1] += count[r];

    for (i=0; i <= N; i++)
        aux[count[array[i]]++] = array[i];

    print_array(array, size);
    for (i=0; i <= N; i++)
        array[i] = aux[i];

    free(aux);
}
