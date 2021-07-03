#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

/**
 * add_node_end - Add a new node to the end of a double
 *                circular linked list
 * @list: the list to modify
 * @str: the string to copy into the new node
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_end(List **list, char *str)
{
	List *ptr = malloc(sizeof(List));
	List *temp;

	if (ptr == NULL)
	{
		return (NULL);
	}
	else
	{
		ptr->str = strdup(str);
		if ((*list) == NULL)
		{
			(*list) = ptr;
			ptr->next = (*list);
			ptr->prev = (*list);
		}
		else
		{
			temp = (*list);
			while (temp->next != (*list))
			{
				temp = temp->next;
			}
			temp->next = ptr;
			ptr->prev = temp;
			(*list)->prev = ptr;
			ptr->next = (*list);
		}
	}
	return (ptr);

}

/**
 * add_node_begin - Add a new node to the beginning of a
 *                double circular linked list
 * @list: the list to modify
 * @str: the string to copy into the new node
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_begin(List **list, char *str)
{
	List *ptr = malloc(sizeof(List));
	List *temp;

	if (ptr == NULL)
	{
		return (NULL);
	}
	else
	{
		ptr->str = str;
		if ((*list) == NULL)
		{
			(*list) = ptr;
			ptr->next = (*list);
			ptr->prev = (*list);
		}
		else
		{
			temp = (*list);
			while (temp->next != (*list))
			{
				temp = temp->next;
			}
			temp->next = ptr;
			ptr->prev = temp;
			(*list)->prev = ptr;
			ptr->next = (*list);
			(*list) = ptr;
		}
	}
	return (ptr);
}
