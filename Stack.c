#include <stdbool.h>
#include <stdlib.h>
#include "Stack.h"

struct Stack* createStack(){
    struct List* list = createList();
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->list = list;
    return stack;
}

void pushStack(struct Stack* stack, int data){
    insertFirst(stack->list, data);
}

struct node* popStack(struct Stack* stack){
    return deleteFirst(stack->list);
}