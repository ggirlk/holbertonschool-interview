#include <stdlib.h>
#include <stdio.h>

#include "palindrome.h"


/**
 * is_palindrome - checks whether or not a given
 *                 unsigned integer is a palindrome
 * @n: the number to be checked
 *
 * Return: 0 or 1
 */

int is_palindrome(unsigned long n)
{
int i = 0, k, mid=-1;
int arr[20];
while (n)
{
arr[i] = n % 10;
n = n / 10;
i++;
}
k = 0;
mid = i / 2;
while (i != mid)
{
i--;
if (arr[i] != arr[k])
return (0);
k++;
}
return (1);
}
