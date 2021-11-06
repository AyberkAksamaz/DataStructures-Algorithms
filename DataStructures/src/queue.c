#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

LINKED_QUEUE linked_queue_init() {
	LINKED_QUEUE queue = (LINKED_QUEUE)malloc(sizeof(LINKED_QUEUE_t));

	if(queue != NULL) {
		queue->head = NULL;
		queue->tail = NULL;
	} else {
		printf("ERROR linked_queue_init\n");
	}
	return queue;
}


void linked_queue_free(LINKED_QUEUE queue){
	free(queue);
}


int linked_queue_is_empty(LINKED_QUEUE queue){
	int retval = 0;
	if(queue->head == NULL) {
		retval = 1;
	}
	return retval;
}


int linked_queue_size(LINKED_QUEUE queue){
	int retval = 0;
	LINKED_QUEUE_NODE node;
	node = queue->head;
	if(!linked_queue_is_empty(queue)) {
		retval++;
		while(node->next != NULL) {
			retval++;
			node = node->next;
		}
	} else retval = 0;

	return retval;
}


void linked_queue_enqueue(LINKED_QUEUE queue, void *data){
	LINKED_QUEUE_NODE node = (LINKED_QUEUE_NODE)malloc(sizeof(LINKED_QUEUE_NODE_t));
	if(node != NULL) {
		node->data = data;
		node->next = NULL;
		if(queue->head == NULL) {
			queue->head = node;
		} else { queue->tail->next = node; }

		queue->tail = node;
	}
}


void *linked_queue_dequeue(LINKED_QUEUE queue){
	void *retval = NULL;
	LINKED_QUEUE_NODE node = (LINKED_QUEUE_NODE)malloc(sizeof(LINKED_QUEUE_NODE_t));

	node = queue->head;
	if(node != NULL) {
		if(node == queue->tail) {
			queue->head = NULL;
			queue->tail = NULL;
		} else { queue->head = node->next; }

		retval = node->data;
		free(node);
	} else { printf("Queue is Empty!!"); }

	return retval;
}


void print_queue(LINKED_QUEUE queue){
	LINKED_QUEUE_NODE node = (LINKED_QUEUE_NODE)malloc(sizeof(LINKED_QUEUE_NODE_t));

	node = queue->head;
	if(!linked_queue_is_empty(queue)) {
		while(node->next != NULL) {
			printf("%p <- ", node->data);
			node = node->next;
		}
		printf("%p\n", node->data);
	} else { printf("Queue is Empty!!"); }

	free(node);
}

















