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
    current = tmp->next->next;
    if (current->next == NULL)
        return (0);
    while (current->next->next != NULL)
    {
        if (tmp == current)
            return (1);
        if (current->next->next && tmp->next)
        {
            current = current->next->next;
            tmp = tmp->next;
        }
        else
            return (0);
        
    }
    return (0);
}
