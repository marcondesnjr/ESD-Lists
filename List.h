#include "Node.h"
#ifndef LIST_H
#define LIST_H
struct List{
	struct node* head;
};

struct List* createList();

void printList(struct List* list);

void insertFirst(struct List* list,int data);

void insertLast(struct List* list,int data);

struct node* deleteFirst(struct List* list); 

bool isEmpty(struct List* list);

struct node* deleteNode(struct List* list, int key);

struct node* findNode(struct List* list, int key); 

int length(struct List* list);

int deleteValue(struct List* list, int key);

int findValue(struct List* list, int key); 

void swap(struct node* a, struct node* b);

void bubbleSort(struct List* list);

struct node* binarySearch(struct List* list, int value);
#endif
