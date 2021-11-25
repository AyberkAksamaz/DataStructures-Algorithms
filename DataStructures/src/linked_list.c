#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"

LINKED_LIST linked_list_init() {
	LINKED_LIST list = (LINKED_LIST)malloc(sizeof(LINKED_LIST_t));

	if(list != NULL) {
		list->head = NULL;
	} else { printf("Error linked_list_init!!\n"); }

	return list;
}


void linked_list_free(LINKED_LIST list) {
	free(list);
}


void linked_list_prepend(LINKED_LIST list, void *data) {
	LINKED_LIST_NODE node = (LINKED_LIST_NODE)malloc(sizeof(LINKED_LIST_NODE_t));

	node->data =data;
	node->next = list->head;
	list->head = node;
}


void linked_list_append(LINKED_LIST list, void *data) {
	LINKED_LIST_NODE node = (LINKED_LIST_NODE)malloc(sizeof(LINKED_LIST_NODE_t));
	LINKED_LIST_NODE temp;
	node->data = data;
	node->next = NULL;

	if(list->head == NULL) {
		list->head = node;
	} else {
		temp = list->head;
		while(temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = node;
	}
}


void linked_list_insert(LINKED_LIST list, void *data, int idx) {
	LINKED_LIST_NODE node = (LINKED_LIST_NODE)malloc(sizeof(LINKED_LIST_NODE_t));
	LINKED_LIST_NODE temp;
	node->data = data;
	temp = list->head;

	if(idx == 0) {
		node->next = list->head;
		list->head = node;
	} else {
		for(int i=0; i<idx; i++) {
			if(i == idx-1) {
				node->next = temp->next;
				temp->next = node;
			} else {
				temp = temp->next;
			}
		}
	}
}


void *linked_list_remove(LINKED_LIST list, int idx){
	LINKED_LIST_NODE node = (LINKED_LIST_NODE)malloc(sizeof(LINKED_LIST_NODE_t));
	LINKED_LIST_NODE tmp;
	void *data;
	int i = 0;

	if(idx == 0) {
		data = list->head->data;
		node = list->head;
		list->head = node->next;
		free(node);
	} else {
		tmp = list->head;
		while(tmp != NULL && i<idx-1) {
			tmp = tmp->next;
			i++;
		}
		data = tmp->next->data;
		node = tmp->next->next;
		free(tmp->next);
		tmp->next = node;
	}
	return data;
}

void linked_list_set(LINKED_LIST list,void *data, int idx)
{
	LINKED_LIST_NODE tmp; // (LINKED_LIST_NODE)malloc(sizeof(LINKED_LIST_NODE_t));


	int i=0;

	if(idx == 0)
	{
		list->head->data = data;
	}
	else
	{

		tmp = list->head;
		while(tmp != NULL && i<idx-1)
		{
			tmp = tmp->next;
			i++;
		}

		tmp->next->data = data;

	}

}

void *linked_list_get(LINKED_LIST list, int idx)
{
	LINKED_LIST_NODE node = (LINKED_LIST_NODE)malloc(sizeof(LINKED_LIST_NODE_t));
	void *data;
	int i=0;
	if(idx == 0)
	{
		data = list->head->data;
	}
	else
	{
		node = list->head;
		while(node != NULL && i<idx-1)
		{
			node = node->next;
			i++;
		}

		data = node->next->data;

	}
	return (int *)data;
}

void linked_list_removeall(LINKED_LIST list)
{
	LINKED_LIST_NODE node = (LINKED_LIST_NODE)malloc(sizeof(LINKED_LIST_NODE_t));

	int i=0;
	while(list->head != NULL)
	{
		node = list->head;
		list->head = list->head->next;
		free(node);
		i++;
	}
	printf("Lınked list remove all\n");
}

void linked_list_concatenate(LINKED_LIST list, LINKED_LIST list2)
{
	LINKED_LIST_NODE node = (LINKED_LIST_NODE)malloc(sizeof(LINKED_LIST_NODE_t));

	node = list->head;
	while(node->next != NULL)
	{
		node = node->next;
	}
	node->next = list2->head;
	list2->head = list->head;
}

int linked_list_size(LINKED_LIST list)
{
	LINKED_LIST_NODE node;
	int size=1;
	node = list->head;
	if(list->head != NULL)
	{
		while(node->next !=NULL)
		{
			node = node->next;
			size++;
		}
	}
	return size;
}

void integer_printer(void *data)
{
	printf("%d ", (int *)data);
}
void char_printer(void *data)
{
	printf("%c ", (char *)data);
}

void linked_list_fprint(LINKED_LIST list, void (*print_type)(void *))
{
	LINKED_LIST_NODE node;
	int size=0;

	node = list->head;
	size = linked_list_size(list);
	printf("Linked List : ");
	for(int i=0; i<size; i++)
	{
		print_type(node->data);
		node = node->next;
	}
	printf("\n");


}


























