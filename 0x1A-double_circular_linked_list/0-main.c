#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/**
 * print_list - Print informations about each element of a list
 *
 * @list: A pointer to the head of the linkd list
 *
 * Return: void
 */
void print_list(List *list)
{
    List *tmp;

    tmp = list;
    while (tmp)
    {
        printf("%s\n", tmp->str);
        printf("\t->prev: %s\n", tmp->prev ? tmp->prev->str : "NULL");
        printf("\t->next: %s\n", tmp->next ? tmp->next->str : "NULL");
        tmp = tmp->next;
        if (tmp == list)
            break;
    }
}

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 *
int main(void)
{
    List *list;

    list = NULL;
    add_node_end(&list, "Holberton");
    add_node_end(&list, "School");
    add_node_end(&list, "Full");
    add_node_end(&list, "Stack");
    add_node_end(&list, "Engineer");

    printf("Added to the end:\n");
    print_list(list);
    
    list = NULL;
    add_node_begin(&list, "Holberton");
    add_node_begin(&list, "School");
    add_node_begin(&list, "Full");
    add_node_begin(&list, "Stack");
    add_node_begin(&list, "Engineer");

    printf("Added to the beginning:\n");
    print_list(list);
    
    return (0);
}*/

int main(void)
{
	List *list, *node;

    
	list = NULL;
    
	//node = add_node_begin(&list, "Hello World.");
	node = add_node_end(&list, "Hello World.");
    node->str[10] = 'k';
    printf("%c\n", node->str[10]);
	if (list != node)
		return (1);
	//node->str[11] = '!';
	print_list(node);
	print_list(list);

	return (0);
    /*
    [Expected]
    Hello World!
    ->prev: Hello World!
    ->next: Hello World!
    Hello World!
    ->prev: Hello World!
    ->next: Hello World!

    (114 chars long)
    [stderr]: [Anything]
    */
}

