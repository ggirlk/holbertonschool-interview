#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * insert_node - insert node
 * @head: list
 * @number: number
 *
 * Return: list.
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *h;
	int t = 0;

	if ((*head) == NULL)
	{
		return (NULL);
	}
	h = NULL;
	while (*head)
	{
		if ((number < (*head)->n) && t == 0)
		{
			add_nodeint_end(&h, number);
			t = 1;
		}
		add_nodeint_end(&h, (*head)->n);
		*head = (*head)->next;
	}
	(*head) = h;
	return (*head);
}
