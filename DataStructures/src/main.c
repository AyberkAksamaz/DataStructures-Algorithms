/*
 ============================================================================
 Name        : Ds2_lec6.c
 Author      : Ayberk Aksamaz
 Version     :
 Copyright   : Your copyright notice
 Description : Data Structures
 ============================================================================
*/



#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "queue.h"

int main() {
	/*
	LINKED_STACK stack = linked_stack_init();
	linked_stack_push(stack, 12);
	linked_stack_push(stack, 32);
	linked_stack_push(stack, 42);
	linked_stack_push(stack, 52);
	int x = linked_stack_pop(stack);
	*/

	LINKED_QUEUE queue = linked_queue_init();
	linked_queue_enqueue(queue, (void *)15);
	linked_queue_enqueue(queue, 25);
	linked_queue_enqueue(queue, 35);
	linked_queue_enqueue(queue, 45);
	linked_queue_enqueue(queue, 55);
	print_queue(queue);
	printf("size: %d",linked_queue_size(queue));
//	linked_queue_dequeue(queue);
//	linked_queue_dequeue(queue);
//	printf("\n");
//	print_queue(queue);
}











