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
