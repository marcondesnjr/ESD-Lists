#include "List.h"
#ifndef STACK_H
#define STACK_H
struct Stack{
    struct List* list;
};

struct Stack* createStack();

void pushStack(struct Stack* stack, int data);

struct node* popStack(struct Stack* stack);
#endif