#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
* get_a_queue - create a queue node
* @node: pointer to the queue node
* Return: queue node
*/
queue_t *get_a_queue(binary_tree_t *node)
{
queue_t *q = (queue_t *)malloc(sizeof(queue_t));
if (q == NULL)
return (NULL);
q->next = NULL;
q->node = node;
return (q);
}
/**
* free_queue - function to free queue's memory
* @q: double pointer to the queue node
* Return: nothing
*/
void free_queue(queue_t **q)
{
queue_t *current_q = *q;
while (current_q != NULL)
{
*q = current_q->next;
free(current_q);
current_q = *q;
}
}
/**
* queue_put - put nodes into queue
* @node: pointer to the queue node
* @last: double pointer to the queue node
* Return: nothing
*/
void queue_put(binary_tree_t *node, queue_t **last)
{
if (node->left != NULL)
{
(*last)->next = get_a_queue(node->left);
(*last) = (*last)->next;
}
if (node->right != NULL)
{
(*last)->next = get_a_queue(node->right);
(*last) = (*last)->next;
}
}
/**
* swap - swap nodes values
* @current_node: pointer to the node
* Return: nothing
*/
void swap(binary_tree_t *current_node)
{
while (current_node->parent != NULL &&
current_node->parent->n < current_node->n)
{
/*swap the value*/
int tmp = current_node->parent->n;
current_node->parent->n = current_node->n;
current_node->n = tmp;
current_node = current_node->parent;
}
}
/**
* heap_insert - insert a value into a Max Binary Heap
* @root: double pointer to the root node of the Heap
* @value: value store in the node to be inserted
* Return: binary tree
*/
heap_t *heap_insert(heap_t **root, int value)
{
if (*root == NULL)/*insert new node if the heap is empty*/
{
*root = binary_tree_node(*root, value);
}
else /*serach for a proper insert point*/
{
queue_t *q = get_a_queue(*root), *current_q = q, *last_q = q;
binary_tree_t *current_node;
while (current_q != NULL)
{
current_node = current_q->node;/*get one node out of queue*/
if (current_node->left == NULL)
{
current_node->left = binary_tree_node(current_node, value);
current_node = current_node->left;
}
else if (current_node->right == NULL)
{
current_node->right = binary_tree_node(current_node, value);
current_node = current_node->right;
}
else
{
queue_put(current_node, &last_q);
current_q = current_q->next;/*increment the current pointer*/
continue;
}
/*put the node to proper point*/
swap(current_node);
break;
}
free_queue(&q);/*free queue node*/
}
return (*root);
}
