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
int t = 0;
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
if (current->next != NULL && current->n > number && t == 0)
{
new->next = current->next;
new->n = current->n;
current->next = new;
current->n = number;
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
