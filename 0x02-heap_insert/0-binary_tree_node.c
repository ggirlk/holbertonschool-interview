#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_node - creates a binary tree node
 * @parent: pointer to the parent node of the node to create
 * @value: the value to put in the new node
 * Return: binary tree
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
binary_tree_t *tmp = (binary_tree_t *)malloc(sizeof(binary_tree_t));
if (tmp == NULL)
	return (NULL);

tmp->n = value;
tmp->left = tmp->right = NULL;
tmp->parent = parent;
return (tmp);
}

