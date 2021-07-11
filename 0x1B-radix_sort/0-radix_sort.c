#include "sort.h"

/**
 * countsort - linear sorting
 * @arr: array to be sorted contains only numbers >= 0
 * @n: array size
 * @place: int
 * Return: nothing
 */

void countsort(int arr[],int n,int place)
{
        int range = 10;
        int i, *freq;
        int *output;

        freq = malloc(sizeof(int) * range);
        output = malloc(sizeof(int) * n);
        if (!freq || !output)
                return;

        for(i = 0; i < n; i++)
                freq[(arr[i] / place) % range]++;

        for(i=1;i<range;i++)
                freq[i] += freq[i-1];

        for(i = n - 1; i >= 0; i--)
        {
                output[freq[(arr[i] / place) % range] - 1] = arr[i];
                freq[(arr[i] / place) % range]--;
        }
        for(i = 0; i < n; i++)
                arr[i] = output[i];
}
/**
 * sort - sorting
 * @arr: array to be sorted contains only numbers >= 0
 * @n: array size
 * @place: int
 * Return: nothing
 */

void sort(int *arr, int n, int maxx)
{
        int mul = 1;

        while(maxx)
        {
                countsort(arr, n, mul);
                print_array(arr, n);
                mul *= 10;
                maxx /= 10;
        }
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
	int i,  maxx;
	int count;

    count = size;
	if (!array || size == 0)
		return;
    maxx = array[0];
    for (i = 1 ; i < count; i++)
    {
        if (maxx < array[i])
        {
            maxx = array[i];
        }
    }
	sort(array, size, maxx);

	

}
