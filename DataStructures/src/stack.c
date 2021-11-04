#include <stdlib.h>
#include <stdio.h>
#include "stack.h"
LINKED_STACK linked_stack_init() {
	LINKED_STACK stack = (LINKED_STACK)malloc(sizeof(LINKED_STACK_NODE_t));
	if(stack != NULL) {
		stack->head = NULL;
		printf("Success : Create Stack\n");
	} else {
		printf("Error : Create Stack\n");
	}
	return stack;
}

void linked_stack_free(LINKED_STACK stack) {
	free(stack);
}

void linked_stack_push(LINKED_STACK stack, void *data) {
	LINKED_STACK_NODE node = (LINKED_STACK_NODE)malloc(sizeof(LINKED_STACK_NODE_t));
	if(node != NULL) {
		node->data = data;
		node->next = stack->head;
		stack->head = node;
	} else {
		printf("Error: Push Stack\n");
	}
}


void *linked_stack_pop(LINKED_STACK stack) {
	LINKED_STACK_NODE node;
	void *res = NULL;

	if(stack->head != NULL) {
		node = stack->head;
		res = node->data;
		stack->head = node->next;
		free(node);
	} else {
		printf("Error : Stack Pop\n");
	}
	return res;
}


int linked_stack_is_emtpy(LINKED_STACK stack){
	int retval = 0;
	if(stack->head == NULL) {retval = 1;}
	return retval;
}



























