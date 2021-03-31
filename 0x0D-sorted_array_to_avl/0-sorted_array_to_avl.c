#include <stdlib.h>
#include <stdio.h>
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

/**
 * insert - recursive insert nodes
 * @root: pointer to the parent node of the node to create
 * @array: a pointer to the first
 * ******* element of the array to be converted
 * @left: index to the array left extreem
 * @right: index to the array right extreem
 * Return: avl tree
 */

avl_t *insert(avl_t *root, int *array, int left, int right)
{
    avl_t *tmp;
    int i = (right+left)/2;
    tmp = binary_tree_node((root), array[i]);
    if (left>right)
        return NULL;
    tmp->left = insert(tmp, array, left, i-1);
    tmp->right = insert(tmp, array, i+1, right);
    
    return tmp;
}
/**
 * print_array - Prints an array of integers
 *
 * @array: a pointer to the first
 * ******* element of the array to be converted
 * @size: the number of element in the array
 * Return: a pointer to the root node of the
 * ******* created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
    avl_t *root;
    size_t left = 0, right = size-1;
    root = malloc(sizeof(avl_t *));
    root = insert(root, array, left, right);
    if (!root)
        return NULL;
    return (root);
}
