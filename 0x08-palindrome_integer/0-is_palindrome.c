#include <stdlib.h>
#include <stdio.h>

#include "palindrome.h"


/**
 * numberLen - number len
 * @n: the number
 *
 * Return: length of n
 */

int numberLen(unsigned long n)
{
unsigned long ulint = 1000000000000000000;
unsigned long k = n;
int i = 0;
while (k)
{
k = k % ulint;
ulint = ulint / 10;
if (k < n)
i++;
}
return (i);
}
/**
 * is_palindrome - checks whether or not a given
 *                 unsigned integer is a palindrome
 * @n: the number to be checked
 *
 * Return: 0 or 1
 */

int is_palindrome(unsigned long n)
{
int i = numberLen(n), k;
int arr[i];
k = i;
while (k)
{
arr[k] = n % 10;
n = n / 10;
k--;
}
k = 1;
while (i)
{
if (arr[i] != arr[k])
return (0);
i--;
k++;
}
return (1);
}
