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
int i = 0, k, mid;
int arr[20];
if (n == 0)
return (1);
while (n)
{
arr[i] = n % 10;
n = n / 10;
i++;
}
i--;
k = 0;
mid = i / 2;
while (i != mid)
{
if (arr[i] != arr[k])
return (0);
i--;
k++;
}
return (1);
}
