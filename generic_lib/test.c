/*
 * test.c
 *
 * Octavio Benedi Sanchez https://github.com/OctavioBenedi
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Generic_Linked_List.h"

typedef struct
{
    int a;
    float b;
    int c;
} my_type_t;


int print_int_node(int *data)
{
    fprintf(stderr, "int value: %d\n", *data);
    return 0;
}

int print_my_type_t_node(my_type_t *data)
{
    fprintf(stderr, "a:%d, b:%2.2f, c:%d\n", data->a, data->b, data->c);
    return 0;
}


int main()
{
    // Thist test does not check all the error conditions that may happen
    {
        // Int example
        int i = 0;
        Generic_List_Node_t *list;
        Generic_List_Node_t *head;

        list = list_create(&i, sizeof(i));
        head = list;

        if (list == NULL)
        {
            fprintf(stderr,"Error creating new element\n");
            exit (-1);
        }

        for (i; i<11; i++)
        {
            head = list_insert_after(head, &i, sizeof(i));
        }

        list_foreach(list, print_int_node);

        list_free(&list);

        if (list == NULL)
        {
            fprintf(stderr,"list is empty \n");
        }

        list_foreach(list, print_int_node);
    }

    {
        // my_type_t example
        int i=0;
        my_type_t itm;
        Generic_List_Node_t *list;
        Generic_List_Node_t *head;

        itm.a = 1;
        itm.b = 2.2;
        itm.c = 3;
        list = list_create(&itm, sizeof(itm));
        head = list;

        if (list == NULL)
        {
            fprintf(stderr,"Error creating new element\n");
            exit (-1);
        }

        for (i=1; i<11; i++)
        {
            itm.a++;
            itm.b++;
            itm.c++;
            head = list_insert_after(head, &itm, sizeof(itm));
        }

        list_foreach(list, print_my_type_t_node);

        list_free(&list);

        if (list == NULL)
        {
            fprintf(stderr,"list is empty \n");
        }

        list_foreach(list, print_my_type_t_node);
    }


    return 0;
}


