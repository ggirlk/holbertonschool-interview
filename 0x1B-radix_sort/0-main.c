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
    int a[] = {80, 50, 10, 77, 99, 0, 53, 84};
    size_t n;
    n = sizeof(array) / sizeof(array[0]);
    print_array(array, n);
    printf("\n");
    radix_sort(array, n);
    printf("\n");
    print_array(array, n);
    
    n = sizeof(a) / sizeof(a[0]);
    print_array(a, n);
    printf("\n");
    radix_sort(a, n);
    printf("\n");
    print_array(a, n);

    
    
   
    return (0);
}
