#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

/**
 * _memcpy - copies memory area
 * @dest: memory area
 * @src: memory area to copy
 * @n: size of the memory to copy
 *
 * Return: char.
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
unsigned int i = 0, j = 0;
char **str = &dest;
char **strc = &src;
while (i < n && str[i])
{
while (j < n && str[i])
{
str[i][j] = strc[i][j];
j++;
}
i++;
}
return (*str);
}

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
		//ptr->str = strdup(str);
        ptr->str = malloc(sizeof(str));
        ptr->str = _memcpy(ptr->str, str, strlen(str));
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
		//ptr->str = strdup(str);
        ptr->str = malloc(sizeof(str));
        ptr->str = _memcpy(ptr->str, str, strlen(str));
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
