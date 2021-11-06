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



























