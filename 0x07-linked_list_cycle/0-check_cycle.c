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
    if (!list || !list->next)
        return (0);
    tmp = list;
    current = tmp;
    while (current->next->next)
    {
        if (tmp == current->next->next)
            return (1);

        current = current->next->next;
        tmp = tmp->next;
    }
    return (0);
}
