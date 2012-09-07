/*
 * Generic_Linked_List.h
 * 
 * Octavio Benedi Sanchez https://github.com/OctavioBenedi
 * 
 */

#ifndef Generic_Linked_List
#define Generic_Linked_List

#define LIST_TYPE(type) \
	Generic_List_##type##_Node_t
	
#define LIST_DECLARE(type) \
	typedef struct Generic_##type##_node_s { \
		type data; \
		struct Generic_node_s *next; \
	} Generic_List_##type##_Node_t;

#define LIST_DEFINE(type) \
Generic_List_##type##_Node_t *list_##type##_create(type *data) \
{ \
	Generic_List_##type##_Node_t *node; \
	if(!(node=malloc(sizeof(Generic_List_##type##_Node_t)))) return NULL; \
	memcpy(&(node->data), data, sizeof(type)); \
	node->next=NULL; \
	return node; \
} \
Generic_List_##type##_Node_t *list_##type##_insert_after(Generic_List_##type##_Node_t *node, void *data) \
{ \
	Generic_List_##type##_Node_t *newnode; \
	newnode=list_##type##_create(data); \
    newnode->next = node->next; \
    node->next = newnode; \
	return newnode; \
} \
Generic_List_##type##_Node_t *list_##type##_insert_beginning(Generic_List_##type##_Node_t *list, void *data) \
{ \
	Generic_List_##type##_Node_t *newnode; \
        newnode=list_##type##_create(data); \
        newnode->next = list; \
	return newnode; \
} \
int list_##type##_remove(Generic_List_##type##_Node_t *list, Generic_List_##type##_Node_t *node) \
{ \
	while(list->next && list->next!=node) list=list->next; \
	if(list->next) { \
		list->next=node->next; \
		free(node); \
		return 0;		 \
	} else return -1; \
} \
int list_##type##_foreach(Generic_List_##type##_Node_t *node, int(*func)(void*)) \
{ \
	while(node) { \
		if(func(&node->data)!=0) return -1; \
		node=node->next; \
	} \
	return 0; \
} \
void list_##type##_free(Generic_List_##type##_Node_t *list) \
{ \
	Generic_List_##type##_Node_t *node = list; \
	Generic_List_##type##_Node_t *next_node; \
	while(node)  \
	{ \
		next_node=node->next; \
		free(node); \
		node=next_node; \
	}  \
	list = NULL;\
} \
Generic_List_##type##_Node_t *list_##type##_find(Generic_List_##type##_Node_t *node, int(*func)(void*,void*), void *data) \
{ \
	while(node) { \
		if(func(&node->data, data)>0) return node; \
		node=node->next; \
	} \
	return NULL; \
}


#define LIST_CREATE(type, data) \
	list_##type##_create(data)

#define LIST_INSERT_AFTER(type, node, data) \
	list_##type##_insert_after(node, data)

#define LIST_INSERT_AT_BEGIN(type, node, data) \
	list_##type##_insert_beginning(node, data)
	
#define LIST_REMOVE(type) \
	list_##type##_remove(node, node)

#define LIST_NODE_GET_DATA(list) \
	(list)->data
	
#define LIST_FOREACH(type, list, func) \
	list_##type##_foreach(list, func)

#define LIST_FIND(type, node, func, data) \
	list_##type##_find(node, func, data)
	
#define LIST_FREE(type, list) \
	list_##type##_free(list); \
	list = NULL;




#endif



