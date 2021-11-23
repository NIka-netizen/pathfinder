#include "../inc/libmx.h"

t_list *mx_create_node(void *data) {
	t_list *temp;
	temp = (t_list*)malloc(sizeof(struct s_list));
	temp->data = data;
	temp->next = NULL;
	return temp;
}
