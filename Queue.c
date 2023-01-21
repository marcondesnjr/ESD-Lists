#include <stdbool.h>
#include <stdlib.h>
#include "Queue.h"

struct Queue* createQueue(){
    struct List* list= createList();
    struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));
    queue->list = list;
    return queue;
}

void pushQueue(struct Queue* queue, int data){
    insertLast(queue->list, data);
}

struct node* popQueue(struct Queue* queue){
    return deleteFirst(queue->list);
}