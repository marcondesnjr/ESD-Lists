#include "List.h"
#ifndef QUEUE_H
#define QUEUE_H

struct Queue {
    struct List* list;
};

struct Queue* createQueue();

void pushQueue(struct Queue* queue, int data);

struct node* popQueue(struct Queue* queue);
#endif