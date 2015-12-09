#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <unistd.h>

//This programme is for making stack with three main functions:
//push (for adding top element), pop (for deleting top element) and top (to find the top element).
//First time space in memory is for 5 element but after it increases twice if it is needful.

#define MAXSIZE 5

typedef struct stack {
	int* data;
	int size;
	int capacity;
} stack; 

stack* create_stack(int maxsize)
{
	stack *S;
	S = malloc(sizeof(stack));
	S->data = (int*) malloc((sizeof(int)) * maxsize);
	S->size = 0;
	S->capacity = maxsize;
	return S;
}

void push(stack *S, int info)
{
	if (S->size == S->capacity) {
		S->capacity *= 2;
		S->data = realloc(S->data,sizeof(int) * S->capacity );
		S->data[S->size++] = info;
	} else {
		S->data[S->size++] = info;
	}
}

void pop(stack *S) 
{
	if (S->size == 0) {
		printf("Error! The stack is empty! Removing is impossible!\n");
	} else {
		S->size--;
	}
}

void top(stack *S) 
{
	if (S->size == 0) {
		printf("Stack is empty!\n");
	} else {
		printf("Top - %d\n", S->data[S->size - 1]);
	}
}

int main(int argc, char const *argv[])
{
	stack *S;
	S = create_stack(MAXSIZE);
	pop(S);
	push(S, 1);	
	push(S, 2);	
	push(S, 3);
	push(S, 4);
	push(S, 5);
	push(S, 6);
	push(S, 7);	
	push(S, 8);
	push(S, 9);
	pop()
	top(S);
	return 0;
}