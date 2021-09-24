#include <stdlib.h>
#include <stdio.h>
#include "regex.h"

#include <regex.h>

/**
 * regex_match - checks whether a given pattern matches a given string
 * @str: is the string to scan
 * @pattern: is the regular expression
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */

int regex_match(char const *str, char const *pattern)
{
    regex_t re;
    if (regcomp(&re, pattern, REG_EXTENDED|REG_NOSUB) != 0) return 0;
    int status = regexec(&re, str, 0, NULL, 0);
    regfree(&re);
    if (status != 0) return 0;
    return 1;
}
