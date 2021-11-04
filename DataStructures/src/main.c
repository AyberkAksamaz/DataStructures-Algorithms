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

int main() {
	LINKED_STACK stack = linked_stack_init();
	linked_stack_push(stack, 12);
	linked_stack_push(stack, 32);
	linked_stack_push(stack, 42);
	linked_stack_push(stack, 52);
	int x = linked_stack_pop(stack);
}
