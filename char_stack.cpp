/* File: char_stack.cpp

  Implementation of functions for basic simple array-based implementation of a stack.

*/

#include "char_stack.h"// contains the declarations of the variables and functions.


char_stack::char_stack(){
	top_of_stack = -1;	
}

void char_stack::push(char item){
	top_of_stack = top_of_stack +1;
	stack_array[top_of_stack] = item;
}

char char_stack::pop(){
	top_of_stack = top_of_stack -1;
	return stack_array[top_of_stack +1];
}

char char_stack::top(){
	return stack_array[top_of_stack];
}

bool char_stack::empty(){
	return top_of_stack == -1;
}

int char_stack::size(){
	return top_of_stack;
}
