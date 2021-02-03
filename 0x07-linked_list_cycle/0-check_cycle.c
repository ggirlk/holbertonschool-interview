#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * check_cycle - checks if a singly linked list has a cycle in it
 * @list: pointer to head of list
 * Return: 0 or 1
 */
int check_cycle(listint_t *list)
{
    listint_t *tmp, *current;

    if (list == NULL)
        return (0);
    tmp = (listint_t *)malloc(sizeof(listint_t *));
    if (tmp == NULL)
        return (0);
    current = (listint_t *)malloc(sizeof(listint_t *));
    if (current == NULL)
        return (0);
    tmp = list;
    while (tmp->next != NULL)
    {
        current = tmp;
        while (current->next != NULL)
        {
            if (tmp == current->next)
            {
                return (1);
            }
            current = current->next;
        }
        tmp = tmp->next;
    }
    return (0);
}