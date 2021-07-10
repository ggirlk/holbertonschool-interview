#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    int a[] = {80, 50};
    size_t n;
    n = sizeof(a) / sizeof(a[0]);
    print_array(a, n);
    radix_sort(a, n);
    print_array(a, n);
    n = sizeof(array) / sizeof(array[0]);
    print_array(array, n);
    printf("\n");
    radix_sort(array, n);
    printf("\n");
    print_array(array, n);
    
   
    return (0);
}
