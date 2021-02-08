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
int i, k, coef, i2;
int midndec, compmidn, compmindec;
double midn;
k = 0;
coef = 1;
i = numberLen(n);
i2 = (i / 2);
while (k != i2)
{
coef *= 10;
k++;
}
midn = (n / coef);
if (i % 2 != 0)
midn = (midn / 10);
midndec = n % coef;
k = 0;
while (k != i2)
{
coef = (int)coef / 10;
midn = midn / coef;
compmidn = (int)(midn);
midn = (midn *coef)-(compmidn *coef);
compmindec = (int)midndec % 10;
midndec = (int)(midndec / 10);
if (compmindec != compmidn)
return (0);
k++;
}
return (1);
}
