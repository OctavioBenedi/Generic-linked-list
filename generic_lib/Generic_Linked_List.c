/*
 * Generic_Linked_List.c
 *
 * Octavio Benedi Sanchez https://github.com/OctavioBenedi
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Generic_Linked_List.h"

Generic_List_Node_t *list_create(void *data, int data_size)
{
    void *tmp;
    Generic_List_Node_t *node;
    if (!(node=malloc(sizeof(Generic_List_Node_t))))
    {
        return NULL;
    }
    if (!(tmp=malloc(data_size)))
    {
        return NULL;
    }
    memcpy(tmp, data, data_size);
    node->data = tmp;
    node->next=NULL;
    return node;
}

Generic_List_Node_t *list_insert_after(Generic_List_Node_t *node, void *data, int data_size)
{
    Generic_List_Node_t *newnode;
    newnode=list_create(data, data_size);
    newnode->next = node->next;
    if (node)
        node->next = newnode;
    return newnode;
}

Generic_List_Node_t *list_insert_beginning(Generic_List_Node_t *list, void *data, int data_size)
{
    Generic_List_Node_t *newnode;
    newnode=list_create(data, data_size);
    newnode->next = list;
    return newnode;
}

int list_remove(Generic_List_Node_t *list, Generic_List_Node_t *node)
{
    while (list->next && list->next!=node)
    {
        list=list->next;
    }
    if (list->next)
    {
        list->next=node->next;
        free(node->data);
        free(node);
        return 0;
    } else return -1;
}

int list_foreach(Generic_List_Node_t *node, int(*func)(void*))
{
    while (node)
    {
        if (func(node->data)!=0) return -1;
        node=node->next;
    }
    return 0;
}

int list_free(Generic_List_Node_t **list)
{
    Generic_List_Node_t *node = *list;
    Generic_List_Node_t *next_node;
    while (node)
    {
        next_node=node->next;
        if(node->data != NULL)
			free(node->data);
        free(node);
        node=next_node;
    }
    *list = NULL;
    return 0;
}

Generic_List_Node_t *get_head(Generic_List_Node_t *list)
{
	Generic_List_Node_t *node = list;
    Generic_List_Node_t *head = NULL;
    
    while (node)
    {
		head = node;
		node = node->next;
	}	
	
	return head;
}

Generic_List_Node_t *list_find(Generic_List_Node_t *node, int(*func)(void*,void*), void *data)
{
    while (node)
    {
        if (func(&node->data, data)>0) return node;
        node=node->next;
    }
    return NULL;
}


