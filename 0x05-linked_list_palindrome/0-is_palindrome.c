#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * is_palindrome - palindrom check
 * @head: pointer to head of list
 * Return: 0 or 1
 */

int is_palindrome(listint_t **head)
{
	int size, i, *t;

	i = 0;
	if (head == NULL)
	{
		return (1);
	}
	t = malloc(sizeof(head));
	while (*head)
	{
		t[i] = (*head)->n;
		(*head) = (*head)->next;
		i++;
	}
	size = i;
	if (size % 2 == 0)
	{
		for (i = 0; i < size / 2; i++)
		{
			if (t[i] != t[size - 1 - i])
			{
				return (0);
			}
		}
	}
	else
	{
		for (i = 0; i < size - 1 / 2; i++)
		{
			if (t[i] != t[size - 1 - i])
			{
				return (0);
			}
		}
	}
	return (1);
}
