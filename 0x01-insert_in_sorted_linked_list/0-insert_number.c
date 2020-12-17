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
	// listint_t *h;
	int t = 0;

	// h = NULL;
	// while (*head)
	// {
	// 	if ((number < (*head)->n) && t == 0)
	// 	{
	// 		add_nodeint_end(&h, number);
	// 		t = 1;
	// 	}
	// 	add_nodeint_end(&h, (*head)->n);
	// 	*head = (*head)->next;
	// }
	// if (t == 0 && (!add_nodeint_end(&h, number)))
	// {
	// 	return (NULL);
	// }
	// (*head) = h;
	// return (*head);

	listint_t *new;
    listint_t *current;

    current = *head;

    new = malloc(sizeof(listint_t));
    if (new == NULL)
        return (NULL);

    new->n = number;
    new->next = NULL;

    if (*head == NULL)
        *head = new;
    else
    {
        while (current != NULL)
        {
        	if (current->next != NULL && current->next->n > number && t == 0)
        	{
                new->next = current->next;
                current->next = new;
                current = new->next;
                t = 1;
        	}
            current = current->next;
        }
        if (t == 0)
        {
            current = *head;
            while (current->next != NULL)
                current = current->next;
            current->next = new;
        }
    }
    
    return (new);
}
