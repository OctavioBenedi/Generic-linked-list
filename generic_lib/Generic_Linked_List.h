/*
 * Generic_Linked_List.h
 * 
 * Octavio Benedi Sanchez https://github.com/OctavioBenedi
 * 
 */

#ifndef Generic_Linked_List
#define Generic_Linked_List

typedef struct Generic_node_s {
	void  *data;
	struct Generic_node_s *next;	
} Generic_List_Node_t;

Generic_List_Node_t *list_create(void *data, int data_size);
Generic_List_Node_t *list_insert_after(Generic_List_Node_t *node, void *data, int data_size);
Generic_List_Node_t *list_insert_beginning(Generic_List_Node_t *list, void *data, int data_size);
int list_remove(Generic_List_Node_t *list, Generic_List_Node_t *node);
int list_foreach(Generic_List_Node_t *node, int(*func)(void*));
int list_free(Generic_List_Node_t **list);
Generic_List_Node_t *list_find(Generic_List_Node_t *node, int(*func)(void*,void*), void *data);


#endif




