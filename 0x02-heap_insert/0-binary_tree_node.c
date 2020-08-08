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
binary_tree_t *temp = (binary_tree_t *)malloc(sizeof(binary_tree_t)); 
temp->n = value; 
temp->left = temp->right = NULL; 
temp->parent = parent; 
return temp; 
}

