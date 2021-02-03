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
    tmp = list;
    current = tmp->next;
    if (current == NULL)
        return (0);
    if (tmp == current->next)
        return (1);
    while (current->next != NULL)
    {
        if (tmp == current->next)
            return (1);
        if (tmp == NULL)
            return (0);
        if (current == NULL && tmp->next != NULL)
        {
            current = tmp;
            tmp = tmp->next;
        }
        current = current->next;
    }
    return (0);
}
