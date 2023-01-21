#include <stdio.h>
#include <stdlib.h>
 
struct queue
{
    int *items;
    int maxsize;
    int front;
    int rear;
    int size;
};
 
// create a queue
struct queue* newQueue(int size)
{
    struct queue *pt = NULL;
    pt = (struct queue*) malloc(sizeof(struct queue));
 
    pt->items = (int*)malloc(size * sizeof(int));
    pt->maxsize = size;
    pt->front = 0;
    pt->rear = -1;
    pt->size = 0;
 
    return pt;
}
 
int size(struct queue *pt) {
    return pt->size;
}
 
//empty queue
int isEmpty(struct queue *pt) {
    return !size(pt);
}
 
//get head of the queue
int front(struct queue *pt)
{
    if (isEmpty(pt))
    {
        printf("Lista Vazia\n");
        exit(EXIT_FAILURE);
    }
 
    return pt->items[pt->front];
}
 
//add element to the queue
void enqueue(struct queue *pt, int x)
{
    if (size(pt) == pt->maxsize)
    {
        printf("Lista cheia\n");
        return;
    }
  
    pt->rear = (pt->rear + 1) % pt->maxsize;
    pt->items[pt->rear] = x;
    pt->size++;

}
 
//dequeue and return element
int dequeue(struct queue *pt)
{
    if (isEmpty(pt)) 
    {
        printf("Lista Vazia\n");
        exit(EXIT_FAILURE);
    }
  
    int value = pt->items[pt->front];
    pt->front = (pt->front + 1) % pt->maxsize;
    pt->size--;
    return value;
 
}
 
int main()
{
    struct queue *pt = newQueue(5);
    
    enqueue(pt, 1);
    enqueue(pt, 2);
    enqueue(pt, 3);
    enqueue(pt, 4);

    int i;
    i = dequeue(pt);
    printf("removido %d\n",i);
    i = dequeue(pt);
    printf("removido %d\n",i);
    i = dequeue(pt);
    printf("removido %d\n",i);
    i = dequeue(pt);
    printf("removido %d\n",i);
 
    enqueue(pt, 5);
    enqueue(pt, 6);
 
    printf("size = %d\n", size(pt));
 
    if (isEmpty(pt)) {
        printf("The queue is empty\n");
    }
    else {
        printf("The queue is not empty\n");
    }
 
    return 0;
}