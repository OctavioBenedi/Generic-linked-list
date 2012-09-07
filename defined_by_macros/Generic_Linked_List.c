/*
 * Generic_Linked_List.c
 *  * 
 * Octavio Benedi Sanchez https://github.com/OctavioBenedi
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Generic_Linked_List.h"

LIST_DECLARE(int)

LIST_DEFINE(int)

LIST_DECLARE(float)

LIST_DEFINE(float)

int print_int_node(int *data)
{
	fprintf(stderr, "int value: %d\n", *data);
	return 0;
}

int print_float_node(float *data)
{
	fprintf(stderr, "float value: %2.2f\n", *data);
	return 0;
}


int main()
{
	{
		// Int example
		int i=0;
		LIST_TYPE(int) *list;
		LIST_TYPE(int) *head;  	
	
		list = LIST_CREATE(int, &i);
		head = list;
	
		for(i=1; i<11; i++)
		{
			head = LIST_INSERT_AFTER(int, head, &i);
		}
	
		LIST_FOREACH(int, list, print_int_node);
	
		LIST_FREE(int, list);
	
		if(list == NULL)
		{
			fprintf(stderr,"list is empty \n");
		}
	
		LIST_FOREACH(int, list, print_int_node);
	}
	
	
	{
		// Float example
		float a = 0;
		LIST_TYPE(float) *list2;
		LIST_TYPE(float) *head2;  
	
		list2 = LIST_CREATE(float, &a);
		head2 = list2;
	
		for(a=1; a<11; a++)
		{
			head2 = LIST_INSERT_AFTER(float, head2, &a);
		}
		
		list2 = LIST_INSERT_AT_BEGIN(float, list2, &a);
	
		LIST_FOREACH(float, list2, print_float_node);
		
		print_float_node(&LIST_NODE_GET_DATA(head2));
	
		LIST_FREE(float, list2);
	
		if(list2 == NULL)
		{
			fprintf(stderr,"list is empty \n");
		}
	
		LIST_FOREACH(float, list2, print_float_node);
	}
	
	return 0;
}

