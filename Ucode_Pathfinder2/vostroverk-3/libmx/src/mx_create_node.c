#include "../inc/libmx.h"

t_list *mx_create_node(void *data){
    t_list *newNode = malloc(16);
    newNode -> next = NULL;
    newNode -> data = data;
    return newNode;
}

