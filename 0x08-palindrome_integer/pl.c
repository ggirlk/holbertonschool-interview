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
long double ulint = 10000000000000000000.0;
unsigned long l = n;
int i = 0;
/*while (k)
{
k = k % ulint;
ulint = ulint / 10;
if (k < n)
i++;
}*/
while (1)
{
    l = n / ulint;
    if (l > 0) {
        i++;
        if (l == n)
            break;
    }
    ulint = ulint / 10;      
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
int i, k, i2;
int compmidn, compmindec;
unsigned long coef, midndec;
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
printf("%f, %lu\n", midn, midndec);
while (k != i2)
{
coef = coef / 10;
midn = midn / coef;
compmidn = midn;

compmindec = (int)midndec % 10;
midndec = (unsigned long)(midndec / 10);
if (compmindec != compmidn)
return (0);
midn = ((midn *coef)-(compmidn *coef));
printf("%d, %d, %lu\n", compmindec, compmidn, coef);
k++;
}
return (1);
}
